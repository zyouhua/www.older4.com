#pragma once

namespace std {

	class ILog
	{
	public:
		virtual void _logError(const char * nValue) = 0;
		virtual void _logInfo(const char * nValue) = 0;
	};
	typedef shared_ptr<ILog> LogPtr;
}
