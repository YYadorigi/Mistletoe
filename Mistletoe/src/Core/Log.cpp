#include "Log.h"

namespace Mistletoe
{
	std::shared_ptr<spdlog::logger> Log::coreLogger;
	std::shared_ptr<spdlog::logger> Log::clientLogger;

	Log::Log() {}

	Log::~Log() {}

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		coreLogger = spdlog::stdout_color_mt("Mistletoe");
		coreLogger->set_level(spdlog::level::trace);
		clientLogger = spdlog::stdout_color_mt("Application");
		clientLogger->set_level(spdlog::level::trace);
	}

	void Log::Shutdown() {}
}