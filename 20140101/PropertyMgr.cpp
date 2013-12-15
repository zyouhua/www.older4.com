#include "Include.h"

namespace std {
	
	PropertyPtr& PropertyMgr::_getProperty(__u32 nPropertyId)
	{
		map<__u32, PropertyPtr>::iterator it = mPropertys.find(nPropertyId);
		if (it == mPropertys.end())
		{
			LogSingleton logSingleton_ = __singleton<LogSingleton>::_instance();
			format fmt("PropertyMgr::_getProperty %1%");
			fmt % nPropertyId;
			logSingleton_._logError(fmt.str().c_str());
			throw exception();
		}
		return it->second;
	}

	PropertyPtr& PropertyMgr::_getProperty(IPropertyId& nPropertyId)
	{
		__u32 propertyId_ = nPropertyId._getId();
		map<__u32, PropertyPtr>::iterator it = mPropertys.find(propertyId_);
		if (it == mPropertys.end())
		{
			LogSingleton logSingleton_ = __singleton<LogSingleton>::_instance();
			format fmt("PropertyMgr::_getProperty %1%");
			fmt % propertyId_;
			logSingleton_._logError(fmt.str().c_str());
			throw exception();
		}
		return it->second;
	}

	void PropertyMgr::_addProperty(PropertyPtr& nProperty, PropertyIdPtr& nPropertyId)
	{
		__u32 propertyId_ = nPropertyId->_getId();
		map<__u32, PropertyPtr>::iterator it = mPropertys.find(propertyId_);
		if (it == mPropertys.end())
		{
			LogSingleton logSingleton_ = __singleton<LogSingleton>::_instance();
			format fmt("PropertyMgr::_AddProperty %1%");
			fmt % propertyId_;
			logSingleton_._logError(fmt.str().c_str());
			throw exception();
		}
		mPropertys[propertyId_] = nProperty;
	}

	PropertyMgr::PropertyMgr()
	{
		mPropertys.clear();
	}

	PropertyMgr::~PropertyMgr()
	{
		mPropertys.clear();
	}

}
