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


Abstract: This is the class declaration of CUIEnvironment

*/


#ifndef __LIBMCENV_UIENVIRONMENT
#define __LIBMCENV_UIENVIRONMENT

#include "libmcenv_interfaces.hpp"
#include "amc_logger.hpp"
#include "amc_statemachinedata.hpp"
#include "amc_statesignalhandler.hpp"

// Parent classes
#include "libmcenv_base.hpp"
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4250)
#endif

// Include custom headers here.


namespace LibMCEnv {
namespace Impl {


/*************************************************************************************************************************
 Class declaration of CUIEnvironment 
**************************************************************************************************************************/

class CUIEnvironment : public virtual IUIEnvironment, public virtual CBase {
private:
	AMC::PLogger m_pLogger;
	AMC::PStateMachineData m_pStateMachineData;
	AMC::PParameterHandler m_pClientVariableHandler;
	AMC::PStateSignalHandler m_pSignalHandler;
	std::string m_sLogSubSystem;
	std::string m_sSenderUUID;


	std::string m_sContextUUID;
	std::map<std::pair <std::string, std::string>, std::string> m_FormValues;

protected:

public:

	CUIEnvironment(AMC::PLogger pLogger, AMC::PStateMachineData pStateMachineData, AMC::PStateSignalHandler pSignalHandler, const std::string& sSenderUUID, const std::string& sContextUUID, AMC::PParameterHandler pClientVariableHandler);

	ISignalTrigger * PrepareSignal(const std::string & sMachineInstance, const std::string & sSignalName) override;

	std::string GetMachineState(const std::string & sMachineInstance) override;

	void LogMessage(const std::string & sLogString) override;

	void LogWarning(const std::string & sLogString) override;

	void LogInfo(const std::string & sLogString) override;


	std::string GetMachineStringParameter(const std::string& sMachineInstance, const std::string& sParameterGroup, const std::string& sParameterName) override;

	std::string GetMachineUUIDParameter(const std::string& sMachineInstance, const std::string& sParameterGroup, const std::string& sParameterName) override;

	LibMCEnv_double GetMachineDoubleParameter(const std::string& sMachineInstance, const std::string& sParameterGroup, const std::string& sParameterName) override;

	LibMCEnv_int64 GetMachineIntegerParameter(const std::string& sMachineInstance, const std::string& sParameterGroup, const std::string& sParameterName) override;

	bool GetMachineBoolParameter(const std::string& sMachineInstance, const std::string& sParameterGroup, const std::string& sParameterName) override;


	std::string GetClientStringVariable(const std::string& sVariableGroup, const std::string& sVariableName) override;

	std::string GetClientUUIDVariable(const std::string& sVariableGroup, const std::string& sVariableName) override;

	LibMCEnv_double GetClientDoubleVariable(const std::string& sVariableGroup, const std::string& sVariableName) override;

	LibMCEnv_int64 GetClientIntegerVariable(const std::string& sVariableGroup, const std::string& sVariableName) override;

	bool GetClientBoolVariable(const std::string& sVariableGroup, const std::string& sVariableName) override;

	void SetClientStringVariable(const std::string& sVariableGroup, const std::string& sVariableName, const std::string& sValue) override;

	void SetClientUUIDVariable(const std::string& sVariableGroup, const std::string& sVariableName, const std::string& sValue) override;

	void SetClientDoubleVariable(const std::string& sVariableGroup, const std::string& sVariableName, const LibMCEnv_double dValue) override;

	void SetClientIntegerVariable(const std::string& sVariableGroup, const std::string& sVariableName, const LibMCEnv_int64 nValue) override;

	void SetClientBoolVariable(const std::string& sVariableGroup, const std::string& sVariableName, const bool bValue) override;

	bool HasFormValue(const std::string& sFormIdentifier, const std::string& sValueIdentifier) override;

	std::string GetFormStringValue(const std::string& sFormIdentifier, const std::string& sValueIdentifier) override;

	std::string GetFormUUIDValue(const std::string& sFormIdentifier, const std::string& sValueIdentifier) override;

	LibMCEnv_double GetFormDoubleValue(const std::string& sFormIdentifier, const std::string& sValueIdentifier) override;

	LibMCEnv_int64 GetFormIntegerValue(const std::string& sFormIdentifier, const std::string& sValueIdentifier) override;

	bool GetFormBoolValue(const std::string& sFormIdentifier, const std::string& sValueIdentifier) override;

	std::string GetEventContext() override;

	void addFormValue(const std::string& sFormIdentifier, const std::string & sValueIdentifier, const std::string & sValue);

};

} // namespace Impl
} // namespace LibMCEnv

#ifdef _MSC_VER
#pragma warning(pop)
#endif
#endif // __LIBMCENV_UIENVIRONMENT
