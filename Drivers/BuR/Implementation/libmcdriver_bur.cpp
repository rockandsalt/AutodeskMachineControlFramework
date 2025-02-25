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
development of MC Driver BR Automation 2.0. It needs to be generated only once.

Interface version: 1.0.0

*/

#include "libmcdriver_bur_abi.hpp"
#include "libmcdriver_bur_interfaces.hpp"
#include "libmcdriver_bur_interfaceexception.hpp"
#include "libmcdriver_bur_driver_bur.hpp"

using namespace LibMCDriver_BuR;
using namespace LibMCDriver_BuR::Impl;

// Injected Components
LibMCEnv::PWrapper CWrapper::sPLibMCEnvWrapper;

void CWrapper::GetVersion(LibMCDriver_BuR_uint32 & nMajor, LibMCDriver_BuR_uint32 & nMinor, LibMCDriver_BuR_uint32 & nMicro)
{
	nMajor = LIBMCDRIVER_BUR_VERSION_MAJOR;
	nMinor = LIBMCDRIVER_BUR_VERSION_MINOR;
	nMicro = LIBMCDRIVER_BUR_VERSION_MICRO;
}

bool CWrapper::GetLastError(IBase* pInstance, std::string & sErrorMessage)
{
	if (pInstance) {
		return pInstance->GetLastErrorMessage (sErrorMessage);
	} else {
		return false;
	}
}

void CWrapper::ReleaseInstance(IBase* pInstance)
{
	IBase::ReleaseBaseClassInterface(pInstance);
}

void CWrapper::AcquireInstance(IBase* pInstance)
{
	IBase::AcquireBaseClassInterface(pInstance);
}

IDriver * CWrapper::CreateDriver(const std::string & sName, const std::string & sType, LibMCEnv::PDriverEnvironment pDriverEnvironment)
{
	if (sType == "bur-1.0")
		return new CDriver_BuR(sName, pDriverEnvironment);

	throw ELibMCDriver_BuRInterfaceException(LIBMCDRIVER_BUR_ERROR_DRIVERERROR, "driver type not found: " + sType);
}


