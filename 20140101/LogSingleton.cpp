#include "Include.h"

namespace std {

	void LogSingleton::_logError(const char * nValue)
	{

	}

	void LogSingleton::_logInfo(const char * nValue)
	{

	}

	void LogSingleton::_runInit(LogPtr& nLog)
	{
		mLog = nLog;
	}

	LogSingleton::LogSingleton()
	{

	}

	LogSingleton::~LogSingleton()
	{

	}

}
