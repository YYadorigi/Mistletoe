#include "mstpch.h"
#include "Log.h"

namespace Mistletoe
{
	Log::Log()
	{
		coreLogger = spdlog::stdout_color_mt("Mistletoe");
		coreLogger->set_level(spdlog::level::trace);
		clientLogger = spdlog::stdout_color_mt("Application");
		clientLogger->set_level(spdlog::level::trace);
	}

	Log::~Log() = default;

	void Log::SetLogFormat(const std::string& format)
	{
		coreLogger->set_pattern(format);
		clientLogger->set_pattern(format);
	}
}