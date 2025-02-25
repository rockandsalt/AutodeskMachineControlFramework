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
order to allow an easy use of MC Driver S7Net 2.0

Interface version: 1.0.0

*/

#ifndef __LIBMCDRIVER_S7NET_TYPES_HEADER_CPP
#define __LIBMCDRIVER_S7NET_TYPES_HEADER_CPP


/*************************************************************************************************************************
 Scalar types definition
**************************************************************************************************************************/

#ifdef LIBMCDRIVER_S7NET_USELEGACYINTEGERTYPES

typedef unsigned char LibMCDriver_S7Net_uint8;
typedef unsigned short LibMCDriver_S7Net_uint16 ;
typedef unsigned int LibMCDriver_S7Net_uint32;
typedef unsigned long long LibMCDriver_S7Net_uint64;
typedef char LibMCDriver_S7Net_int8;
typedef short LibMCDriver_S7Net_int16;
typedef int LibMCDriver_S7Net_int32;
typedef long long LibMCDriver_S7Net_int64;

#else // LIBMCDRIVER_S7NET_USELEGACYINTEGERTYPES

#include <stdint.h>

typedef uint8_t LibMCDriver_S7Net_uint8;
typedef uint16_t LibMCDriver_S7Net_uint16;
typedef uint32_t LibMCDriver_S7Net_uint32;
typedef uint64_t LibMCDriver_S7Net_uint64;
typedef int8_t LibMCDriver_S7Net_int8;
typedef int16_t LibMCDriver_S7Net_int16;
typedef int32_t LibMCDriver_S7Net_int32;
typedef int64_t LibMCDriver_S7Net_int64 ;

#endif // LIBMCDRIVER_S7NET_USELEGACYINTEGERTYPES

typedef float LibMCDriver_S7Net_single;
typedef double LibMCDriver_S7Net_double;

/*************************************************************************************************************************
 General type definitions
**************************************************************************************************************************/

typedef LibMCDriver_S7Net_int32 LibMCDriver_S7NetResult;
typedef void * LibMCDriver_S7NetHandle;
typedef void * LibMCDriver_S7Net_pvoid;

/*************************************************************************************************************************
 Version for LibMCDriver_S7Net
**************************************************************************************************************************/

#define LIBMCDRIVER_S7NET_VERSION_MAJOR 1
#define LIBMCDRIVER_S7NET_VERSION_MINOR 0
#define LIBMCDRIVER_S7NET_VERSION_MICRO 0
#define LIBMCDRIVER_S7NET_VERSION_PRERELEASEINFO ""
#define LIBMCDRIVER_S7NET_VERSION_BUILDINFO ""

/*************************************************************************************************************************
 Error constants for LibMCDriver_S7Net
**************************************************************************************************************************/

#define LIBMCDRIVER_S7NET_SUCCESS 0
#define LIBMCDRIVER_S7NET_ERROR_NOTIMPLEMENTED 1
#define LIBMCDRIVER_S7NET_ERROR_INVALIDPARAM 2
#define LIBMCDRIVER_S7NET_ERROR_INVALIDCAST 3
#define LIBMCDRIVER_S7NET_ERROR_BUFFERTOOSMALL 4
#define LIBMCDRIVER_S7NET_ERROR_GENERICEXCEPTION 5
#define LIBMCDRIVER_S7NET_ERROR_COULDNOTLOADLIBRARY 6
#define LIBMCDRIVER_S7NET_ERROR_COULDNOTFINDLIBRARYEXPORT 7
#define LIBMCDRIVER_S7NET_ERROR_INCOMPATIBLEBINARYVERSION 8
#define LIBMCDRIVER_S7NET_ERROR_INVALIDSTATENAME 9
#define LIBMCDRIVER_S7NET_ERROR_DRIVERERROR 1000
#define LIBMCDRIVER_S7NET_ERROR_DRIVERNOTINITIALISED 1001
#define LIBMCDRIVER_S7NET_ERROR_DRIVERNOTCONNECTED 1002
#define LIBMCDRIVER_S7NET_ERROR_INVALIDDRIVERPROTOCOL 1003
#define LIBMCDRIVER_S7NET_ERROR_COULDNOTPARSEDRIVERPROTOCOL 1004
#define LIBMCDRIVER_S7NET_ERROR_NOSTATUSDBDEFINITION 1005
#define LIBMCDRIVER_S7NET_ERROR_NOSTATUSDBNUMBER 1006
#define LIBMCDRIVER_S7NET_ERROR_INVALIDSTATUSDBNUMBER 1007
#define LIBMCDRIVER_S7NET_ERROR_NOSTATUSDBSIZE 1008
#define LIBMCDRIVER_S7NET_ERROR_INVALIDSTATUSDBSIZE 1009
#define LIBMCDRIVER_S7NET_ERROR_NONAMEATTRIBUTE 1010
#define LIBMCDRIVER_S7NET_ERROR_NOADDRESSEATTRIBUTE 1011
#define LIBMCDRIVER_S7NET_ERROR_NODESCRIPTIONATTRIBUTE 1012
#define LIBMCDRIVER_S7NET_ERROR_NOBITATTRIBUTE 1013
#define LIBMCDRIVER_S7NET_ERROR_INVALIDNAMEATTRIBUTE 1014
#define LIBMCDRIVER_S7NET_ERROR_INVALIDADDRESSEATTRIBUTE 1015
#define LIBMCDRIVER_S7NET_ERROR_INVALIDDESCRIPTIONATTRIBUTE 1016
#define LIBMCDRIVER_S7NET_ERROR_INVALIDBITATTRIBUTE 1017
#define LIBMCDRIVER_S7NET_ERROR_INVALIDCPUTYPE 1018
#define LIBMCDRIVER_S7NET_ERROR_NOCONTROLDBDEFINITION 1019
#define LIBMCDRIVER_S7NET_ERROR_NOCONTROLDBNUMBER 1020
#define LIBMCDRIVER_S7NET_ERROR_INVALIDCONTROLDBNUMBER 1021
#define LIBMCDRIVER_S7NET_ERROR_UNKNOWNCOMMANDNAME 1022
#define LIBMCDRIVER_S7NET_ERROR_NOCOMMANDNAME 1023
#define LIBMCDRIVER_S7NET_ERROR_NOCOMMANDID 1024
#define LIBMCDRIVER_S7NET_ERROR_INVALIDCOMMANDNAME 1025
#define LIBMCDRIVER_S7NET_ERROR_INVALIDCOMMANDID 1026
#define LIBMCDRIVER_S7NET_ERROR_COMMANDHASALREADYBEENEXECUTED 1027
#define LIBMCDRIVER_S7NET_ERROR_COMMANDHASNOTBEENEXECUTED 1028
#define LIBMCDRIVER_S7NET_ERROR_INVALIDSEQUENCEID 1029
#define LIBMCDRIVER_S7NET_ERROR_COMMANDSEQUENCEERROR 1030
#define LIBMCDRIVER_S7NET_ERROR_COMMANDREACTIONTIMEOUT 1031
#define LIBMCDRIVER_S7NET_ERROR_NOCOMMANDSDEFINITION 1032
#define LIBMCDRIVER_S7NET_ERROR_NOVERSIONDEFINITION 1033
#define LIBMCDRIVER_S7NET_ERROR_NOMAJORVERSION 1034
#define LIBMCDRIVER_S7NET_ERROR_NOMINORVERSION 1035
#define LIBMCDRIVER_S7NET_ERROR_NOPATCHVERSION 1036
#define LIBMCDRIVER_S7NET_ERROR_NOCONTROLDBSIZE 1037
#define LIBMCDRIVER_S7NET_ERROR_INVALIDCONTROLDBSIZE 1038
#define LIBMCDRIVER_S7NET_ERROR_COULDNOTFINDADDRESS 1039
#define LIBMCDRIVER_S7NET_ERROR_FIELDISNOINTPARAM 1040
#define LIBMCDRIVER_S7NET_ERROR_FIELDISNODINTPARAM 1041
#define LIBMCDRIVER_S7NET_ERROR_FIELDISNOSTRINGPARAM 1042
#define LIBMCDRIVER_S7NET_ERROR_NOLENGTHATTRIBUTE 1043
#define LIBMCDRIVER_S7NET_ERROR_INVALIDLENGTHATTRIBUTE 1044
#define LIBMCDRIVER_S7NET_ERROR_COMMANDPARAMETERNAMEMISSING 1045
#define LIBMCDRIVER_S7NET_ERROR_COMMANDPARAMETERDESCRIPTIONMISSING 1046
#define LIBMCDRIVER_S7NET_ERROR_COMMANDPARAMETERFIELDMISSING 1047
#define LIBMCDRIVER_S7NET_ERROR_COMMANDPARAMETERNOTFOUND 1048
#define LIBMCDRIVER_S7NET_ERROR_COMMANDFIELDNOTFOUND 1049
#define LIBMCDRIVER_S7NET_ERROR_INVALIDPARAMETERTYPE 1050
#define LIBMCDRIVER_S7NET_ERROR_COMMANDPARAMETEROUTOFBOUNDS 1051

/*************************************************************************************************************************
 Error strings for LibMCDriver_S7Net
**************************************************************************************************************************/

inline const char * LIBMCDRIVER_S7NET_GETERRORSTRING (LibMCDriver_S7NetResult nErrorCode) {
  switch (nErrorCode) {
    case LIBMCDRIVER_S7NET_SUCCESS: return "no error";
    case LIBMCDRIVER_S7NET_ERROR_NOTIMPLEMENTED: return "functionality not implemented";
    case LIBMCDRIVER_S7NET_ERROR_INVALIDPARAM: return "an invalid parameter was passed";
    case LIBMCDRIVER_S7NET_ERROR_INVALIDCAST: return "a type cast failed";
    case LIBMCDRIVER_S7NET_ERROR_BUFFERTOOSMALL: return "a provided buffer is too small";
    case LIBMCDRIVER_S7NET_ERROR_GENERICEXCEPTION: return "a generic exception occurred";
    case LIBMCDRIVER_S7NET_ERROR_COULDNOTLOADLIBRARY: return "the library could not be loaded";
    case LIBMCDRIVER_S7NET_ERROR_COULDNOTFINDLIBRARYEXPORT: return "a required exported symbol could not be found in the library";
    case LIBMCDRIVER_S7NET_ERROR_INCOMPATIBLEBINARYVERSION: return "the version of the binary interface does not match the bindings interface";
    case LIBMCDRIVER_S7NET_ERROR_INVALIDSTATENAME: return "invalid state name";
    case LIBMCDRIVER_S7NET_ERROR_DRIVERERROR: return "a driver error occured";
    case LIBMCDRIVER_S7NET_ERROR_DRIVERNOTINITIALISED: return "the driver is not initialised";
    case LIBMCDRIVER_S7NET_ERROR_DRIVERNOTCONNECTED: return "the driver is not connected";
    case LIBMCDRIVER_S7NET_ERROR_INVALIDDRIVERPROTOCOL: return "invalid driver protocol definition";
    case LIBMCDRIVER_S7NET_ERROR_COULDNOTPARSEDRIVERPROTOCOL: return "could not parse driver protocol";
    case LIBMCDRIVER_S7NET_ERROR_NOSTATUSDBDEFINITION: return "no status db definition";
    case LIBMCDRIVER_S7NET_ERROR_NOSTATUSDBNUMBER: return "no status db number";
    case LIBMCDRIVER_S7NET_ERROR_INVALIDSTATUSDBNUMBER: return "invalid status db number";
    case LIBMCDRIVER_S7NET_ERROR_NOSTATUSDBSIZE: return "no status db size";
    case LIBMCDRIVER_S7NET_ERROR_INVALIDSTATUSDBSIZE: return "invalid status db size";
    case LIBMCDRIVER_S7NET_ERROR_NONAMEATTRIBUTE: return "no name attribute";
    case LIBMCDRIVER_S7NET_ERROR_NOADDRESSEATTRIBUTE: return "no address attribute";
    case LIBMCDRIVER_S7NET_ERROR_NODESCRIPTIONATTRIBUTE: return "no description attribute";
    case LIBMCDRIVER_S7NET_ERROR_NOBITATTRIBUTE: return "no bit attribute";
    case LIBMCDRIVER_S7NET_ERROR_INVALIDNAMEATTRIBUTE: return "invalid name attribute";
    case LIBMCDRIVER_S7NET_ERROR_INVALIDADDRESSEATTRIBUTE: return "invalid address attribute";
    case LIBMCDRIVER_S7NET_ERROR_INVALIDDESCRIPTIONATTRIBUTE: return "invalid description attribute";
    case LIBMCDRIVER_S7NET_ERROR_INVALIDBITATTRIBUTE: return "invalid bit attribute";
    case LIBMCDRIVER_S7NET_ERROR_INVALIDCPUTYPE: return "invalid cpu type";
    case LIBMCDRIVER_S7NET_ERROR_NOCONTROLDBDEFINITION: return "no control db definition";
    case LIBMCDRIVER_S7NET_ERROR_NOCONTROLDBNUMBER: return "no control db number";
    case LIBMCDRIVER_S7NET_ERROR_INVALIDCONTROLDBNUMBER: return "invalid control db number";
    case LIBMCDRIVER_S7NET_ERROR_UNKNOWNCOMMANDNAME: return "unknown command name";
    case LIBMCDRIVER_S7NET_ERROR_NOCOMMANDNAME: return "no command name";
    case LIBMCDRIVER_S7NET_ERROR_NOCOMMANDID: return "no command id";
    case LIBMCDRIVER_S7NET_ERROR_INVALIDCOMMANDNAME: return "invalid command name";
    case LIBMCDRIVER_S7NET_ERROR_INVALIDCOMMANDID: return "invalid command id";
    case LIBMCDRIVER_S7NET_ERROR_COMMANDHASALREADYBEENEXECUTED: return "command has already been executed";
    case LIBMCDRIVER_S7NET_ERROR_COMMANDHASNOTBEENEXECUTED: return "command has not been executed";
    case LIBMCDRIVER_S7NET_ERROR_INVALIDSEQUENCEID: return "invalid sequence id";
    case LIBMCDRIVER_S7NET_ERROR_COMMANDSEQUENCEERROR: return "command sequence communication error";
    case LIBMCDRIVER_S7NET_ERROR_COMMANDREACTIONTIMEOUT: return "command reaction timeout";
    case LIBMCDRIVER_S7NET_ERROR_NOCOMMANDSDEFINITION: return "no commands definition";
    case LIBMCDRIVER_S7NET_ERROR_NOVERSIONDEFINITION: return "no version definition";
    case LIBMCDRIVER_S7NET_ERROR_NOMAJORVERSION: return "no major version";
    case LIBMCDRIVER_S7NET_ERROR_NOMINORVERSION: return "no minor version";
    case LIBMCDRIVER_S7NET_ERROR_NOPATCHVERSION: return "no patch version";
    case LIBMCDRIVER_S7NET_ERROR_NOCONTROLDBSIZE: return "no control db size";
    case LIBMCDRIVER_S7NET_ERROR_INVALIDCONTROLDBSIZE: return "invalid control db size";
    case LIBMCDRIVER_S7NET_ERROR_COULDNOTFINDADDRESS: return "could not find address";
    case LIBMCDRIVER_S7NET_ERROR_FIELDISNOINTPARAM: return "field is no int parameter";
    case LIBMCDRIVER_S7NET_ERROR_FIELDISNODINTPARAM: return "field is no dint parameter";
    case LIBMCDRIVER_S7NET_ERROR_FIELDISNOSTRINGPARAM: return "field is no string parameter";
    case LIBMCDRIVER_S7NET_ERROR_NOLENGTHATTRIBUTE: return "no length attribute";
    case LIBMCDRIVER_S7NET_ERROR_INVALIDLENGTHATTRIBUTE: return "invalid length attribute";
    case LIBMCDRIVER_S7NET_ERROR_COMMANDPARAMETERNAMEMISSING: return "command parameter name missing";
    case LIBMCDRIVER_S7NET_ERROR_COMMANDPARAMETERDESCRIPTIONMISSING: return "command parameter description missing";
    case LIBMCDRIVER_S7NET_ERROR_COMMANDPARAMETERFIELDMISSING: return "command parameter field missing";
    case LIBMCDRIVER_S7NET_ERROR_COMMANDPARAMETERNOTFOUND: return "command parameter not found";
    case LIBMCDRIVER_S7NET_ERROR_COMMANDFIELDNOTFOUND: return "command field not found";
    case LIBMCDRIVER_S7NET_ERROR_INVALIDPARAMETERTYPE: return "command field parameter is of wrong type";
    case LIBMCDRIVER_S7NET_ERROR_COMMANDPARAMETEROUTOFBOUNDS: return "command field parameter is out of bounds";
    default: return "unknown error";
  }
}

/*************************************************************************************************************************
 Declaration of handle classes 
**************************************************************************************************************************/

typedef LibMCDriver_S7NetHandle LibMCDriver_S7Net_Base;
typedef LibMCDriver_S7NetHandle LibMCDriver_S7Net_Driver;
typedef LibMCDriver_S7NetHandle LibMCDriver_S7Net_PLCCommand;
typedef LibMCDriver_S7NetHandle LibMCDriver_S7Net_Driver_S7Net;

namespace LibMCDriver_S7Net {

  /*************************************************************************************************************************
   Declaration of enums
  **************************************************************************************************************************/
  
  enum class eS7CPUType : LibMCDriver_S7Net_int32 {
    S7200 = 0,
    S7300 = 10,
    S7400 = 20,
    S71200 = 30,
    S71500 = 40
  };
  
} // namespace LibMCDriver_S7Net;

// define legacy C-names for enums, structs and function types
typedef LibMCDriver_S7Net::eS7CPUType eLibMCDriver_S7NetS7CPUType;

#endif // __LIBMCDRIVER_S7NET_TYPES_HEADER_CPP
