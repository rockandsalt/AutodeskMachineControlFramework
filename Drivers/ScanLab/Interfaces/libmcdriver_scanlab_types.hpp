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

Abstract: This is an autogenerated C++-Header file with basic types in
order to allow an easy use of MC Driver ScanLab RTC6

Interface version: 1.0.0

*/

#ifndef __LIBMCDRIVER_SCANLAB_TYPES_HEADER_CPP
#define __LIBMCDRIVER_SCANLAB_TYPES_HEADER_CPP


/*************************************************************************************************************************
 Scalar types definition
**************************************************************************************************************************/

#ifdef LIBMCDRIVER_SCANLAB_USELEGACYINTEGERTYPES

typedef unsigned char LibMCDriver_ScanLab_uint8;
typedef unsigned short LibMCDriver_ScanLab_uint16 ;
typedef unsigned int LibMCDriver_ScanLab_uint32;
typedef unsigned long long LibMCDriver_ScanLab_uint64;
typedef char LibMCDriver_ScanLab_int8;
typedef short LibMCDriver_ScanLab_int16;
typedef int LibMCDriver_ScanLab_int32;
typedef long long LibMCDriver_ScanLab_int64;

#else // LIBMCDRIVER_SCANLAB_USELEGACYINTEGERTYPES

#include <stdint.h>

typedef uint8_t LibMCDriver_ScanLab_uint8;
typedef uint16_t LibMCDriver_ScanLab_uint16;
typedef uint32_t LibMCDriver_ScanLab_uint32;
typedef uint64_t LibMCDriver_ScanLab_uint64;
typedef int8_t LibMCDriver_ScanLab_int8;
typedef int16_t LibMCDriver_ScanLab_int16;
typedef int32_t LibMCDriver_ScanLab_int32;
typedef int64_t LibMCDriver_ScanLab_int64 ;

#endif // LIBMCDRIVER_SCANLAB_USELEGACYINTEGERTYPES

typedef float LibMCDriver_ScanLab_single;
typedef double LibMCDriver_ScanLab_double;

/*************************************************************************************************************************
 General type definitions
**************************************************************************************************************************/

typedef LibMCDriver_ScanLab_int32 LibMCDriver_ScanLabResult;
typedef void * LibMCDriver_ScanLabHandle;
typedef void * LibMCDriver_ScanLab_pvoid;

/*************************************************************************************************************************
 Version for LibMCDriver_ScanLab
**************************************************************************************************************************/

#define LIBMCDRIVER_SCANLAB_VERSION_MAJOR 1
#define LIBMCDRIVER_SCANLAB_VERSION_MINOR 0
#define LIBMCDRIVER_SCANLAB_VERSION_MICRO 0
#define LIBMCDRIVER_SCANLAB_VERSION_PRERELEASEINFO ""
#define LIBMCDRIVER_SCANLAB_VERSION_BUILDINFO ""

/*************************************************************************************************************************
 Error constants for LibMCDriver_ScanLab
**************************************************************************************************************************/

#define LIBMCDRIVER_SCANLAB_SUCCESS 0
#define LIBMCDRIVER_SCANLAB_ERROR_NOTIMPLEMENTED 1
#define LIBMCDRIVER_SCANLAB_ERROR_INVALIDPARAM 2
#define LIBMCDRIVER_SCANLAB_ERROR_INVALIDCAST 3
#define LIBMCDRIVER_SCANLAB_ERROR_BUFFERTOOSMALL 4
#define LIBMCDRIVER_SCANLAB_ERROR_GENERICEXCEPTION 5
#define LIBMCDRIVER_SCANLAB_ERROR_COULDNOTLOADLIBRARY 6
#define LIBMCDRIVER_SCANLAB_ERROR_COULDNOTFINDLIBRARYEXPORT 7
#define LIBMCDRIVER_SCANLAB_ERROR_INCOMPATIBLEBINARYVERSION 8
#define LIBMCDRIVER_SCANLAB_ERROR_INVALIDSTATENAME 9
#define LIBMCDRIVER_SCANLAB_ERROR_DRIVERERROR 1000
#define LIBMCDRIVER_SCANLAB_ERROR_RTC6_NO_PCIE_CARD_FOUND 1001
#define LIBMCDRIVER_SCANLAB_ERROR_RTC6_ACCESS_DENIED 1002
#define LIBMCDRIVER_SCANLAB_ERROR_RTC6_SEND_ERROR 1003
#define LIBMCDRIVER_SCANLAB_ERROR_RTC6_TIMEOUT 1004
#define LIBMCDRIVER_SCANLAB_ERROR_RTC6_PARAM_ERROR 1005
#define LIBMCDRIVER_SCANLAB_ERROR_RTC6_BUSY 1006
#define LIBMCDRIVER_SCANLAB_ERROR_RTC6_REJECTED 1007
#define LIBMCDRIVER_SCANLAB_ERROR_RTC6_IGNORED 1008
#define LIBMCDRIVER_SCANLAB_ERROR_RTC6_VERSION_MISMATCH 1009
#define LIBMCDRIVER_SCANLAB_ERROR_RTC6_VERIFY_ERROR 1010
#define LIBMCDRIVER_SCANLAB_ERROR_RTC6_TYPE_REJECTED 1011
#define LIBMCDRIVER_SCANLAB_ERROR_RTC6_OUT_OF_MEMORY 1012
#define LIBMCDRIVER_SCANLAB_ERROR_RTC6_FLASH_ERROR 1013
#define LIBMCDRIVER_SCANLAB_ERROR_RTC6_ETH_ERROR 1014
#define LIBMCDRIVER_SCANLAB_ERROR_RTC6_CONFIG_ERROR 1015
#define LIBMCDRIVER_SCANLAB_ERROR_RTC6_UNKNOWN_ERROR 1016
#define LIBMCDRIVER_SCANLAB_ERROR_RTCOPEN_FAILED 1017
#define LIBMCDRIVER_SCANLAB_ERROR_INVALIDRTCPROC 1018
#define LIBMCDRIVER_SCANLAB_ERROR_INVALIDIPADDRESS 1019
#define LIBMCDRIVER_SCANLAB_ERROR_INVALIDNETMASK 1020
#define LIBMCDRIVER_SCANLAB_ERROR_CARDALREADYACQUIRED 1021
#define LIBMCDRIVER_SCANLAB_ERROR_CARDNOTFOUND 1022
#define LIBMCDRIVER_SCANLAB_ERROR_COULDNOTLOADPROGRAMFILE 1023
#define LIBMCDRIVER_SCANLAB_ERROR_COULDNOTLOADCORRECTIONFILE 1024
#define LIBMCDRIVER_SCANLAB_ERROR_DELAYSMUSTBEMULTIPLEOF10 1025
#define LIBMCDRIVER_SCANLAB_ERROR_SCANLABSDKNOTLOADED 1026
#define LIBMCDRIVER_SCANLAB_ERROR_SCANLABSDKALREADYLOADED 1027
#define LIBMCDRIVER_SCANLAB_ERROR_CARDALREADYINITIALIZED 1028
#define LIBMCDRIVER_SCANLAB_ERROR_CARDNOTINITIALIZED 1029
#define LIBMCDRIVER_SCANLAB_ERROR_INVALIDPOINTCOUNT 1030
#define LIBMCDRIVER_SCANLAB_ERROR_INVALIDMAXLASERPOWER 1031
#define LIBMCDRIVER_SCANLAB_ERROR_INVALIDLASERDELAY 1032
#define LIBMCDRIVER_SCANLAB_ERROR_INVALIDSCANNERDELAY 1033

/*************************************************************************************************************************
 Error strings for LibMCDriver_ScanLab
**************************************************************************************************************************/

inline const char * LIBMCDRIVER_SCANLAB_GETERRORSTRING (LibMCDriver_ScanLabResult nErrorCode) {
  switch (nErrorCode) {
    case LIBMCDRIVER_SCANLAB_SUCCESS: return "no error";
    case LIBMCDRIVER_SCANLAB_ERROR_NOTIMPLEMENTED: return "functionality not implemented";
    case LIBMCDRIVER_SCANLAB_ERROR_INVALIDPARAM: return "an invalid parameter was passed";
    case LIBMCDRIVER_SCANLAB_ERROR_INVALIDCAST: return "a type cast failed";
    case LIBMCDRIVER_SCANLAB_ERROR_BUFFERTOOSMALL: return "a provided buffer is too small";
    case LIBMCDRIVER_SCANLAB_ERROR_GENERICEXCEPTION: return "a generic exception occurred";
    case LIBMCDRIVER_SCANLAB_ERROR_COULDNOTLOADLIBRARY: return "the library could not be loaded";
    case LIBMCDRIVER_SCANLAB_ERROR_COULDNOTFINDLIBRARYEXPORT: return "a required exported symbol could not be found in the library";
    case LIBMCDRIVER_SCANLAB_ERROR_INCOMPATIBLEBINARYVERSION: return "the version of the binary interface does not match the bindings interface";
    case LIBMCDRIVER_SCANLAB_ERROR_INVALIDSTATENAME: return "invalid state name";
    case LIBMCDRIVER_SCANLAB_ERROR_DRIVERERROR: return "a driver error occured";
    case LIBMCDRIVER_SCANLAB_ERROR_RTC6_NO_PCIE_CARD_FOUND: return "RTC6: No PCIE Card was found";
    case LIBMCDRIVER_SCANLAB_ERROR_RTC6_ACCESS_DENIED: return "RTC6: Access Denied";
    case LIBMCDRIVER_SCANLAB_ERROR_RTC6_SEND_ERROR: return "RTC6: Send Error";
    case LIBMCDRIVER_SCANLAB_ERROR_RTC6_TIMEOUT: return "RTC6: Timeout";
    case LIBMCDRIVER_SCANLAB_ERROR_RTC6_PARAM_ERROR: return "RTC6: Param Error";
    case LIBMCDRIVER_SCANLAB_ERROR_RTC6_BUSY: return "RTC6: Busy";
    case LIBMCDRIVER_SCANLAB_ERROR_RTC6_REJECTED: return "RTC6: Rejected";
    case LIBMCDRIVER_SCANLAB_ERROR_RTC6_IGNORED: return "RTC6: Ignored";
    case LIBMCDRIVER_SCANLAB_ERROR_RTC6_VERSION_MISMATCH: return "RTC6: Version Mismatch";
    case LIBMCDRIVER_SCANLAB_ERROR_RTC6_VERIFY_ERROR: return "RTC6: Verify Error";
    case LIBMCDRIVER_SCANLAB_ERROR_RTC6_TYPE_REJECTED: return "RTC6: Type Rejected";
    case LIBMCDRIVER_SCANLAB_ERROR_RTC6_OUT_OF_MEMORY: return "RTC6: Out of Memory";
    case LIBMCDRIVER_SCANLAB_ERROR_RTC6_FLASH_ERROR: return "RTC6: Flash Error";
    case LIBMCDRIVER_SCANLAB_ERROR_RTC6_ETH_ERROR: return "RTC6: Eth Error";
    case LIBMCDRIVER_SCANLAB_ERROR_RTC6_CONFIG_ERROR: return "RTC6: Config Error";
    case LIBMCDRIVER_SCANLAB_ERROR_RTC6_UNKNOWN_ERROR: return "RTC6: Unknown Error";
    case LIBMCDRIVER_SCANLAB_ERROR_RTCOPEN_FAILED: return "RTC open failed";
    case LIBMCDRIVER_SCANLAB_ERROR_INVALIDRTCPROC: return "Invalid RTC proc";
    case LIBMCDRIVER_SCANLAB_ERROR_INVALIDIPADDRESS: return "Invalid IP Address";
    case LIBMCDRIVER_SCANLAB_ERROR_INVALIDNETMASK: return "Invalid NetMask";
    case LIBMCDRIVER_SCANLAB_ERROR_CARDALREADYACQUIRED: return "Card already acquired";
    case LIBMCDRIVER_SCANLAB_ERROR_CARDNOTFOUND: return "Card not found";
    case LIBMCDRIVER_SCANLAB_ERROR_COULDNOTLOADPROGRAMFILE: return "Could not load program file";
    case LIBMCDRIVER_SCANLAB_ERROR_COULDNOTLOADCORRECTIONFILE: return "Could not load correction file";
    case LIBMCDRIVER_SCANLAB_ERROR_DELAYSMUSTBEMULTIPLEOF10: return "Delays must be a multiple of 10 microseconds";
    case LIBMCDRIVER_SCANLAB_ERROR_SCANLABSDKNOTLOADED: return "Scanlab RTC has not been loaded";
    case LIBMCDRIVER_SCANLAB_ERROR_SCANLABSDKALREADYLOADED: return "Scanlab RTC has already been loaded";
    case LIBMCDRIVER_SCANLAB_ERROR_CARDALREADYINITIALIZED: return "Scanlab RTC card is already initialized";
    case LIBMCDRIVER_SCANLAB_ERROR_CARDNOTINITIALIZED: return "Scanlab RTC card is not initialized";
    case LIBMCDRIVER_SCANLAB_ERROR_INVALIDPOINTCOUNT: return "Invalid point count";
    case LIBMCDRIVER_SCANLAB_ERROR_INVALIDMAXLASERPOWER: return "Invalid max laser power.";
    case LIBMCDRIVER_SCANLAB_ERROR_INVALIDLASERDELAY: return "Invalid laser delay.";
    case LIBMCDRIVER_SCANLAB_ERROR_INVALIDSCANNERDELAY: return "Invalid scanner delay.";
    default: return "unknown error";
  }
}

/*************************************************************************************************************************
 Declaration of handle classes 
**************************************************************************************************************************/

typedef LibMCDriver_ScanLabHandle LibMCDriver_ScanLab_Base;
typedef LibMCDriver_ScanLabHandle LibMCDriver_ScanLab_Driver;
typedef LibMCDriver_ScanLabHandle LibMCDriver_ScanLab_RTCContext;
typedef LibMCDriver_ScanLabHandle LibMCDriver_ScanLab_RTCSelector;
typedef LibMCDriver_ScanLabHandle LibMCDriver_ScanLab_Driver_ScanLab;
typedef LibMCDriver_ScanLabHandle LibMCDriver_ScanLab_Driver_ScanLab_RTC6;

namespace LibMCDriver_ScanLab {

  /*************************************************************************************************************************
   Declaration of enums
  **************************************************************************************************************************/
  
  enum class eLaserMode : LibMCDriver_ScanLab_int32 {
    CO2 = 0,
    YAG1 = 1,
    YAG2 = 2,
    YAG3 = 3,
    LaserMode4 = 4,
    YAG5 = 5,
    LaserMode6 = 6
  };
  
  enum class eLaserPort : LibMCDriver_ScanLab_int32 {
    Port8bitDigital = 1,
    Port16bitDigital = 2,
    Port12BitAnalog1 = 3,
    Port12BitAnalog2 = 4
  };
  
  /*************************************************************************************************************************
   Declaration of structs
  **************************************************************************************************************************/
  
  #pragma pack (1)
  
  typedef struct {
      LibMCDriver_ScanLab_single m_X;
      LibMCDriver_ScanLab_single m_Y;
  } sPoint2D;
  
  typedef struct {
      LibMCDriver_ScanLab_single m_X1;
      LibMCDriver_ScanLab_single m_Y1;
      LibMCDriver_ScanLab_single m_X2;
      LibMCDriver_ScanLab_single m_Y2;
  } sHatch2D;
  
  #pragma pack ()
  
} // namespace LibMCDriver_ScanLab;

// define legacy C-names for enums, structs and function types
typedef LibMCDriver_ScanLab::eLaserMode eLibMCDriver_ScanLabLaserMode;
typedef LibMCDriver_ScanLab::eLaserPort eLibMCDriver_ScanLabLaserPort;
typedef LibMCDriver_ScanLab::sPoint2D sLibMCDriver_ScanLabPoint2D;
typedef LibMCDriver_ScanLab::sHatch2D sLibMCDriver_ScanLabHatch2D;

#endif // __LIBMCDRIVER_SCANLAB_TYPES_HEADER_CPP
