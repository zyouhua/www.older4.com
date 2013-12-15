#pragma once

namespace std {

	class LogSingleton
	{
	public:
		void _logError(const char * nValue);
		void _logInfo(const char * nValue);
		void _runInit(LogPtr& nLog);
		LogSingleton();
		~LogSingleton();
	private:
		LogPtr mLog;
	};

}
