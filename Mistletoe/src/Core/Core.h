#pragma once

#ifdef MST_PLATFORM_WINDOWS
#ifdef MST_BUILD_DLL
#define MST_API __declspec(dllexport)
#else
#define MST_API __declspec(dllimport)
#endif
#else
#error Mistletoe only supports Windows!
#endif

#define BIT(x) (1 << x)