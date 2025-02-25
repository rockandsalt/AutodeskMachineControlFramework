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

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 'AS IS' AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL AUTODESK INC. BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


This file has been generated by the Automatic Component Toolkit (ACT) version 1.7.0-develop.

Abstract: This is an autogenerated C++ implementation file in order to allow easy
development of S7Net Communication Protocol. The functions in this file need to be implemented. It needs to be generated only once.

Interface version: 3.1.3

*/

#include "libs7com_abi.hpp"
#include "libs7com_interfaces.hpp"
#include "libs7com_interfaceexception.hpp"

#include <map>

using namespace LibS7Com::Impl;

LibS7ComResult handleLibS7ComException(IBase * pIBaseClass, ELibS7ComInterfaceException & Exception)
{
	LibS7ComResult errorCode = Exception.getErrorCode();

	if (pIBaseClass != nullptr)
		pIBaseClass->RegisterErrorMessage(Exception.what());

	return errorCode;
}

LibS7ComResult handleStdException(IBase * pIBaseClass, std::exception & Exception)
{
	LibS7ComResult errorCode = LIBS7COM_ERROR_GENERICEXCEPTION;

	if (pIBaseClass != nullptr)
		pIBaseClass->RegisterErrorMessage(Exception.what());

	return errorCode;
}

LibS7ComResult handleUnhandledException(IBase * pIBaseClass)
{
	LibS7ComResult errorCode = LIBS7COM_ERROR_GENERICEXCEPTION;

	if (pIBaseClass != nullptr)
		pIBaseClass->RegisterErrorMessage("Unhandled Exception");

	return errorCode;
}



/*************************************************************************************************************************
 Class implementation for Base
**************************************************************************************************************************/

/*************************************************************************************************************************
 Class implementation for CommandParameters
**************************************************************************************************************************/
LibS7ComResult libs7com_commandparameters_writestring(LibS7Com_CommandParameters pCommandParameters, LibS7Com_uint32 nAddress, LibS7Com_uint32 nMaxLength, const char * pValue)
{
	IBase* pIBaseClass = (IBase *)pCommandParameters;

	try {
		if (pValue == nullptr)
			throw ELibS7ComInterfaceException (LIBS7COM_ERROR_INVALIDPARAM);
		std::string sValue(pValue);
		ICommandParameters* pICommandParameters = dynamic_cast<ICommandParameters*>(pIBaseClass);
		if (!pICommandParameters)
			throw ELibS7ComInterfaceException(LIBS7COM_ERROR_INVALIDCAST);
		
		pICommandParameters->WriteString(nAddress, nMaxLength, sValue);

		return LIBS7COM_SUCCESS;
	}
	catch (ELibS7ComInterfaceException & Exception) {
		return handleLibS7ComException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibS7ComResult libs7com_commandparameters_writebool(LibS7Com_CommandParameters pCommandParameters, LibS7Com_uint32 nAddress, LibS7Com_uint32 nBit, bool bValue)
{
	IBase* pIBaseClass = (IBase *)pCommandParameters;

	try {
		ICommandParameters* pICommandParameters = dynamic_cast<ICommandParameters*>(pIBaseClass);
		if (!pICommandParameters)
			throw ELibS7ComInterfaceException(LIBS7COM_ERROR_INVALIDCAST);
		
		pICommandParameters->WriteBool(nAddress, nBit, bValue);

		return LIBS7COM_SUCCESS;
	}
	catch (ELibS7ComInterfaceException & Exception) {
		return handleLibS7ComException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibS7ComResult libs7com_commandparameters_writebyte(LibS7Com_CommandParameters pCommandParameters, LibS7Com_uint32 nAddress, LibS7Com_uint8 nValue)
{
	IBase* pIBaseClass = (IBase *)pCommandParameters;

	try {
		ICommandParameters* pICommandParameters = dynamic_cast<ICommandParameters*>(pIBaseClass);
		if (!pICommandParameters)
			throw ELibS7ComInterfaceException(LIBS7COM_ERROR_INVALIDCAST);
		
		pICommandParameters->WriteByte(nAddress, nValue);

		return LIBS7COM_SUCCESS;
	}
	catch (ELibS7ComInterfaceException & Exception) {
		return handleLibS7ComException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibS7ComResult libs7com_commandparameters_writeint16(LibS7Com_CommandParameters pCommandParameters, LibS7Com_uint32 nAddress, LibS7Com_int16 nValue)
{
	IBase* pIBaseClass = (IBase *)pCommandParameters;

	try {
		ICommandParameters* pICommandParameters = dynamic_cast<ICommandParameters*>(pIBaseClass);
		if (!pICommandParameters)
			throw ELibS7ComInterfaceException(LIBS7COM_ERROR_INVALIDCAST);
		
		pICommandParameters->WriteInt16(nAddress, nValue);

		return LIBS7COM_SUCCESS;
	}
	catch (ELibS7ComInterfaceException & Exception) {
		return handleLibS7ComException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibS7ComResult libs7com_commandparameters_writeuint16(LibS7Com_CommandParameters pCommandParameters, LibS7Com_uint32 nAddress, LibS7Com_uint16 nValue)
{
	IBase* pIBaseClass = (IBase *)pCommandParameters;

	try {
		ICommandParameters* pICommandParameters = dynamic_cast<ICommandParameters*>(pIBaseClass);
		if (!pICommandParameters)
			throw ELibS7ComInterfaceException(LIBS7COM_ERROR_INVALIDCAST);
		
		pICommandParameters->WriteUint16(nAddress, nValue);

		return LIBS7COM_SUCCESS;
	}
	catch (ELibS7ComInterfaceException & Exception) {
		return handleLibS7ComException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibS7ComResult libs7com_commandparameters_writeint32(LibS7Com_CommandParameters pCommandParameters, LibS7Com_uint32 nAddress, LibS7Com_int32 nValue)
{
	IBase* pIBaseClass = (IBase *)pCommandParameters;

	try {
		ICommandParameters* pICommandParameters = dynamic_cast<ICommandParameters*>(pIBaseClass);
		if (!pICommandParameters)
			throw ELibS7ComInterfaceException(LIBS7COM_ERROR_INVALIDCAST);
		
		pICommandParameters->WriteInt32(nAddress, nValue);

		return LIBS7COM_SUCCESS;
	}
	catch (ELibS7ComInterfaceException & Exception) {
		return handleLibS7ComException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibS7ComResult libs7com_commandparameters_writeuint32(LibS7Com_CommandParameters pCommandParameters, LibS7Com_uint32 nAddress, LibS7Com_uint32 nValue)
{
	IBase* pIBaseClass = (IBase *)pCommandParameters;

	try {
		ICommandParameters* pICommandParameters = dynamic_cast<ICommandParameters*>(pIBaseClass);
		if (!pICommandParameters)
			throw ELibS7ComInterfaceException(LIBS7COM_ERROR_INVALIDCAST);
		
		pICommandParameters->WriteUint32(nAddress, nValue);

		return LIBS7COM_SUCCESS;
	}
	catch (ELibS7ComInterfaceException & Exception) {
		return handleLibS7ComException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibS7ComResult libs7com_commandparameters_writereal(LibS7Com_CommandParameters pCommandParameters, LibS7Com_uint32 nAddress, LibS7Com_double dValue)
{
	IBase* pIBaseClass = (IBase *)pCommandParameters;

	try {
		ICommandParameters* pICommandParameters = dynamic_cast<ICommandParameters*>(pIBaseClass);
		if (!pICommandParameters)
			throw ELibS7ComInterfaceException(LIBS7COM_ERROR_INVALIDCAST);
		
		pICommandParameters->WriteReal(nAddress, dValue);

		return LIBS7COM_SUCCESS;
	}
	catch (ELibS7ComInterfaceException & Exception) {
		return handleLibS7ComException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibS7ComResult libs7com_commandparameters_writelreal(LibS7Com_CommandParameters pCommandParameters, LibS7Com_uint32 nAddress, LibS7Com_double dValue)
{
	IBase* pIBaseClass = (IBase *)pCommandParameters;

	try {
		ICommandParameters* pICommandParameters = dynamic_cast<ICommandParameters*>(pIBaseClass);
		if (!pICommandParameters)
			throw ELibS7ComInterfaceException(LIBS7COM_ERROR_INVALIDCAST);
		
		pICommandParameters->WriteLReal(nAddress, dValue);

		return LIBS7COM_SUCCESS;
	}
	catch (ELibS7ComInterfaceException & Exception) {
		return handleLibS7ComException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}


/*************************************************************************************************************************
 Class implementation for PLCCommunication
**************************************************************************************************************************/
LibS7ComResult libs7com_plccommunication_setprotocolconfiguration(LibS7Com_PLCCommunication pPLCCommunication, LibS7Com_uint32 nMajorVersion, LibS7Com_uint32 nMinorVersion, LibS7Com_uint32 nPatchVersion, LibS7Com_uint32 nPLCtoAMC_DBNo, LibS7Com_uint32 nPLCtoAMC_Size, LibS7Com_uint32 nAMCtoPLC_DBNo, LibS7Com_uint32 nAMCtoPLC_Size)
{
	IBase* pIBaseClass = (IBase *)pPLCCommunication;

	try {
		IPLCCommunication* pIPLCCommunication = dynamic_cast<IPLCCommunication*>(pIBaseClass);
		if (!pIPLCCommunication)
			throw ELibS7ComInterfaceException(LIBS7COM_ERROR_INVALIDCAST);
		
		pIPLCCommunication->SetProtocolConfiguration(nMajorVersion, nMinorVersion, nPatchVersion, nPLCtoAMC_DBNo, nPLCtoAMC_Size, nAMCtoPLC_DBNo, nAMCtoPLC_Size);

		return LIBS7COM_SUCCESS;
	}
	catch (ELibS7ComInterfaceException & Exception) {
		return handleLibS7ComException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibS7ComResult libs7com_plccommunication_setamctoplcoffsets(LibS7Com_PLCCommunication pPLCCommunication, LibS7Com_uint32 nMajorVersionAddress, LibS7Com_uint32 nMinorVersionAddress, LibS7Com_uint32 nPatchVersionAddress, LibS7Com_uint32 nBuildVersionAddress, LibS7Com_uint32 nCommandSequenceAddress, LibS7Com_uint32 nCommandIDAddress, LibS7Com_uint32 nCommandChecksumAddress)
{
	IBase* pIBaseClass = (IBase *)pPLCCommunication;

	try {
		IPLCCommunication* pIPLCCommunication = dynamic_cast<IPLCCommunication*>(pIBaseClass);
		if (!pIPLCCommunication)
			throw ELibS7ComInterfaceException(LIBS7COM_ERROR_INVALIDCAST);
		
		pIPLCCommunication->SetAMCTOPLCOffsets(nMajorVersionAddress, nMinorVersionAddress, nPatchVersionAddress, nBuildVersionAddress, nCommandSequenceAddress, nCommandIDAddress, nCommandChecksumAddress);

		return LIBS7COM_SUCCESS;
	}
	catch (ELibS7ComInterfaceException & Exception) {
		return handleLibS7ComException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibS7ComResult libs7com_plccommunication_setplctoamcoffsets(LibS7Com_PLCCommunication pPLCCommunication, LibS7Com_uint32 nMajorVersionAddress, LibS7Com_uint32 nMinorVersionAddress, LibS7Com_uint32 nPatchVersionAddress, LibS7Com_uint32 nBuildVersionAddress, LibS7Com_uint32 nSequenceRunningAddress, LibS7Com_uint32 nSequenceFinishedAddress, LibS7Com_uint32 nSequenceStatusAddress, LibS7Com_uint32 nSequenceErrorAddress)
{
	IBase* pIBaseClass = (IBase *)pPLCCommunication;

	try {
		IPLCCommunication* pIPLCCommunication = dynamic_cast<IPLCCommunication*>(pIBaseClass);
		if (!pIPLCCommunication)
			throw ELibS7ComInterfaceException(LIBS7COM_ERROR_INVALIDCAST);
		
		pIPLCCommunication->SetPLCToAMCOffsets(nMajorVersionAddress, nMinorVersionAddress, nPatchVersionAddress, nBuildVersionAddress, nSequenceRunningAddress, nSequenceFinishedAddress, nSequenceStatusAddress, nSequenceErrorAddress);

		return LIBS7COM_SUCCESS;
	}
	catch (ELibS7ComInterfaceException & Exception) {
		return handleLibS7ComException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibS7ComResult libs7com_plccommunication_startcommunication(LibS7Com_PLCCommunication pPLCCommunication, LibS7Net_PLC pPLC)
{
	IBase* pIBaseClass = (IBase *)pPLCCommunication;

	try {
		LibS7Net::PPLC pIPLC = std::make_shared<LibS7Net::CPLC>(CWrapper::sPLibS7NetWrapper.get(), pPLC);
		CWrapper::sPLibS7NetWrapper->AcquireInstance(pIPLC.get());
		if (!pIPLC)
			throw ELibS7ComInterfaceException (LIBS7COM_ERROR_INVALIDCAST);
		
		IPLCCommunication* pIPLCCommunication = dynamic_cast<IPLCCommunication*>(pIBaseClass);
		if (!pIPLCCommunication)
			throw ELibS7ComInterfaceException(LIBS7COM_ERROR_INVALIDCAST);
		
		pIPLCCommunication->StartCommunication(pIPLC);

		return LIBS7COM_SUCCESS;
	}
	catch (ELibS7ComInterfaceException & Exception) {
		return handleLibS7ComException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibS7ComResult libs7com_plccommunication_retrievestatus(LibS7Com_PLCCommunication pPLCCommunication)
{
	IBase* pIBaseClass = (IBase *)pPLCCommunication;

	try {
		IPLCCommunication* pIPLCCommunication = dynamic_cast<IPLCCommunication*>(pIBaseClass);
		if (!pIPLCCommunication)
			throw ELibS7ComInterfaceException(LIBS7COM_ERROR_INVALIDCAST);
		
		pIPLCCommunication->RetrieveStatus();

		return LIBS7COM_SUCCESS;
	}
	catch (ELibS7ComInterfaceException & Exception) {
		return handleLibS7ComException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibS7ComResult libs7com_plccommunication_stopcommunication(LibS7Com_PLCCommunication pPLCCommunication)
{
	IBase* pIBaseClass = (IBase *)pPLCCommunication;

	try {
		IPLCCommunication* pIPLCCommunication = dynamic_cast<IPLCCommunication*>(pIBaseClass);
		if (!pIPLCCommunication)
			throw ELibS7ComInterfaceException(LIBS7COM_ERROR_INVALIDCAST);
		
		pIPLCCommunication->StopCommunication();

		return LIBS7COM_SUCCESS;
	}
	catch (ELibS7ComInterfaceException & Exception) {
		return handleLibS7ComException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibS7ComResult libs7com_plccommunication_prepareparameters(LibS7Com_PLCCommunication pPLCCommunication, LibS7Com_CommandParameters * pInstance)
{
	IBase* pIBaseClass = (IBase *)pPLCCommunication;

	try {
		if (pInstance == nullptr)
			throw ELibS7ComInterfaceException (LIBS7COM_ERROR_INVALIDPARAM);
		IBase* pBaseInstance(nullptr);
		IPLCCommunication* pIPLCCommunication = dynamic_cast<IPLCCommunication*>(pIBaseClass);
		if (!pIPLCCommunication)
			throw ELibS7ComInterfaceException(LIBS7COM_ERROR_INVALIDCAST);
		
		pBaseInstance = pIPLCCommunication->PrepareParameters();

		*pInstance = (IBase*)(pBaseInstance);
		return LIBS7COM_SUCCESS;
	}
	catch (ELibS7ComInterfaceException & Exception) {
		return handleLibS7ComException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibS7ComResult libs7com_plccommunication_executecommand(LibS7Com_PLCCommunication pPLCCommunication, LibS7Com_CommandParameters pParametersInstance, LibS7Com_uint32 nCommandID, LibS7Com_uint32 * pSequenceID)
{
	IBase* pIBaseClass = (IBase *)pPLCCommunication;

	try {
		if (pSequenceID == nullptr)
			throw ELibS7ComInterfaceException (LIBS7COM_ERROR_INVALIDPARAM);
		IBase* pIBaseClassParametersInstance = (IBase *)pParametersInstance;
		ICommandParameters* pIParametersInstance = dynamic_cast<ICommandParameters*>(pIBaseClassParametersInstance);
		if (!pIParametersInstance)
			throw ELibS7ComInterfaceException (LIBS7COM_ERROR_INVALIDCAST);
		
		IPLCCommunication* pIPLCCommunication = dynamic_cast<IPLCCommunication*>(pIBaseClass);
		if (!pIPLCCommunication)
			throw ELibS7ComInterfaceException(LIBS7COM_ERROR_INVALIDCAST);
		
		*pSequenceID = pIPLCCommunication->ExecuteCommand(pIParametersInstance, nCommandID);

		return LIBS7COM_SUCCESS;
	}
	catch (ELibS7ComInterfaceException & Exception) {
		return handleLibS7ComException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibS7ComResult libs7com_plccommunication_checkcommandexecution(LibS7Com_PLCCommunication pPLCCommunication, LibS7Com_uint32 nSequenceID, bool * pSequenceIsActive, bool * pSequenceIsFinished, LibS7Com_uint32 * pErrorCode)
{
	IBase* pIBaseClass = (IBase *)pPLCCommunication;

	try {
		if (!pSequenceIsActive)
			throw ELibS7ComInterfaceException (LIBS7COM_ERROR_INVALIDPARAM);
		if (!pSequenceIsFinished)
			throw ELibS7ComInterfaceException (LIBS7COM_ERROR_INVALIDPARAM);
		if (!pErrorCode)
			throw ELibS7ComInterfaceException (LIBS7COM_ERROR_INVALIDPARAM);
		IPLCCommunication* pIPLCCommunication = dynamic_cast<IPLCCommunication*>(pIBaseClass);
		if (!pIPLCCommunication)
			throw ELibS7ComInterfaceException(LIBS7COM_ERROR_INVALIDCAST);
		
		pIPLCCommunication->CheckCommandExecution(nSequenceID, *pSequenceIsActive, *pSequenceIsFinished, *pErrorCode);

		return LIBS7COM_SUCCESS;
	}
	catch (ELibS7ComInterfaceException & Exception) {
		return handleLibS7ComException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibS7ComResult libs7com_plccommunication_readvariablestring(LibS7Com_PLCCommunication pPLCCommunication, LibS7Com_uint32 nAddress, LibS7Com_uint32 nMaxLength, const LibS7Com_uint32 nValueBufferSize, LibS7Com_uint32* pValueNeededChars, char * pValueBuffer)
{
	IBase* pIBaseClass = (IBase *)pPLCCommunication;

	try {
		if ( (!pValueBuffer) && !(pValueNeededChars) )
			throw ELibS7ComInterfaceException (LIBS7COM_ERROR_INVALIDPARAM);
		std::string sValue("");
		IPLCCommunication* pIPLCCommunication = dynamic_cast<IPLCCommunication*>(pIBaseClass);
		if (!pIPLCCommunication)
			throw ELibS7ComInterfaceException(LIBS7COM_ERROR_INVALIDCAST);
		
		bool isCacheCall = (pValueBuffer == nullptr);
		if (isCacheCall) {
			sValue = pIPLCCommunication->ReadVariableString(nAddress, nMaxLength);

			pIPLCCommunication->_setCache (new ParameterCache_1<std::string> (sValue));
		}
		else {
			auto cache = dynamic_cast<ParameterCache_1<std::string>*> (pIPLCCommunication->_getCache ());
			if (cache == nullptr)
				throw ELibS7ComInterfaceException(LIBS7COM_ERROR_INVALIDCAST);
			cache->retrieveData (sValue);
			pIPLCCommunication->_setCache (nullptr);
		}
		
		if (pValueNeededChars)
			*pValueNeededChars = (LibS7Com_uint32) (sValue.size()+1);
		if (pValueBuffer) {
			if (sValue.size() >= nValueBufferSize)
				throw ELibS7ComInterfaceException (LIBS7COM_ERROR_BUFFERTOOSMALL);
			for (size_t iValue = 0; iValue < sValue.size(); iValue++)
				pValueBuffer[iValue] = sValue[iValue];
			pValueBuffer[sValue.size()] = 0;
		}
		return LIBS7COM_SUCCESS;
	}
	catch (ELibS7ComInterfaceException & Exception) {
		return handleLibS7ComException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibS7ComResult libs7com_plccommunication_readvariablebool(LibS7Com_PLCCommunication pPLCCommunication, LibS7Com_uint32 nAddress, LibS7Com_uint32 nBit, bool * pValue)
{
	IBase* pIBaseClass = (IBase *)pPLCCommunication;

	try {
		if (pValue == nullptr)
			throw ELibS7ComInterfaceException (LIBS7COM_ERROR_INVALIDPARAM);
		IPLCCommunication* pIPLCCommunication = dynamic_cast<IPLCCommunication*>(pIBaseClass);
		if (!pIPLCCommunication)
			throw ELibS7ComInterfaceException(LIBS7COM_ERROR_INVALIDCAST);
		
		*pValue = pIPLCCommunication->ReadVariableBool(nAddress, nBit);

		return LIBS7COM_SUCCESS;
	}
	catch (ELibS7ComInterfaceException & Exception) {
		return handleLibS7ComException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibS7ComResult libs7com_plccommunication_readvariablebyte(LibS7Com_PLCCommunication pPLCCommunication, LibS7Com_uint32 nAddress, LibS7Com_uint8 * pValue)
{
	IBase* pIBaseClass = (IBase *)pPLCCommunication;

	try {
		if (pValue == nullptr)
			throw ELibS7ComInterfaceException (LIBS7COM_ERROR_INVALIDPARAM);
		IPLCCommunication* pIPLCCommunication = dynamic_cast<IPLCCommunication*>(pIBaseClass);
		if (!pIPLCCommunication)
			throw ELibS7ComInterfaceException(LIBS7COM_ERROR_INVALIDCAST);
		
		*pValue = pIPLCCommunication->ReadVariableByte(nAddress);

		return LIBS7COM_SUCCESS;
	}
	catch (ELibS7ComInterfaceException & Exception) {
		return handleLibS7ComException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibS7ComResult libs7com_plccommunication_readvariableint16(LibS7Com_PLCCommunication pPLCCommunication, LibS7Com_uint32 nAddress, LibS7Com_int16 * pValue)
{
	IBase* pIBaseClass = (IBase *)pPLCCommunication;

	try {
		if (pValue == nullptr)
			throw ELibS7ComInterfaceException (LIBS7COM_ERROR_INVALIDPARAM);
		IPLCCommunication* pIPLCCommunication = dynamic_cast<IPLCCommunication*>(pIBaseClass);
		if (!pIPLCCommunication)
			throw ELibS7ComInterfaceException(LIBS7COM_ERROR_INVALIDCAST);
		
		*pValue = pIPLCCommunication->ReadVariableInt16(nAddress);

		return LIBS7COM_SUCCESS;
	}
	catch (ELibS7ComInterfaceException & Exception) {
		return handleLibS7ComException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibS7ComResult libs7com_plccommunication_readvariableuint16(LibS7Com_PLCCommunication pPLCCommunication, LibS7Com_uint32 nAddress, LibS7Com_uint16 * pValue)
{
	IBase* pIBaseClass = (IBase *)pPLCCommunication;

	try {
		if (pValue == nullptr)
			throw ELibS7ComInterfaceException (LIBS7COM_ERROR_INVALIDPARAM);
		IPLCCommunication* pIPLCCommunication = dynamic_cast<IPLCCommunication*>(pIBaseClass);
		if (!pIPLCCommunication)
			throw ELibS7ComInterfaceException(LIBS7COM_ERROR_INVALIDCAST);
		
		*pValue = pIPLCCommunication->ReadVariableUint16(nAddress);

		return LIBS7COM_SUCCESS;
	}
	catch (ELibS7ComInterfaceException & Exception) {
		return handleLibS7ComException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibS7ComResult libs7com_plccommunication_readvariableint32(LibS7Com_PLCCommunication pPLCCommunication, LibS7Com_uint32 nAddress, LibS7Com_int32 * pValue)
{
	IBase* pIBaseClass = (IBase *)pPLCCommunication;

	try {
		if (pValue == nullptr)
			throw ELibS7ComInterfaceException (LIBS7COM_ERROR_INVALIDPARAM);
		IPLCCommunication* pIPLCCommunication = dynamic_cast<IPLCCommunication*>(pIBaseClass);
		if (!pIPLCCommunication)
			throw ELibS7ComInterfaceException(LIBS7COM_ERROR_INVALIDCAST);
		
		*pValue = pIPLCCommunication->ReadVariableInt32(nAddress);

		return LIBS7COM_SUCCESS;
	}
	catch (ELibS7ComInterfaceException & Exception) {
		return handleLibS7ComException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibS7ComResult libs7com_plccommunication_readvariableuint32(LibS7Com_PLCCommunication pPLCCommunication, LibS7Com_uint32 nAddress, LibS7Com_uint32 * pValue)
{
	IBase* pIBaseClass = (IBase *)pPLCCommunication;

	try {
		if (pValue == nullptr)
			throw ELibS7ComInterfaceException (LIBS7COM_ERROR_INVALIDPARAM);
		IPLCCommunication* pIPLCCommunication = dynamic_cast<IPLCCommunication*>(pIBaseClass);
		if (!pIPLCCommunication)
			throw ELibS7ComInterfaceException(LIBS7COM_ERROR_INVALIDCAST);
		
		*pValue = pIPLCCommunication->ReadVariableUint32(nAddress);

		return LIBS7COM_SUCCESS;
	}
	catch (ELibS7ComInterfaceException & Exception) {
		return handleLibS7ComException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibS7ComResult libs7com_plccommunication_readvariablereal(LibS7Com_PLCCommunication pPLCCommunication, LibS7Com_uint32 nAddress, LibS7Com_double * pValue)
{
	IBase* pIBaseClass = (IBase *)pPLCCommunication;

	try {
		if (pValue == nullptr)
			throw ELibS7ComInterfaceException (LIBS7COM_ERROR_INVALIDPARAM);
		IPLCCommunication* pIPLCCommunication = dynamic_cast<IPLCCommunication*>(pIBaseClass);
		if (!pIPLCCommunication)
			throw ELibS7ComInterfaceException(LIBS7COM_ERROR_INVALIDCAST);
		
		*pValue = pIPLCCommunication->ReadVariableReal(nAddress);

		return LIBS7COM_SUCCESS;
	}
	catch (ELibS7ComInterfaceException & Exception) {
		return handleLibS7ComException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibS7ComResult libs7com_plccommunication_readvariablelreal(LibS7Com_PLCCommunication pPLCCommunication, LibS7Com_uint32 nAddress, LibS7Com_double * pValue)
{
	IBase* pIBaseClass = (IBase *)pPLCCommunication;

	try {
		if (pValue == nullptr)
			throw ELibS7ComInterfaceException (LIBS7COM_ERROR_INVALIDPARAM);
		IPLCCommunication* pIPLCCommunication = dynamic_cast<IPLCCommunication*>(pIBaseClass);
		if (!pIPLCCommunication)
			throw ELibS7ComInterfaceException(LIBS7COM_ERROR_INVALIDCAST);
		
		*pValue = pIPLCCommunication->ReadVariableLReal(nAddress);

		return LIBS7COM_SUCCESS;
	}
	catch (ELibS7ComInterfaceException & Exception) {
		return handleLibS7ComException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}



/*************************************************************************************************************************
 Function table lookup implementation
**************************************************************************************************************************/

LibS7ComResult LibS7Com::Impl::LibS7Com_GetProcAddress (const char * pProcName, void ** ppProcAddress)
{
	if (pProcName == nullptr)
		return LIBS7COM_ERROR_INVALIDPARAM;
	if (ppProcAddress == nullptr)
		return LIBS7COM_ERROR_INVALIDPARAM;
	*ppProcAddress = nullptr;
	std::string sProcName (pProcName);
	
	if (sProcName == "libs7com_commandparameters_writestring") 
		*ppProcAddress = (void*) &libs7com_commandparameters_writestring;
	if (sProcName == "libs7com_commandparameters_writebool") 
		*ppProcAddress = (void*) &libs7com_commandparameters_writebool;
	if (sProcName == "libs7com_commandparameters_writebyte") 
		*ppProcAddress = (void*) &libs7com_commandparameters_writebyte;
	if (sProcName == "libs7com_commandparameters_writeint16") 
		*ppProcAddress = (void*) &libs7com_commandparameters_writeint16;
	if (sProcName == "libs7com_commandparameters_writeuint16") 
		*ppProcAddress = (void*) &libs7com_commandparameters_writeuint16;
	if (sProcName == "libs7com_commandparameters_writeint32") 
		*ppProcAddress = (void*) &libs7com_commandparameters_writeint32;
	if (sProcName == "libs7com_commandparameters_writeuint32") 
		*ppProcAddress = (void*) &libs7com_commandparameters_writeuint32;
	if (sProcName == "libs7com_commandparameters_writereal") 
		*ppProcAddress = (void*) &libs7com_commandparameters_writereal;
	if (sProcName == "libs7com_commandparameters_writelreal") 
		*ppProcAddress = (void*) &libs7com_commandparameters_writelreal;
	if (sProcName == "libs7com_plccommunication_setprotocolconfiguration") 
		*ppProcAddress = (void*) &libs7com_plccommunication_setprotocolconfiguration;
	if (sProcName == "libs7com_plccommunication_setamctoplcoffsets") 
		*ppProcAddress = (void*) &libs7com_plccommunication_setamctoplcoffsets;
	if (sProcName == "libs7com_plccommunication_setplctoamcoffsets") 
		*ppProcAddress = (void*) &libs7com_plccommunication_setplctoamcoffsets;
	if (sProcName == "libs7com_plccommunication_startcommunication") 
		*ppProcAddress = (void*) &libs7com_plccommunication_startcommunication;
	if (sProcName == "libs7com_plccommunication_retrievestatus") 
		*ppProcAddress = (void*) &libs7com_plccommunication_retrievestatus;
	if (sProcName == "libs7com_plccommunication_stopcommunication") 
		*ppProcAddress = (void*) &libs7com_plccommunication_stopcommunication;
	if (sProcName == "libs7com_plccommunication_prepareparameters") 
		*ppProcAddress = (void*) &libs7com_plccommunication_prepareparameters;
	if (sProcName == "libs7com_plccommunication_executecommand") 
		*ppProcAddress = (void*) &libs7com_plccommunication_executecommand;
	if (sProcName == "libs7com_plccommunication_checkcommandexecution") 
		*ppProcAddress = (void*) &libs7com_plccommunication_checkcommandexecution;
	if (sProcName == "libs7com_plccommunication_readvariablestring") 
		*ppProcAddress = (void*) &libs7com_plccommunication_readvariablestring;
	if (sProcName == "libs7com_plccommunication_readvariablebool") 
		*ppProcAddress = (void*) &libs7com_plccommunication_readvariablebool;
	if (sProcName == "libs7com_plccommunication_readvariablebyte") 
		*ppProcAddress = (void*) &libs7com_plccommunication_readvariablebyte;
	if (sProcName == "libs7com_plccommunication_readvariableint16") 
		*ppProcAddress = (void*) &libs7com_plccommunication_readvariableint16;
	if (sProcName == "libs7com_plccommunication_readvariableuint16") 
		*ppProcAddress = (void*) &libs7com_plccommunication_readvariableuint16;
	if (sProcName == "libs7com_plccommunication_readvariableint32") 
		*ppProcAddress = (void*) &libs7com_plccommunication_readvariableint32;
	if (sProcName == "libs7com_plccommunication_readvariableuint32") 
		*ppProcAddress = (void*) &libs7com_plccommunication_readvariableuint32;
	if (sProcName == "libs7com_plccommunication_readvariablereal") 
		*ppProcAddress = (void*) &libs7com_plccommunication_readvariablereal;
	if (sProcName == "libs7com_plccommunication_readvariablelreal") 
		*ppProcAddress = (void*) &libs7com_plccommunication_readvariablelreal;
	if (sProcName == "libs7com_getversion") 
		*ppProcAddress = (void*) &libs7com_getversion;
	if (sProcName == "libs7com_getlasterror") 
		*ppProcAddress = (void*) &libs7com_getlasterror;
	if (sProcName == "libs7com_acquireinstance") 
		*ppProcAddress = (void*) &libs7com_acquireinstance;
	if (sProcName == "libs7com_releaseinstance") 
		*ppProcAddress = (void*) &libs7com_releaseinstance;
	if (sProcName == "libs7com_injectcomponent") 
		*ppProcAddress = (void*) &libs7com_injectcomponent;
	if (sProcName == "libs7com_getsymbollookupmethod") 
		*ppProcAddress = (void*) &libs7com_getsymbollookupmethod;
	if (sProcName == "libs7com_createplccommunication") 
		*ppProcAddress = (void*) &libs7com_createplccommunication;
	
	if (*ppProcAddress == nullptr) 
		return LIBS7COM_ERROR_COULDNOTFINDLIBRARYEXPORT;
	return LIBS7COM_SUCCESS;
}

/*************************************************************************************************************************
 Global functions implementation
**************************************************************************************************************************/
LibS7ComResult libs7com_getversion(LibS7Com_uint32 * pMajor, LibS7Com_uint32 * pMinor, LibS7Com_uint32 * pMicro)
{
	IBase* pIBaseClass = nullptr;

	try {
		if (!pMajor)
			throw ELibS7ComInterfaceException (LIBS7COM_ERROR_INVALIDPARAM);
		if (!pMinor)
			throw ELibS7ComInterfaceException (LIBS7COM_ERROR_INVALIDPARAM);
		if (!pMicro)
			throw ELibS7ComInterfaceException (LIBS7COM_ERROR_INVALIDPARAM);
		CWrapper::GetVersion(*pMajor, *pMinor, *pMicro);

		return LIBS7COM_SUCCESS;
	}
	catch (ELibS7ComInterfaceException & Exception) {
		return handleLibS7ComException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibS7ComResult libs7com_getlasterror(LibS7Com_Base pInstance, const LibS7Com_uint32 nErrorMessageBufferSize, LibS7Com_uint32* pErrorMessageNeededChars, char * pErrorMessageBuffer, bool * pHasError)
{
	IBase* pIBaseClass = nullptr;

	try {
		if ( (!pErrorMessageBuffer) && !(pErrorMessageNeededChars) )
			throw ELibS7ComInterfaceException (LIBS7COM_ERROR_INVALIDPARAM);
		if (pHasError == nullptr)
			throw ELibS7ComInterfaceException (LIBS7COM_ERROR_INVALIDPARAM);
		IBase* pIBaseClassInstance = (IBase *)pInstance;
		IBase* pIInstance = dynamic_cast<IBase*>(pIBaseClassInstance);
		if (!pIInstance)
			throw ELibS7ComInterfaceException (LIBS7COM_ERROR_INVALIDCAST);
		
		std::string sErrorMessage("");
		*pHasError = CWrapper::GetLastError(pIInstance, sErrorMessage);

		if (pErrorMessageNeededChars)
			*pErrorMessageNeededChars = (LibS7Com_uint32) (sErrorMessage.size()+1);
		if (pErrorMessageBuffer) {
			if (sErrorMessage.size() >= nErrorMessageBufferSize)
				throw ELibS7ComInterfaceException (LIBS7COM_ERROR_BUFFERTOOSMALL);
			for (size_t iErrorMessage = 0; iErrorMessage < sErrorMessage.size(); iErrorMessage++)
				pErrorMessageBuffer[iErrorMessage] = sErrorMessage[iErrorMessage];
			pErrorMessageBuffer[sErrorMessage.size()] = 0;
		}
		return LIBS7COM_SUCCESS;
	}
	catch (ELibS7ComInterfaceException & Exception) {
		return handleLibS7ComException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibS7ComResult libs7com_acquireinstance(LibS7Com_Base pInstance)
{
	IBase* pIBaseClass = nullptr;

	try {
		IBase* pIBaseClassInstance = (IBase *)pInstance;
		IBase* pIInstance = dynamic_cast<IBase*>(pIBaseClassInstance);
		if (!pIInstance)
			throw ELibS7ComInterfaceException (LIBS7COM_ERROR_INVALIDCAST);
		
		CWrapper::AcquireInstance(pIInstance);

		return LIBS7COM_SUCCESS;
	}
	catch (ELibS7ComInterfaceException & Exception) {
		return handleLibS7ComException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibS7ComResult libs7com_releaseinstance(LibS7Com_Base pInstance)
{
	IBase* pIBaseClass = nullptr;

	try {
		IBase* pIBaseClassInstance = (IBase *)pInstance;
		IBase* pIInstance = dynamic_cast<IBase*>(pIBaseClassInstance);
		if (!pIInstance)
			throw ELibS7ComInterfaceException (LIBS7COM_ERROR_INVALIDCAST);
		
		CWrapper::ReleaseInstance(pIInstance);

		return LIBS7COM_SUCCESS;
	}
	catch (ELibS7ComInterfaceException & Exception) {
		return handleLibS7ComException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibS7ComResult libs7com_injectcomponent(const char * pNameSpace, LibS7Com_pvoid pSymbolAddressMethod)
{
	IBase* pIBaseClass = nullptr;

	try {
		if (pNameSpace == nullptr)
			throw ELibS7ComInterfaceException (LIBS7COM_ERROR_INVALIDPARAM);
		std::string sNameSpace(pNameSpace);
		
		bool bNameSpaceFound = false;
		
		if (sNameSpace == "LibS7Net") {
			if (CWrapper::sPLibS7NetWrapper.get() != nullptr) {
				throw ELibS7ComInterfaceException(LIBS7COM_ERROR_COULDNOTLOADLIBRARY);
			}
			CWrapper::sPLibS7NetWrapper = LibS7Net::CWrapper::loadLibraryFromSymbolLookupMethod(pSymbolAddressMethod);
			bNameSpaceFound = true;
		}
		
		if (!bNameSpaceFound)
			throw ELibS7ComInterfaceException(LIBS7COM_ERROR_COULDNOTLOADLIBRARY);
		
		return LIBS7COM_SUCCESS;
	}
	catch (ELibS7ComInterfaceException & Exception) {
		return handleLibS7ComException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibS7ComResult libs7com_getsymbollookupmethod(LibS7Com_pvoid * pSymbolLookupMethod)
{
	IBase* pIBaseClass = nullptr;

	try {
		if (pSymbolLookupMethod == nullptr)
			throw ELibS7ComInterfaceException (LIBS7COM_ERROR_INVALIDPARAM);
		*pSymbolLookupMethod = (void*)&LibS7Com::Impl::LibS7Com_GetProcAddress;
		return LIBS7COM_SUCCESS;
	}
	catch (ELibS7ComInterfaceException & Exception) {
		return handleLibS7ComException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}

LibS7ComResult libs7com_createplccommunication(LibS7Com_PLCCommunication * pPLCCommunication)
{
	IBase* pIBaseClass = nullptr;

	try {
		if (pPLCCommunication == nullptr)
			throw ELibS7ComInterfaceException (LIBS7COM_ERROR_INVALIDPARAM);
		IBase* pBasePLCCommunication(nullptr);
		pBasePLCCommunication = CWrapper::CreatePLCCommunication();

		*pPLCCommunication = (IBase*)(pBasePLCCommunication);
		return LIBS7COM_SUCCESS;
	}
	catch (ELibS7ComInterfaceException & Exception) {
		return handleLibS7ComException(pIBaseClass, Exception);
	}
	catch (std::exception & StdException) {
		return handleStdException(pIBaseClass, StdException);
	}
	catch (...) {
		return handleUnhandledException(pIBaseClass);
	}
}


