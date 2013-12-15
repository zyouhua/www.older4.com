#pragma once

namespace std {

	class PropertyMgr
	{
	public:
		PropertyPtr& _getProperty(__u32 nPropertyId);
		PropertyPtr& _getProperty(IPropertyId& nPropertyId);
		void _addProperty(PropertyPtr& nProperty, PropertyIdPtr& nPropertyId);

		PropertyMgr();
		~PropertyMgr();

	private:
		map<__u32, PropertyPtr> mPropertys;
	};

}
