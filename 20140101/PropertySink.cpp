#include "Include.h"

namespace std {

	void PropertySink::_runCreate(PropertyMgrPtr& nPropertyMgr)
	{
		map<__u32, PropertyIdPtr>::iterator it = mCreates.begin();
		for ( ; it != mCreates.end(); ++it )
		{
			PropertyIdPtr& propertyId_ = it->second;
			PropertyPtr property_ = propertyId_->_createProperty(nPropertyMgr);
			nPropertyMgr->_addProperty(property_, propertyId_);
			property_->_runInit();
		}
	}

	void PropertySink::_registerCreate(PropertyIdPtr& nPropertyId)
	{
		__u32 propertyId_ = nPropertyId->_getId();
		map<__u32, PropertyIdPtr>::iterator it = mCreates.find(propertyId_);
		if (it == mCreates.end())
		{
			LogSingleton logSingleton_ = __singleton<LogSingleton>::_instance();
			format fmt("PropertyMgr::_registerCreate %1%");
			fmt % propertyId_;
			logSingleton_._logError(fmt.str().c_str());
			throw exception();
		}
		mCreates[propertyId_] = nPropertyId;
	}

}
