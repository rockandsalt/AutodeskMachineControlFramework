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

#define __AMCIMPL_UI_MODULE
#define __AMCIMPL_API_CONSTANTS

#include "amc_ui_module_contentitem_buildlist.hpp"
#include "libmc_interfaceexception.hpp"

#include "amc_api_constants.hpp"
#include "Common/common_utils.hpp"
#include "amc_parameterhandler.hpp"
#include "amc_statemachinedata.hpp"

#include "libmcdata_dynamic.hpp"

using namespace AMC;



CUIModule_ContentBuildList::CUIModule_ContentBuildList(const std::string& sLoadingText, const uint32_t nEntriesPerPage, const std::string& sDetailPage, LibMCData::PBuildJobHandler pBuildJobHandler)
	: CUIModule_ContentItem(AMCCommon::CUtils::createUUID()), m_sLoadingText(sLoadingText), m_nEntriesPerPage(nEntriesPerPage), m_sDetailPage (sDetailPage), m_pBuildJobHandler (pBuildJobHandler)
{
	if (pBuildJobHandler.get() == nullptr)
		throw ELibMCInterfaceException(LIBMC_ERROR_INVALIDPARAM);

	m_sBuildNameCaption = "Build name";
	m_sBuildLayersCaption = "Layers";
	m_sBuildUUIDCaption = "UUID";

}

CUIModule_ContentBuildList::~CUIModule_ContentBuildList()
{

}

void CUIModule_ContentBuildList::addDefinitionToJSON(CJSONWriter& writer, CJSONWriterObject& object)
{

	object.addString(AMC_API_KEY_UI_ITEMTYPE, "buildlist");
	object.addString(AMC_API_KEY_UI_ITEMUUID, m_sUUID);
	object.addString(AMC_API_KEY_UI_ITEMLOADINGTEXT, m_sLoadingText);
	object.addString(AMC_API_KEY_UI_ITEMDETAILPAGE, m_sDetailPage);
	object.addInteger(AMC_API_KEY_UI_ITEMENTRIESPERPAGE, m_nEntriesPerPage);

	CJSONWriterArray headersArray(writer);

	CJSONWriterObject headerObject1(writer);
	headerObject1.addString(AMC_API_KEY_UI_ITEMTEXT, m_sBuildNameCaption);
	headerObject1.addString(AMC_API_KEY_UI_ITEMVALUE, AMC_API_KEY_UI_ITEMBUILDNAME);
	headersArray.addObject(headerObject1);

	CJSONWriterObject headerObject2(writer);
	headerObject2.addString(AMC_API_KEY_UI_ITEMTEXT, m_sBuildLayersCaption);
	headerObject2.addString(AMC_API_KEY_UI_ITEMVALUE, AMC_API_KEY_UI_ITEMBUILDLAYERS);
	headersArray.addObject(headerObject2);

	CJSONWriterObject headerObject3(writer);
	headerObject3.addString(AMC_API_KEY_UI_ITEMTEXT, m_sBuildUUIDCaption);
	headerObject3.addString(AMC_API_KEY_UI_ITEMVALUE, AMC_API_KEY_UI_ITEMBUILDUUID);
	headersArray.addObject(headerObject3);

	object.addArray(AMC_API_KEY_UI_ITEMHEADERS, headersArray);

	CJSONWriterArray entriesArray(writer);
	object.addArray(AMC_API_KEY_UI_ITEMENTRIES, entriesArray);
}

void CUIModule_ContentBuildList::addContentToJSON(CJSONWriter& writer, CJSONWriterObject& object)
{

	CJSONWriterArray entryArray(writer);

	auto pBuildJobIterator = m_pBuildJobHandler->ListJobsByStatus(LibMCData::eBuildJobStatus::Validated);
	while (pBuildJobIterator->MoveNext ()) {
		
		auto pBuildJob = pBuildJobIterator->GetCurrentJob();

		CJSONWriterObject entryObject(writer);
		entryObject.addString(AMC_API_KEY_UI_ITEMBUILDNAME, pBuildJob->GetName ());
		entryObject.addInteger(AMC_API_KEY_UI_ITEMBUILDLAYERS, pBuildJob->GetLayerCount());
		entryObject.addString(AMC_API_KEY_UI_ITEMBUILDUUID, pBuildJob->GetUUID());
		entryObject.addString(AMC_API_KEY_UI_ITEMBUILDTIMESTAMP, pBuildJob->GetUUID());

		pBuildJob->GetTimeStamp();

		entryObject.addString(AMC_API_KEY_UI_ITEMDETAILPAGE, m_sDetailPage);
		entryArray.addObject(entryObject);

	}

	object.addArray(AMC_API_KEY_UI_ITEMENTRIES, entryArray);
}


