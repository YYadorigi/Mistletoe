#pragma once
#pragma warning(disable: 4251)
#include "Core/Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Mistletoe
{
	class MST_API Log
	{
	public:
		Log() = delete;
		static void Init();
		static void Shutdown();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return clientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> coreLogger;
		static std::shared_ptr<spdlog::logger> clientLogger;
	};
}

#ifdef MST_DEBUG // Debug mode
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
// Assertion macros
#define MST_CORE_ASSERT(x, ...) {if(!(x)) { MST_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define MST_ASSERT(x, ...) { if(!(x)) { MST_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else // Release mode or distribution version
// Core log macros
#define MST_CORE_TRACE(...)
#define MST_CORE_INFO(...)
#define MST_CORE_WARN(...)
#define MST_CORE_ERROR(...)
#define MST_CORE_CRITICAL(...)
// Client log macros
#define MST_TRACE(...)
#define MST_INFO(...)
#define MST_WARN(...)
#define MST_ERROR(...)
#define MST_CRITICAL(...)
// Assertion macros
#define MST_CORE_ASSERT(x, ...)
#define MST_ASSERT(x, ...)
#endif