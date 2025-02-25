/*++

Copyright (C) 2020 Autodesk Inc.

All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
	* Redistributions of source code must retain the above copyright
	  notice, this list of conditions and the following disclaimer.
	* Redistributions in binary form must reproduce the above copyright
	  notice, this list of conditions and the following disclaimer in the
	  documentation and/or other materials provided with the distribution.
	* Neither the name of the Autodesk Inc. nor the
	  names of its contributors may be used to endorse or promote products
	  derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL AUTODESK INC. BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/


#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <exception>
#include <iomanip>
#include <thread>
#include <cctype>

#include "crossguid/guid.hpp"
#include "PicoSHA2/picosha2.h"

#include "cppcodec/base64_rfc4648.hpp"
#include "cppcodec/base64_url.hpp"

#ifdef _WIN32
#include <objbase.h>
#include <shlwapi.h>
#include <iomanip>
#else
#include <sys/stat.h>
#include <ctime>
#include <unistd.h>
#include <dirent.h> 
#endif



#include "common_utils.hpp"

namespace AMCCommon {

#define LIBMC_MAXSTRINGBUFFERSIZE (1024 * 1024 * 1024)
#define LIBMC_MAXRANDOMSTRINGITERATIONS 1024

	// Lookup table to convert UTF8 bytes to sequence length
	const unsigned char UTF8DecodeTable[256] = {
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
		2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
		3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
		4,4,4,4,4,4,4,4,5,5,5,5,6,6,0,0
	};

	// Masks to decode highest UTF8 sequence byte
	const unsigned char UTF8DecodeMask[7] = { 0, 0x7f, 0x1f, 0x0f, 0x07, 0x03, 0x01 };




	bool fnUTF16CharIsSurrogate(wchar_t cChar)
	{
		uint32_t nSignature = (cChar & 0xfc00);
		return (nSignature == 0xd800) || (nSignature == 0xdc00);
	}

	bool fnUTF16CharIsHighSurrogate(wchar_t cChar)
	{
		uint32_t nSignature = (cChar & 0xfc00);
		return (nSignature == 0xd800);
	}

	bool fnUTF16CharIsLowSurrogate(wchar_t cChar)
	{
		uint32_t nSignature = (cChar & 0xfc00);
		return (nSignature == 0xdc00);
	}

	uint32_t fnUTF16toCharacterID(uint16_t nHighSurrogate, uint16_t nLowSurrogate)
	{
		if ((fnUTF16CharIsHighSurrogate(nLowSurrogate)) && (fnUTF16CharIsLowSurrogate(nHighSurrogate))) {
			std::swap(nLowSurrogate, nHighSurrogate); // UTF16LE
		}

		if ((!fnUTF16CharIsHighSurrogate(nHighSurrogate)) || (!fnUTF16CharIsLowSurrogate(nLowSurrogate)))
			throw std::runtime_error ("could not convert to utf8");

		uint32_t nCode = (((uint32_t)(nHighSurrogate & 0x3ff)) << 10 | ((uint32_t)(nLowSurrogate & 0x3ff)));
		return nCode + 0x10000;
	}


	std::string CUtils::UTF16toUTF8(const std::wstring sString)
	{

		// Check Input Sanity
		size_t nLength = sString.length();
		if (nLength == 0)
			return "";
		if (nLength > LIBMC_MAXSTRINGBUFFERSIZE)
			throw std::runtime_error("invalid buffer size");

		// Reserve UTF8 Buffer
		uint32_t nBufferSize = (uint32_t)nLength * 4 + 1;
		std::vector<char> Buffer;
		Buffer.resize(nBufferSize);

		// nfInt32 nResult;
		// Alternative: Convert via Win API
		// nResult = WideCharToMultiByte(CP_UTF8, 0, sString.c_str(), (nfUint32)nLength, &Buffer[0], nBufferSize, nullptr, nullptr);
		// if (nResult == 0)
		//	throw CNMRException(NMR_ERROR_COULDNOTCONVERTTOUTF8);

		const wchar_t* pChar = sString.c_str();
		char* pOutput = &Buffer[0];

		while (*pChar) {
			wchar_t cChar = *pChar;
			uint32_t nCharacter;
			pChar++;

			if (fnUTF16CharIsSurrogate(cChar)) {
				wchar_t cLowChar = *pChar;
				if (cLowChar == 0)
					throw std::runtime_error("could not convert to utf8");
				pChar++;

				nCharacter = fnUTF16toCharacterID(cChar, cLowChar);
			}
			else {
				nCharacter = cChar;
			}

			if (nCharacter < 0x80) {
				// One Byte Encoding
				*pOutput = nCharacter;
				pOutput++;
			}
			else if (nCharacter < 0x800) {
				// Two Byte Encoding
				*pOutput = (nCharacter >> 6) | 0xC0;
				pOutput++;
				*pOutput = (nCharacter & 0x3f) | 0x80;
				pOutput++;
			}
			else if (nCharacter < 0x10000) {
				// Three Byte Encoding
				*pOutput = (nCharacter >> 12) | 0xE0;
				pOutput++;
				*pOutput = ((nCharacter >> 6) & 0x3f) | 0x80;
				pOutput++;
				*pOutput = (nCharacter & 0x3f) | 0x80;
				pOutput++;
			}
			else if (nCharacter < 0x200000) {
				// Four Byte Encoding
				*pOutput = (nCharacter >> 18) | 0xF0;
				pOutput++;
				*pOutput = ((nCharacter >> 12) & 0x3f) | 0x80;
				pOutput++;
				*pOutput = ((nCharacter >> 6) & 0x3f) | 0x80;
				pOutput++;
				*pOutput = (nCharacter & 0x3f) | 0x80;
				pOutput++;
			}
			else if (nCharacter < 0x4000000) {
				// Five Byte Encoding
				*pOutput = (nCharacter >> 24) | 0xF8;
				pOutput++;
				*pOutput = ((nCharacter >> 18) & 0x3f) | 0x80;
				pOutput++;
				*pOutput = ((nCharacter >> 12) & 0x3f) | 0x80;
				pOutput++;
				*pOutput = ((nCharacter >> 6) & 0x3f) | 0x80;
				pOutput++;
				*pOutput = (nCharacter & 0x3f) | 0x80;
				pOutput++;
			}
			else {
				// Six Byte Encoding
				*pOutput = (nCharacter >> 30) | 0xFC;
				pOutput++;
				*pOutput = ((nCharacter >> 24) & 0x3f) | 0x80;
				pOutput++;
				*pOutput = ((nCharacter >> 18) & 0x3f) | 0x80;
				pOutput++;
				*pOutput = ((nCharacter >> 12) & 0x3f) | 0x80;
				pOutput++;
				*pOutput = ((nCharacter >> 6) & 0x3f) | 0x80;
				pOutput++;
				*pOutput = (nCharacter & 0x3f) | 0x80;
				pOutput++;
			}

		}

		// write end byte
		*pOutput = 0;

		return std::string(&Buffer[0]);

	}

	void CUtils::characterIDToUTF16(uint32_t nCharacterID, uint16_t& nHighSurrogate, uint16_t& nLowSurrogate)
	{
		if ((nCharacterID < 0x10000) || (nCharacterID > 0x10FFFF))
			throw std::runtime_error("could not convert to utf16");
		nCharacterID -= 0x10000;
		nHighSurrogate = (nCharacterID >> 10) | 0xd800;
		nLowSurrogate = (nCharacterID & 0x3ff) | 0xdc00;
	}

	bool CUtils::UTF8StringIsValid(const std::string& sString)
	{
		const char* pChar = sString.c_str();

		while (*pChar) {
			unsigned char cChar = (unsigned char)*pChar;
			uint32_t nLength = UTF8DecodeTable[(uint32_t)cChar];
			pChar++;

			if (nLength == 0)
				return false;
			if (nLength > 6)
				return false;

			// Check for BOM (0xEF,0xBB,0xBF), this also checks for #0 characters at the end,
			// so it does not read over the string end!
			bool bIsBOM = false;
			if (cChar == 0xef) {
				if (*((const unsigned char*)pChar) == 0xbb) {
					if (*((const unsigned char*)(pChar + 1)) == 0xbf) {
						bIsBOM = true;
					}
				}
			};


			if (!bIsBOM) {
				uint32_t nCode = cChar & UTF8DecodeMask[nLength];

				while (nLength > 1) {
					cChar = *pChar;
					if ((cChar & 0xc0) != 0x80)
						return false;
					pChar++;

					// Map UTF8 sequence to code
					nCode = (nCode << 6) | (cChar & 0x3f);
					nLength--;
				}

				// Map Code to UTF16
				if ((nCode < 0xd800) || ((nCode >= 0xe000) && (nCode <= 0xffff))) {
					// everything is good in this case

				}
				else {
					if ((nCode < 0x10000) || (nCode > 0x10FFFF))
						return false;

					// everything is good in this case
				}
			}
			else {
				// If we find a UTF8 bom, we just ignore it.
				if (nLength != 3)
					return false;
				pChar += 2;
			}
		}


		// success
		return true;
	}

	
	std::string CUtils::trimString(const std::string& sString)
	{
		std::string s = sString;
		// left trim
		s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
			return !std::isspace(ch);
		}));

		// right trim
		s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
			return !std::isspace(ch);
		}).base(), s.end());

		return s;
	}

	std::string CUtils::toLowerString(const std::string& sString)
	{
		std::string s = sString;
		std::transform(s.begin(), s.end(), s.begin(),
			[](unsigned char c) { return std::tolower(c); } // correct
		);
		return s;
	}



	void CUtils::splitString(const std::string& sString, const std::string& sDelimiter, std::vector<std::string>& stringVector)
	{
		auto nDelimiterLength = sDelimiter.length();
		if (nDelimiterLength == 0)
			throw std::runtime_error("split string delimiter is empty");

		if (!sString.empty()) {
			
			size_t nOffset = 0;
			bool bFinished = false;
			while (!bFinished) {
				auto nPos = sString.find(sDelimiter, nOffset);
				if (nPos == std::string::npos) {
					stringVector.push_back(sString);
					bFinished = true;
				}
				else {
					stringVector.push_back(sString.substr (nOffset, nPos - nOffset));
					nOffset = nPos + nDelimiterLength;
				}

			}


		}

	}


    std::wstring CUtils::UTF8toUTF16(const std::string sString)
	{

		// Check Input Sanity
		size_t nLength = sString.length();
		if (nLength == 0)
			return L"";
		if (nLength > LIBMC_MAXSTRINGBUFFERSIZE)
			throw std::runtime_error("invalid buffer size");

		// Reserve UTF8 Buffer
		uint32_t nBufferSize = (uint32_t)nLength;
		std::vector<wchar_t> Buffer;
		Buffer.resize(nBufferSize * 2 + 2);

		const char * pChar = sString.c_str();
		wchar_t* pOutput = &Buffer[0];

		while (*pChar) {
			unsigned char cChar = (unsigned char)*pChar;
			uint32_t nLength = UTF8DecodeTable[(uint32_t)cChar];
			pChar++;

			if (nLength == 0)
				throw std::runtime_error("could not convert to utf16");
			if (nLength > 6)
				throw std::runtime_error("could not convert to utf16");

			// Check for BOM (0xEF,0xBB,0xBF), this also checks for #0 characters at the end,
			// so it does not read over the string end!
			bool bIsBOM = false;
			if (cChar == 0xef) {
				if (*((const unsigned char*)pChar) == 0xbb) {
					if (*((const unsigned char*)(pChar + 1)) == 0xbf) {
						bIsBOM = true;
					}
				}
			};


			if (!bIsBOM) {
				uint32_t nCode = cChar & UTF8DecodeMask[nLength];

				while (nLength > 1) {
					cChar = *pChar;
					if ((cChar & 0xc0) != 0x80)
						throw std::runtime_error("could not convert to utf16");
					pChar++;

					// Map UTF8 sequence to code
					nCode = (nCode << 6) | (cChar & 0x3f);
					nLength--;
				}

				// Map Code to UTF16
				if ((nCode < 0xd800) || ((nCode >= 0xe000) && (nCode <= 0xffff))) {
					*pOutput = nCode;
					pOutput++;
				}
				else {
					uint16_t nHighSurrogate, nLowSurrogate;
					characterIDToUTF16(nCode, nHighSurrogate, nLowSurrogate);
					*pOutput = nHighSurrogate;
					pOutput++;
					*pOutput = nLowSurrogate;
					pOutput++;
				}
			}
			else {
				// If we find a UTF8 bom, we just ignore it.
				if (nLength != 3)
					throw std::runtime_error("could not convert to utf16");
				pChar += 2;
			}
		}

		// write end byte
		*pOutput = 0;

		return std::wstring(&Buffer[0]);

	}


	bool UUIDInValid(char c)
	{
		return !(((c >= '0') && (c <= '9'))
			|| ((c >= 'a') && (c <= 'f'))
			// || (c == '-')
			);
	}

	std::string CUtils::normalizeUUIDString(std::string sRawString)
	{
		
		// to lowercase, remove all non hex characters, insert dashes again
		std::transform(sRawString.begin(), sRawString.end(), sRawString.begin(), ::tolower);
		sRawString.erase(std::remove_if(sRawString.begin(), sRawString.end(), &UUIDInValid), sRawString.end());
		if (sRawString.length() != 32) {
			throw std::runtime_error("invalid uuid string " + sRawString);
		}
		return sRawString.substr(0, 8) + '-' + sRawString.substr(8, 4) + '-' + sRawString.substr(12, 4) + '-' + sRawString.substr(16, 4) + '-' + sRawString.substr(20, 12);
	}


	std::string CUtils::normalizeSHA256String(std::string sRawString)
	{
		// to lowercase, remove all non hex characters, insert dashes again
		std::transform(sRawString.begin(), sRawString.end(), sRawString.begin(), ::tolower);
		sRawString.erase(std::remove_if(sRawString.begin(), sRawString.end(), &UUIDInValid), sRawString.end());
		if (sRawString.length() != 64) {
			throw std::runtime_error("invalid sha256 string " + sRawString);
		}

		return sRawString;
	}



	std::string CUtils::createUUID()
	{
		auto guid = xg::newGuid ();		
		return normalizeUUIDString (guid.str());
	}



	void CUtils::deleteFileFromDisk(const std::string& sFileName, bool bMustSucceed)
	{
#ifdef _WIN32
		std::wstring sFileNameUTF16 = UTF8toUTF16(sFileName);
		if (!DeleteFileW(sFileNameUTF16.c_str())) {
			if (bMustSucceed)
				throw std::runtime_error("could not delete file: " + sFileName);		
		}
#else
		if (std::remove(sFileName.c_str())) {
			if (bMustSucceed)
				throw std::runtime_error("could not delete file: " + sFileName);
		}
#endif
	}

	void CUtils::deleteDirectoryFromDisk(const std::string& sPath, bool bMustSucceed)
	{
#ifdef _WIN32
		std::wstring sPathUTF16 = UTF8toUTF16(sPath);
		if (!RemoveDirectoryW(sPathUTF16.c_str())) {
			if (bMustSucceed)
				throw std::runtime_error("could not delete path: " + sPath);
		}
#else
		if (std::remove(sPath.c_str())) {
			if (bMustSucceed)
				throw std::runtime_error("could not delete path: " + sPath);
		}
#endif
	}

	void CUtils::createDirectoryOnDisk(const std::string& sPath)
	{
#ifdef _WIN32
		std::wstring sPathUTF16 = UTF8toUTF16(sPath);
		if (!CreateDirectoryW(sPathUTF16.c_str(), nullptr)) {
			throw std::runtime_error("could not create path: " + sPath);
		}
#else
		if (mkdir(sPath.c_str(), 0700)) {
			throw std::runtime_error("could not create path: " + sPath);
		}
#endif
	}


	// Returns a UUID, such that sBasePath/sPrefixUUID.extension does not exist.
	// Tries out maximum nMaxIterations different random uuids.
	std::string CUtils::findTemporaryFileName(const std::string& sBasePath, const std::string& sPrefix, const std::string& sExtension, const uint32_t nMaxIterations)
	{
		if (sBasePath.empty())
			throw std::runtime_error("empty temporary file base path");

		std::string sBasePathWithDelimiter = sBasePath;
		std::string sExtensionWithPoint;

		if (!sExtension.empty()) {
			if (sExtension.at(0) != '.') {
				sExtensionWithPoint = "." + sExtension;
			}
			else {
				sExtensionWithPoint = sExtension;
			}

		}

		char lastChar = sBasePathWithDelimiter.at(sBasePathWithDelimiter.length() - 1);
		if ((lastChar != '/') && (lastChar != '\\'))
			sBasePathWithDelimiter += "/";

		for (uint32_t nIndex = 0; nIndex < nMaxIterations; nIndex++) {
			std::string sUUID = createUUID();
			std::string sFullPath = sBasePathWithDelimiter + sPrefix + sUUID + sExtensionWithPoint;

			if (!fileOrPathExistsOnDisk(sFullPath))
				return sFullPath;

		}

		throw std::runtime_error("could not create temporary file path");

	}


	bool CUtils::fileOrPathExistsOnDisk(const std::string& sPathName)
	{

#ifdef _WIN32
		std::wstring sFileNameUTF16 = UTF8toUTF16(sPathName);
		return PathFileExistsW(sFileNameUTF16.c_str ());
#else
		if (access(sPathName.c_str (), F_OK) != -1) {
			return true;
		}
		else {
			return false;
		}
#endif

	}



	std::string CUtils::calculateBlockwiseSHA256FromFile(const std::string& sFileNameUTF8, uint32_t nBlockSize)
	{
		if (nBlockSize == 0)
			throw std::runtime_error("invalid hash block size!");

#ifndef __GNUC__
		auto sWidePath = AMCCommon::CUtils::UTF8toUTF16(sFileNameUTF8);
		std::ifstream shaStream;
		shaStream.open(sWidePath, std::ios::binary);
#else
		std::ifstream shaStream;
		shaStream.open(sFileNameUTF8, std::ios::binary);
#endif			
		if (!shaStream.is_open())
			throw std::runtime_error("could not open file for hash calculation.");

		std::vector<uint8_t> BlockData;
		BlockData.resize(nBlockSize);

		std::stringstream sConcatenatedSHASums;

		shaStream.seekg(0, shaStream.end);
		size_t totalBytesToRead = shaStream.tellg();
		shaStream.seekg(0, shaStream.beg);

		while (totalBytesToRead > 0) {
			size_t bytesToRead;
			if (totalBytesToRead >= nBlockSize) {
				bytesToRead = nBlockSize;
				totalBytesToRead -= nBlockSize;
			}
			else {
				bytesToRead = totalBytesToRead;
				BlockData.resize(bytesToRead);
				totalBytesToRead = 0;
			}

			shaStream.read((char*)BlockData.data(), bytesToRead);
			if (!shaStream)
				throw std::runtime_error("could not read hash stream");


			std::vector<unsigned char> hash(picosha2::k_digest_size);
			picosha2::hash256(BlockData, hash.begin(), hash.end());
			std::string sBlockChecksum = picosha2::bytes_to_hex_string(hash.begin(), hash.end());
			sConcatenatedSHASums << sBlockChecksum;
		}

		return calculateSHA256FromString(sConcatenatedSHASums.str());

	}


	std::string CUtils::calculateSHA256FromFile(const std::string& sFileNameUTF8)
	{
		std::vector<unsigned char> hash(picosha2::k_digest_size);

#ifndef __GNUC__
		auto sWidePath = AMCCommon::CUtils::UTF8toUTF16(sFileNameUTF8);
		std::ifstream shaStream(sWidePath, std::ios::binary);
#else
		std::ifstream shaStream(sFileNameUTF8, std::ios::binary);
#endif			

		picosha2::hash256(shaStream, hash.begin(), hash.end());
		return picosha2::bytes_to_hex_string(hash.begin(), hash.end());
	}

	std::string CUtils::calculateSHA256FromString(const std::string& sString)
	{
		std::vector<unsigned char> hash(picosha2::k_digest_size);
		picosha2::hash256(sString.begin(), sString.end(), hash.begin(), hash.end());
		return picosha2::bytes_to_hex_string(hash.begin(), hash.end());
	}

	std::string CUtils::calculateSHA256FromData(const uint8_t* pData, uint64_t nDataSize)
	{
		if ((nDataSize == 0) || (pData == nullptr))
			throw std::runtime_error("could not calculate SHA256 from empty data");

		auto startIter = static_cast<const uint8_t*> (pData);
		auto endIter = startIter + nDataSize;

		std::vector<unsigned char> hash(picosha2::k_digest_size);
		picosha2::hash256(startIter, endIter, hash.begin(), hash.end());
		return picosha2::bytes_to_hex_string(hash.begin(), hash.end());

	}



	std::string CUtils::calculateRandomSHA256String(const uint32_t nIterations)
	{
		if ((nIterations == 0) || (nIterations > LIBMC_MAXRANDOMSTRINGITERATIONS))
			throw std::runtime_error("invalid random string iterations");

		std::string sRandomString;

		uint32_t nCount = nIterations + (((uint32_t) rand()) % nIterations);
		for (uint32_t nIndex = 0; nIndex < nCount; nIndex++)
			sRandomString += createUUID();

		return calculateSHA256FromString(sRandomString);
	}

	std::string CUtils::encodeBase64(const std::string& sString, eBase64Type eType)
	{		
		switch (eType) {
		case eBase64Type::RFC4648:
			return cppcodec::base64_rfc4648::encode(sString);
		case eBase64Type::URL:
			return cppcodec::base64_url::encode(sString);
		default:
			throw std::runtime_error("invalid base64 type");
		}

	}

	void CUtils::decodeBase64(const std::string& sString, eBase64Type eType, std::vector<uint8_t>& byteBuffer)
	{
		switch (eType) {
		case eBase64Type::RFC4648:
			cppcodec::base64_rfc4648::decode(byteBuffer, sString);
			break;
		case eBase64Type::URL:
			cppcodec::base64_url::decode(byteBuffer, sString);
			break;
		default:
			throw std::runtime_error("invalid base64 type");
		}

	}

	std::string CUtils::decodeBase64ToASCIIString(const std::string& sString, eBase64Type eType)
	{
		std::vector<uint8_t> byteBuffer;
		byteBuffer.reserve (sString.length () + 1);
		decodeBase64(sString, eType, byteBuffer);

		for (auto b : byteBuffer) {
			if ((b < 32) || (b >= 128))
				throw std::runtime_error("invalid ASCII character in base64 decoding");
		}

		byteBuffer.push_back (0);
		return std::string((char*)byteBuffer.data());
	}


	std::set<std::string> CUtils::findContentOfDirectory(const std::string& sDirectory, bool bReturnFiles, bool bReturnDirectories)
	{
		std::set<std::string> foundItems;

#ifdef _WIN32

		std::wstring sSearchString = UTF8toUTF16(sDirectory + "/*");
		WIN32_FIND_DATAW findData;

		HANDLE hSearchHandle = FindFirstFileW(sSearchString.c_str(), &findData);
		if (hSearchHandle != INVALID_HANDLE_VALUE) {

			bool bFound = true;
			while (bFound) {

				std::string sFileName = UTF16toUTF8(findData.cFileName);
				bool bIsDirectory = (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0;

				if ((sFileName != "..") && (sFileName != ".")) {
					if ((bIsDirectory && bReturnDirectories) || ((!bIsDirectory) && bReturnFiles)) {
						foundItems.insert(sFileName);
					}
				}

				bFound = FindNextFileW (hSearchHandle, &findData);
			}

			FindClose(hSearchHandle);
			

		}


#else
		DIR* pDir = opendir (sDirectory.c_str ()); 
		if (pDir != nullptr) {
			struct dirent* pDirEnt = readdir (pDir);
			while (pDirEnt != nullptr) {
				std::string sFileName = pDirEnt->d_name;
				if ((sFileName != "..") && (sFileName != ".")) {
					bool bIsDirectory = (pDirEnt->d_type == DT_DIR);
					if ((bIsDirectory && bReturnDirectories) || ((!bIsDirectory) && bReturnFiles)) {
						foundItems.insert(sFileName);
					}
				}
				
				pDirEnt = readdir(pDir);
			}

			closedir(pDir);

		}

#endif

		return foundItems;
	}


}
