#pragma once
#pragma warning(disable: 4251)
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "Core.h"

namespace Mistletoe
{
	class MST_API Log
	{
	public:
		static void Init();
		static void Shutdown();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return clientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> coreLogger;
		static std::shared_ptr<spdlog::logger> clientLogger;

		Log() = default;
		~Log() = default;
	};
}

// Core log macros
#define MST_CORE_TRACE(...) Mistletoe::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MST_CORE_INFO(...) Mistletoe::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MST_CORE_WARN(...) Mistletoe::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MST_CORE_ERROR(...) Mistletoe::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MST_CORE_CRITICAL(...) Mistletoe::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define MST_TRACE(...) Mistletoe::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MST_INFO(...) Mistletoe::Log::GetClientLogger()->info(__VA_ARGS__)
#define MST_WARN(...) Mistletoe::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MST_ERROR(...) Mistletoe::Log::GetClientLogger()->error(__VA_ARGS__)
#define MST_CRITICAL(...) Mistletoe::Log::GetClientLogger()->critical(__VA_ARGS__)