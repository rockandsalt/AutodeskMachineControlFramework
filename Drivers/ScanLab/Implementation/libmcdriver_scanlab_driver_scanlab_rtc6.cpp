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

#include "libmcdriver_scanlab_driver_scanlab_rtc6.hpp"
#include "libmcdriver_scanlab_interfaceexception.hpp"

// Include custom headers here.
#define RTC6_MIN_MAXLASERPOWER 10.0f
#define RTC6_MAX_MAXLASERPOWER 10000.0f

using namespace LibMCDriver_ScanLab::Impl;

/*************************************************************************************************************************
 Class definition of CDriver_ScanLab_RTC6 
**************************************************************************************************************************/

CDriver_ScanLab_RTC6::CDriver_ScanLab_RTC6(const std::string& sName, const std::string& sType, LibMCEnv::PDriverEnvironment pDriverEnvironment)
	: CDriver_ScanLab (pDriverEnvironment), m_sName (sName), m_sType (sType), m_fMaxLaserPowerInWatts (0.0f)
{
}

void CDriver_ScanLab_RTC6::Configure(const std::string& sConfigurationString)
{
    m_pDriverEnvironment->RegisterBoolParameter("position_x_ok", "Scan Position X is ok", false);
    m_pDriverEnvironment->RegisterBoolParameter("position_y_ok", "Scan Position Y is ok", false);
    m_pDriverEnvironment->RegisterBoolParameter("temperature_ok", "Scan Head Temperature is ok", false);
    m_pDriverEnvironment->RegisterBoolParameter("power_ok", "Scan Head Power is ok", false);
    m_pDriverEnvironment->RegisterBoolParameter("laser_on", "Laser is On", false);
    m_pDriverEnvironment->RegisterIntegerParameter("position_x", "Laser Position X", 0);
    m_pDriverEnvironment->RegisterIntegerParameter("position_y", "Laser Position Y", 0);
    m_pDriverEnvironment->RegisterIntegerParameter("position_z", "Laser Position Z", 0);
    m_pDriverEnvironment->RegisterIntegerParameter("position_x_corrected", "corrected Laser Position X", 0);
    m_pDriverEnvironment->RegisterIntegerParameter("position_y_corrected", "corrected Laser Position Y", 0);
    m_pDriverEnvironment->RegisterIntegerParameter("position_z_corrected", "corrected Laser Position Z", 0);
    m_pDriverEnvironment->RegisterIntegerParameter("focus_shift", "current Focus Shift", 0);
    m_pDriverEnvironment->RegisterIntegerParameter("mark_speed", "current Mark Speed", 0);
    m_pDriverEnvironment->RegisterIntegerParameter("list_position", "current List Position", 0);
    m_pDriverEnvironment->RegisterBoolParameter("card_busy", "Card is busy", false);
    m_pDriverEnvironment->RegisterIntegerParameter("rtc_version", "Scanlab RTC Version", 0);
    m_pDriverEnvironment->RegisterIntegerParameter("card_type", "Scanlab RTC Type", 0);
    m_pDriverEnvironment->RegisterIntegerParameter("dll_version", "Scanlab DLL Version", 0);
    m_pDriverEnvironment->RegisterIntegerParameter("hex_version", "Scanlab HEX Version", 0);
    m_pDriverEnvironment->RegisterIntegerParameter("bios_version", "Scanlab BIOS Version", 0);
}

std::string CDriver_ScanLab_RTC6::GetName()
{
	return m_sName;
}

std::string CDriver_ScanLab_RTC6::GetType()
{
	return m_sType;
}


void CDriver_ScanLab_RTC6::QueryParameters()
{
    updateCardStatus();
}


void CDriver_ScanLab_RTC6::Initialise(const std::string& sIP, const std::string& sNetmask, const LibMCDriver_ScanLab_uint32 nTimeout, const LibMCDriver_ScanLab_uint32 nSerialNumber)
{
	if (m_pRTCSelector.get() != nullptr)
		throw ELibMCDriver_ScanLabInterfaceException(LIBMCDRIVER_SCANLAB_ERROR_CARDALREADYINITIALIZED);

	m_pRTCContext = nullptr;

	m_pRTCSelector = std::shared_ptr<IRTCSelector> (CreateRTCSelector());

	if (sIP.empty ()) {
		m_pRTCContext = std::shared_ptr<IRTCContext> (m_pRTCSelector->AcquireCardBySerial(nSerialNumber));
	}
	else {
		m_pRTCSelector->SearchCards(sIP, sNetmask, nTimeout);
		m_pRTCContext = std::shared_ptr<IRTCContext>(m_pRTCSelector->AcquireEthernetCardBySerial(nSerialNumber));
	}

    uint32_t nRTCVersion = 0;
    uint32_t nRTCType = 0;
    uint32_t nDLLVersion = 0;
    uint32_t nHEXVersion = 0;
    uint32_t nBIOSVersion = 0;
    m_pRTCContext->GetRTCVersion(nRTCVersion, nRTCType, nDLLVersion, nHEXVersion, nBIOSVersion);
    m_pDriverEnvironment->SetIntegerParameter("rtc_version", nRTCVersion);
    m_pDriverEnvironment->SetIntegerParameter("card_type", nRTCType);
    m_pDriverEnvironment->SetIntegerParameter("dll_version", nDLLVersion);
    m_pDriverEnvironment->SetIntegerParameter("hex_version", nHEXVersion);
    m_pDriverEnvironment->SetIntegerParameter("bios_version", nBIOSVersion);

}

void CDriver_ScanLab_RTC6::LoadFirmware(const std::string& sFirmwareResource, const std::string& sFPGAResource, const std::string& sAuxiliaryResource)
{
	if (m_pRTCContext.get() == nullptr)
		throw ELibMCDriver_ScanLabInterfaceException(LIBMCDRIVER_SCANLAB_ERROR_CARDNOTINITIALIZED);

	m_pRTCContext->LoadFirmware(sFirmwareResource, sFPGAResource, sAuxiliaryResource);

}

void CDriver_ScanLab_RTC6::SetCorrectionFile(const LibMCDriver_ScanLab_uint64 nCorrectionFileBufferSize, const LibMCDriver_ScanLab_uint8* pCorrectionFileBuffer, const LibMCDriver_ScanLab_uint32 nTableNumber, const LibMCDriver_ScanLab_uint32 nDimension, const LibMCDriver_ScanLab_uint32 nTableNumberHeadA, const LibMCDriver_ScanLab_uint32 nTableNumberHeadB) 
{
	if (m_pRTCContext.get() == nullptr)
		throw ELibMCDriver_ScanLabInterfaceException(LIBMCDRIVER_SCANLAB_ERROR_CARDNOTINITIALIZED);

	m_pRTCContext->LoadCorrectionFile (nCorrectionFileBufferSize, pCorrectionFileBuffer, nTableNumber, nDimension);
    m_pRTCContext->SelectCorrectionTable(nTableNumberHeadA, nTableNumberHeadB);

}

void CDriver_ScanLab_RTC6::ConfigureLaserMode(const LibMCDriver_ScanLab::eLaserMode eLaserMode, const LibMCDriver_ScanLab::eLaserPort eLaserPort, const LibMCDriver_ScanLab_double dMaxLaserPower, const bool bFinishLaserPulseAfterOn, const bool bPhaseShiftOfLaserSignal, const bool bLaserOnSignalLowActive, const bool bLaserHalfSignalsLowActive, const bool bSetDigitalInOneHighActive, const bool bOutputSynchronizationActive) 
{

    if (m_pRTCContext.get() == nullptr)
        throw ELibMCDriver_ScanLabInterfaceException(LIBMCDRIVER_SCANLAB_ERROR_CARDNOTINITIALIZED);

    if (((float)dMaxLaserPower < RTC6_MIN_MAXLASERPOWER) || ((float)dMaxLaserPower > RTC6_MAX_MAXLASERPOWER))
        throw ELibMCDriver_ScanLabInterfaceException(LIBMCDRIVER_SCANLAB_ERROR_INVALIDMAXLASERPOWER);

    m_fMaxLaserPowerInWatts = (float)dMaxLaserPower;

    m_pRTCContext->ConfigureLists(1 << 22, 1 << 22);
    m_pRTCContext->SetLaserMode(eLaserMode, eLaserPort);
    m_pRTCContext->DisableAutoLaserControl ();
    m_pRTCContext->SetLaserControlParameters(false, bFinishLaserPulseAfterOn, bPhaseShiftOfLaserSignal, bLaserOnSignalLowActive, bLaserHalfSignalsLowActive, bSetDigitalInOneHighActive, bOutputSynchronizationActive); 
    m_pRTCContext->SetLaserPulsesInMicroSeconds(5, 5);
    m_pRTCContext->SetStandbyInMicroSeconds(1, 1);
}

void CDriver_ScanLab_RTC6::ConfigureDelays(const LibMCDriver_ScanLab_double dLaserOnDelay, const LibMCDriver_ScanLab_double dLaserOffDelay, const LibMCDriver_ScanLab_double dMarkDelay, const LibMCDriver_ScanLab_double dJumpDelay, const LibMCDriver_ScanLab_double dPolygonDelay)
{
    if (m_pRTCContext.get() == nullptr)
        throw ELibMCDriver_ScanLabInterfaceException(LIBMCDRIVER_SCANLAB_ERROR_CARDNOTINITIALIZED);

    if ((dLaserOnDelay < 0.0) || (dLaserOnDelay > 10000000.0))
        throw ELibMCDriver_ScanLabInterfaceException(LIBMCDRIVER_SCANLAB_ERROR_INVALIDLASERDELAY);
    if ((dLaserOffDelay < 0.0) || (dLaserOffDelay > 10000000.0))
        throw ELibMCDriver_ScanLabInterfaceException(LIBMCDRIVER_SCANLAB_ERROR_INVALIDLASERDELAY);
    if ((dMarkDelay < 0.0) || (dMarkDelay > 10000000.0))
        throw ELibMCDriver_ScanLabInterfaceException(LIBMCDRIVER_SCANLAB_ERROR_INVALIDSCANNERDELAY);
    if ((dJumpDelay < 0.0) || (dJumpDelay > 10000000.0))
        throw ELibMCDriver_ScanLabInterfaceException(LIBMCDRIVER_SCANLAB_ERROR_INVALIDSCANNERDELAY);
    if ((dPolygonDelay < 0.0) || (dPolygonDelay > 10000000.0))
        throw ELibMCDriver_ScanLabInterfaceException(LIBMCDRIVER_SCANLAB_ERROR_INVALIDSCANNERDELAY);


    int nIntMarkDelay = ((int)round(dMarkDelay / 10.0)) * 10;
    int nIntJumpDelay = ((int)round(dJumpDelay / 10.0)) * 10;
    int nIntPolygonDelay = ((int)round(dPolygonDelay / 10.0)) * 10;

    if (nIntMarkDelay < 10)
        nIntMarkDelay = 10;
    if (nIntJumpDelay < 10)
        nIntJumpDelay = 10;
    if (nIntPolygonDelay < 10)
        nIntPolygonDelay = 10;

    m_pRTCContext->SetLaserDelaysInMicroseconds(dLaserOnDelay, dLaserOffDelay);
    m_pRTCContext->SetDelays(nIntMarkDelay, nIntJumpDelay, nIntPolygonDelay);

}


void CDriver_ScanLab_RTC6::DrawLayer(const std::string& sStreamUUID, const LibMCDriver_ScanLab_uint32 nLayerIndex)
{
    if (m_pRTCContext.get() == nullptr)
        throw ELibMCDriver_ScanLabInterfaceException(LIBMCDRIVER_SCANLAB_ERROR_CARDNOTINITIALIZED);
    if ((m_fMaxLaserPowerInWatts < RTC6_MIN_MAXLASERPOWER) || (m_fMaxLaserPowerInWatts > RTC6_MAX_MAXLASERPOWER))
        throw ELibMCDriver_ScanLabInterfaceException(LIBMCDRIVER_SCANLAB_ERROR_INVALIDMAXLASERPOWER);
    

    auto pToolpathAccessor = m_pDriverEnvironment->CreateToolpathAccessor(sStreamUUID);
    auto pLayer = pToolpathAccessor->LoadLayer(nLayerIndex);

    double dUnits = pToolpathAccessor->GetUnits();

    internalBegin();

    uint32_t nSegmentCount = pLayer->GetSegmentCount();
    for (uint32_t nSegmentIndex = 0; nSegmentIndex < nSegmentCount; nSegmentIndex++) {

        LibMCEnv::eToolpathSegmentType eSegmentType;
        uint32_t nPointCount;
        pLayer->GetSegmentInfo(nSegmentIndex, eSegmentType, nPointCount);

        if (nPointCount >= 2) {

            float fJumpSpeedInMMPerSecond = (float) pLayer->GetSegmentProfileTypedValue (nSegmentIndex, LibMCEnv::eToolpathProfileValueType::JumpSpeed);
            float fMarkSpeedInMMPerSecond = (float)pLayer->GetSegmentProfileTypedValue(nSegmentIndex, LibMCEnv::eToolpathProfileValueType::Speed);
            float fPowerInWatts = (float)pLayer->GetSegmentProfileTypedValue(nSegmentIndex, LibMCEnv::eToolpathProfileValueType::LaserPower);
            float fPowerInPercent = (fPowerInWatts * 100.f) / m_fMaxLaserPowerInWatts;
            float fLaserFocus = (float)pLayer->GetSegmentProfileTypedValue(nSegmentIndex, LibMCEnv::eToolpathProfileValueType::LaserFocus);

            std::vector<LibMCEnv::sPosition2D> Points;
            pLayer->GetSegmentPointData(nSegmentIndex, Points);

            if (nPointCount != Points.size())
                throw ELibMCDriver_ScanLabInterfaceException(LIBMCDRIVER_SCANLAB_ERROR_INVALIDPOINTCOUNT);

            switch (eSegmentType) {
            case LibMCEnv::eToolpathSegmentType::Loop:
            case LibMCEnv::eToolpathSegmentType::Polyline:
            {

                std::vector<sPoint2D> ContourPoints;
                ContourPoints.resize(nPointCount);
                
                for (uint32_t nPointIndex = 0; nPointIndex < nPointCount; nPointIndex++) {
                    auto pContourPoint = &ContourPoints.at(nPointIndex);
                    pContourPoint->m_X = (float) (Points[nPointIndex].m_Coordinates[0] * dUnits);
                    pContourPoint->m_Y = (float) (Points[nPointIndex].m_Coordinates[1] * dUnits);
                }

                m_pRTCContext->DrawPolyline(nPointCount, ContourPoints.data(), fMarkSpeedInMMPerSecond, fJumpSpeedInMMPerSecond, fPowerInPercent, fLaserFocus);

                break;
            }

            case LibMCEnv::eToolpathSegmentType::Hatch:
            {
                if (nPointCount % 2 == 1)
                    throw ELibMCDriver_ScanLabInterfaceException(LIBMCDRIVER_SCANLAB_ERROR_INVALIDPOINTCOUNT);

                uint64_t nHatchCount = nPointCount / 2;
                std::vector<sHatch2D> Hatches;
                Hatches.resize(nHatchCount);

                for (uint64_t nHatchIndex = 0; nHatchIndex < nHatchCount; nHatchIndex++) {
                    auto pHatch = &Hatches.at (nHatchIndex);
                    pHatch->m_X1 = (float)(Points[nHatchIndex * 2].m_Coordinates[0] * dUnits);
                    pHatch->m_Y1 = (float)(Points[nHatchIndex * 2].m_Coordinates[1] * dUnits);
                    pHatch->m_X2 = (float)(Points[nHatchIndex * 2 + 1].m_Coordinates[0] * dUnits);
                    pHatch->m_Y2 = (float)(Points[nHatchIndex * 2 + 1].m_Coordinates[1] * dUnits);
                }

                m_pRTCContext->DrawHatches (Hatches.size (), Hatches.data (), fMarkSpeedInMMPerSecond, fJumpSpeedInMMPerSecond, fPowerInPercent, fLaserFocus);

                break;
            }

            }

        }

    }

    internalExecute();


}


void CDriver_ScanLab_RTC6::internalBegin()
{
    if (m_pRTCContext.get() == nullptr)
        throw ELibMCDriver_ScanLabInterfaceException(LIBMCDRIVER_SCANLAB_ERROR_CARDNOTINITIALIZED);

    m_pRTCContext->SetStartList(1, 0);

}


void CDriver_ScanLab_RTC6::internalExecute()
{
    if (m_pRTCContext.get() == nullptr)
        throw ELibMCDriver_ScanLabInterfaceException(LIBMCDRIVER_SCANLAB_ERROR_CARDNOTINITIALIZED);

    m_pRTCContext->SetEndOfList();
    m_pRTCContext->ExecuteList(1, 0);

    bool Busy = true;
    uint32_t Pos = 0;

    while (Busy) {
        m_pRTCContext->GetStatus (Busy, Pos);
        m_pDriverEnvironment->Sleep(10);

        updateCardStatus();
    }

}

void CDriver_ScanLab_RTC6::updateCardStatus()
{
    bool Busy = true;
    uint32_t ListPosition = 0;
    bool bPositionXisOK, bPositionYisOK, bTemperatureisOK, bPowerisOK;

    m_pRTCContext->GetStatus(Busy, ListPosition);
    m_pRTCContext->GetHeadStatus(1, bPositionXisOK, bPositionYisOK, bTemperatureisOK, bPowerisOK);

    m_pDriverEnvironment->SetBoolParameter("position_x_ok", bPositionXisOK);
    m_pDriverEnvironment->SetBoolParameter("position_y_ok", bPositionYisOK);
    m_pDriverEnvironment->SetBoolParameter("temperature_ok", bTemperatureisOK);
    m_pDriverEnvironment->SetBoolParameter("power_ok", bPowerisOK);

    m_pDriverEnvironment->SetIntegerParameter("list_position", ListPosition);
    m_pDriverEnvironment->SetBoolParameter("card_busy", Busy);

    bool bLaserIsOn;
    uint32_t nPositionX, nPositionY, nPositionZ;
    uint32_t nCorrectedPositionX, nCorrectedPositionY, nCorrectedPositionZ;
    uint32_t nFocusShift, nMarkSpeed;

    m_pRTCContext->GetStateValues(bLaserIsOn, nPositionX, nPositionY, nPositionZ, nCorrectedPositionX, nCorrectedPositionY, nCorrectedPositionZ, nFocusShift, nMarkSpeed);
    m_pDriverEnvironment->SetBoolParameter("laser_on", bLaserIsOn);
    m_pDriverEnvironment->SetIntegerParameter("position_x", nPositionX);
    m_pDriverEnvironment->SetIntegerParameter("position_y", nPositionY);
    m_pDriverEnvironment->SetIntegerParameter("position_z", nPositionZ);
    m_pDriverEnvironment->SetIntegerParameter("position_x_corrected", nCorrectedPositionX);
    m_pDriverEnvironment->SetIntegerParameter("position_y_corrected", nCorrectedPositionY);
    m_pDriverEnvironment->SetIntegerParameter("position_z_corrected", nCorrectedPositionZ);
    m_pDriverEnvironment->SetIntegerParameter("focus_shift", nFocusShift);
    m_pDriverEnvironment->SetIntegerParameter("mark_speed", nMarkSpeed);


}

