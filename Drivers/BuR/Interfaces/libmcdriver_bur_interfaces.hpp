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

Abstract: This is an autogenerated C++ header file in order to allow easy
development of MC Driver BR Automation 2.0. The implementer of MC Driver BR Automation 2.0 needs to
derive concrete classes from the abstract classes in this header.

Interface version: 1.0.0

*/


#ifndef __LIBMCDRIVER_BUR_CPPINTERFACES
#define __LIBMCDRIVER_BUR_CPPINTERFACES

#include <string>
#include <memory>

#include "libmcdriver_bur_types.hpp"


#include "libmcenv_dynamic.hpp"

namespace LibMCDriver_BuR {
namespace Impl {

/**
 Forward declarations of class interfaces
*/
class IBase;
class IDriver;
class IPLCCommand;
class IPLCCommandList;
class IDriver_BuR;



/*************************************************************************************************************************
 Parameter Cache definitions
**************************************************************************************************************************/

class ParameterCache {
	public:
		virtual ~ParameterCache() {}
};

template <class T1> class ParameterCache_1 : public ParameterCache {
	private:
		T1 m_param1;
	public:
		ParameterCache_1 (const T1 & param1)
			: m_param1 (param1)
		{
		}

		void retrieveData (T1 & param1)
		{
			param1 = m_param1;
		}
};

template <class T1, class T2> class ParameterCache_2 : public ParameterCache {
	private:
		T1 m_param1;
		T2 m_param2;
	public:
		ParameterCache_2 (const T1 & param1, const T2 & param2)
			: m_param1 (param1), m_param2 (param2)
		{
		}

		void retrieveData (T1 & param1, T2 & param2)
		{
			param1 = m_param1;
			param2 = m_param2;
		}
};

template <class T1, class T2, class T3> class ParameterCache_3 : public ParameterCache {
	private:
		T1 m_param1;
		T2 m_param2;
		T3 m_param3;
	public:
		ParameterCache_3 (const T1 & param1, const T2 & param2, const T3 & param3)
			: m_param1 (param1), m_param2 (param2), m_param3 (param3)
		{
		}

		void retrieveData (T1 & param1, T2 & param2, T3 & param3)
		{
			param1 = m_param1;
			param2 = m_param2;
			param3 = m_param3;
		}
};

template <class T1, class T2, class T3, class T4> class ParameterCache_4 : public ParameterCache {
	private:
		T1 m_param1;
		T2 m_param2;
		T3 m_param3;
		T4 m_param4;
	public:
		ParameterCache_4 (const T1 & param1, const T2 & param2, const T3 & param3, const T4 & param4)
			: m_param1 (param1), m_param2 (param2), m_param3 (param3), m_param4 (param4)
		{
		}

		void retrieveData (T1 & param1, T2 & param2, T3 & param3, T4 & param4)
		{
			param1 = m_param1;
			param2 = m_param2;
			param3 = m_param3;
			param4 = m_param4;
		}
};


/*************************************************************************************************************************
 Class interface for Base 
**************************************************************************************************************************/

class IBase {
private:
	std::unique_ptr<ParameterCache> m_ParameterCache;
public:
	/**
	* IBase::~IBase - virtual destructor of IBase
	*/
	virtual ~IBase() {};

	/**
	* IBase::ReleaseBaseClassInterface - Releases ownership of a base class interface. Deletes the reference, if necessary.
	* @param[in] pIBase - The base class instance to release
	*/
	static void ReleaseBaseClassInterface(IBase* pIBase)
	{
		if (pIBase) {
			pIBase->DecRefCount();
		}
	};

	/**
	* IBase::AcquireBaseClassInterface - Acquires shared ownership of a base class interface.
	* @param[in] pIBase - The base class instance to acquire
	*/
	static void AcquireBaseClassInterface(IBase* pIBase)
	{
		if (pIBase) {
			pIBase->IncRefCount();
		}
	};


	/**
	* IBase::GetLastErrorMessage - Returns the last error registered of this class instance
	* @param[out] sErrorMessage - Message of the last error registered
	* @return Has an error been registered already
	*/
	virtual bool GetLastErrorMessage(std::string & sErrorMessage) = 0;

	/**
	* IBase::ClearErrorMessages - Clears all registered messages of this class instance
	*/
	virtual void ClearErrorMessages() = 0;

	/**
	* IBase::RegisterErrorMessage - Registers an error message with this class instance
	* @param[in] sErrorMessage - Error message to register
	*/
	virtual void RegisterErrorMessage(const std::string & sErrorMessage) = 0;

	/**
	* IBase::IncRefCount - Increases the reference count of a class instance
	*/
	virtual void IncRefCount() = 0;

	/**
	* IBase::DecRefCount - Decreases the reference count of a class instance and free releases it, if the last reference has been removed
	* @return Has the object been released
	*/
	virtual bool DecRefCount() = 0;

	/**
	* IBase::_setCache - set parameter cache of object
	*/
	void _setCache(ParameterCache * pCache)
	{
		m_ParameterCache.reset(pCache);
	}

	/**
	* IBase::_getCache - returns parameter cache of object
	*/
	ParameterCache* _getCache()
	{
		return m_ParameterCache.get();
	}

};


/**
 Definition of a shared pointer class for IBase
*/
template<class T>
class IBaseSharedPtr : public std::shared_ptr<T>
{
public:
	explicit IBaseSharedPtr(T* t = nullptr)
		: std::shared_ptr<T>(t, IBase::ReleaseBaseClassInterface)
	{
		t->IncRefCount();
	}

	// Reset function, as it also needs to properly set the deleter.
	void reset(T* t = nullptr)
	{
		std::shared_ptr<T>::reset(t, IBase::ReleaseBaseClassInterface);
	}

	// Get-function that increases the Base class's reference count
	T* getCoOwningPtr()
	{
		T* t = this->get();
		t->IncRefCount();
		return t;
	}
};


typedef IBaseSharedPtr<IBase> PIBase;


/*************************************************************************************************************************
 Class interface for Driver 
**************************************************************************************************************************/

class IDriver : public virtual IBase {
public:
	/**
	* IDriver::Configure - Configures a driver with its specific configuration data.
	* @param[in] sConfigurationString - Configuration data of driver.
	*/
	virtual void Configure(const std::string & sConfigurationString) = 0;

	/**
	* IDriver::GetName - returns the name identifier of the driver
	* @return Name of the driver.
	*/
	virtual std::string GetName() = 0;

	/**
	* IDriver::GetType - returns the type identifier of the driver
	* @return Type of the driver.
	*/
	virtual std::string GetType() = 0;

	/**
	* IDriver::GetVersion - returns the version identifiers of the driver
	* @param[out] nMajor - Major version.
	* @param[out] nMinor - Minor version.
	* @param[out] nMicro - Micro version.
	* @param[out] sBuild - Build identifier.
	*/
	virtual void GetVersion(LibMCDriver_BuR_uint32 & nMajor, LibMCDriver_BuR_uint32 & nMinor, LibMCDriver_BuR_uint32 & nMicro, std::string & sBuild) = 0;

	/**
	* IDriver::GetHeaderInformation - returns the header information
	* @param[out] sNameSpace - NameSpace of the driver.
	* @param[out] sBaseName - BaseName of the driver.
	*/
	virtual void GetHeaderInformation(std::string & sNameSpace, std::string & sBaseName) = 0;

	/**
	* IDriver::QueryParameters - Stores the driver parameters in the driver environment.
	*/
	virtual void QueryParameters() = 0;

};

typedef IBaseSharedPtr<IDriver> PIDriver;


/*************************************************************************************************************************
 Class interface for PLCCommand 
**************************************************************************************************************************/

class IPLCCommand : public virtual IBase {
public:
	/**
	* IPLCCommand::SetIntegerParameter - Sets an integer parameter of the command
	* @param[in] sParameterName - Parameter Value
	* @param[in] nValue - Parameter Value
	*/
	virtual void SetIntegerParameter(const std::string & sParameterName, const LibMCDriver_BuR_int64 nValue) = 0;

	/**
	* IPLCCommand::SetBoolParameter - Sets a bool parameter of the command
	* @param[in] sParameterName - Parameter Value
	* @param[in] bValue - Parameter Value
	*/
	virtual void SetBoolParameter(const std::string & sParameterName, const bool bValue) = 0;

	/**
	* IPLCCommand::SetDoubleParameter - Sets a double parameter of the command
	* @param[in] sParameterName - Parameter Value
	* @param[in] dValue - Parameter Value
	*/
	virtual void SetDoubleParameter(const std::string & sParameterName, const LibMCDriver_BuR_double dValue) = 0;

};

typedef IBaseSharedPtr<IPLCCommand> PIPLCCommand;


/*************************************************************************************************************************
 Class interface for PLCCommandList 
**************************************************************************************************************************/

class IPLCCommandList : public virtual IBase {
public:
	/**
	* IPLCCommandList::AddCommand - Adds a command to the list. List must not be executed before.
	* @param[in] pCommandInstance - Add a command instance.
	*/
	virtual void AddCommand(IPLCCommand* pCommandInstance) = 0;

	/**
	* IPLCCommandList::FinishList - Finish command list.
	*/
	virtual void FinishList() = 0;

	/**
	* IPLCCommandList::ExecuteList - Execute command list.
	*/
	virtual void ExecuteList() = 0;

	/**
	* IPLCCommandList::WaitForList - Wait for command list to finish executing
	* @param[in] nReactionTimeInMS - How much time the PLC may need to react to the command in Milliseconds. Will fail if no reaction in that time.
	* @param[in] nWaitForTimeInMS - How long to wait for the command to be finished in Milliseconds. Will return false if command has not finished.
	* @return Returns true if the command was finished successfully.
	*/
	virtual bool WaitForList(const LibMCDriver_BuR_uint32 nReactionTimeInMS, const LibMCDriver_BuR_uint32 nWaitForTimeInMS) = 0;

	/**
	* IPLCCommandList::PauseList - Pause command list. Must be executed or resumed before.
	*/
	virtual void PauseList() = 0;

	/**
	* IPLCCommandList::ResumeList - Resume command list. Must be paused before.
	*/
	virtual void ResumeList() = 0;

};

typedef IBaseSharedPtr<IPLCCommandList> PIPLCCommandList;


/*************************************************************************************************************************
 Class interface for Driver_BuR 
**************************************************************************************************************************/

class IDriver_BuR : public virtual IDriver {
public:
	/**
	* IDriver_BuR::Connect - Connects to a BuR PLC Controller.
	* @param[in] sIPAddress - IP Address of PLC Service.
	* @param[in] nPort - Port of PLC Service.
	* @param[in] nTimeout - Timeout in milliseconds.
	*/
	virtual void Connect(const std::string & sIPAddress, const LibMCDriver_BuR_uint32 nPort, const LibMCDriver_BuR_uint32 nTimeout) = 0;

	/**
	* IDriver_BuR::Disconnect - Disconnects from the BuR PLC Controller.
	*/
	virtual void Disconnect() = 0;

	/**
	* IDriver_BuR::CreateCommandList - Create Command
	* @return Command list instance
	*/
	virtual IPLCCommandList * CreateCommandList() = 0;

	/**
	* IDriver_BuR::CreateCommand - Creates a command instance.
	* @param[in] sCommandName - Command Name.
	* @return Returns a command instance.
	*/
	virtual IPLCCommand * CreateCommand(const std::string & sCommandName) = 0;

	/**
	* IDriver_BuR::StartJournaling - Start Journaling.
	*/
	virtual void StartJournaling() = 0;

	/**
	* IDriver_BuR::StopJournaling - Stop Journaling.
	*/
	virtual void StopJournaling() = 0;

	/**
	* IDriver_BuR::RefreshJournal - Refresh Journal.
	*/
	virtual void RefreshJournal() = 0;

};

typedef IBaseSharedPtr<IDriver_BuR> PIDriver_BuR;


/*************************************************************************************************************************
 Global functions declarations
**************************************************************************************************************************/
class CWrapper {
public:
	// Injected Components
	static LibMCEnv::PWrapper sPLibMCEnvWrapper;

	/**
	* Ilibmcdriver_bur::GetVersion - retrieves the binary version of this library.
	* @param[out] nMajor - returns the major version of this library
	* @param[out] nMinor - returns the minor version of this library
	* @param[out] nMicro - returns the micro version of this library
	*/
	static void GetVersion(LibMCDriver_BuR_uint32 & nMajor, LibMCDriver_BuR_uint32 & nMinor, LibMCDriver_BuR_uint32 & nMicro);

	/**
	* Ilibmcdriver_bur::GetLastError - Returns the last error recorded on this object
	* @param[in] pInstance - Instance Handle
	* @param[out] sErrorMessage - Message of the last error
	* @return Is there a last error to query
	*/
	static bool GetLastError(IBase* pInstance, std::string & sErrorMessage);

	/**
	* Ilibmcdriver_bur::ReleaseInstance - Releases shared ownership of an Instance
	* @param[in] pInstance - Instance Handle
	*/
	static void ReleaseInstance(IBase* pInstance);

	/**
	* Ilibmcdriver_bur::AcquireInstance - Acquires shared ownership of an Instance
	* @param[in] pInstance - Instance Handle
	*/
	static void AcquireInstance(IBase* pInstance);

	/**
	* Ilibmcdriver_bur::CreateDriver - Creates a driver instance with a specific name.
	* @param[in] sName - Name of driver to be created.
	* @param[in] sType - Type of driver to be created.
	* @param[in] pDriverEnvironment - Environment of this driver.
	* @return New Driver instance
	*/
	static IDriver * CreateDriver(const std::string & sName, const std::string & sType, LibMCEnv::PDriverEnvironment pDriverEnvironment);

};

LibMCDriver_BuRResult LibMCDriver_BuR_GetProcAddress (const char * pProcName, void ** ppProcAddress);

} // namespace Impl
} // namespace LibMCDriver_BuR

#endif // __LIBMCDRIVER_BUR_CPPINTERFACES
