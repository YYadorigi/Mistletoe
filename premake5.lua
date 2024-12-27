workspace "Mistletoe"
	architecture "x64"
	configurations { "Debug", "Release" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"	--e.g., Debug-Windows-x64
appname = "TestGame"

include "Mistletoe/third-party/glfw/premake5.lua"
include "Mistletoe/third-party/glad/premake5.lua"
include "Mistletoe/third-party/imgui/premake5.lua"

project "Mistletoe"
	location "Mistletoe"
	kind "SharedLib"
	language "C++"

	objdir ("bin/tmp/" .. outputdir .. "/%{prj.name}")
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")

	pchheader "mstpch.h"
	pchsource "%{prj.name}/src/mstpch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/third-party/spdlog/include",
		"%{prj.name}/third-party/glfw/include",
		"%{prj.name}/third-party/glad/include",
		"%{prj.name}/third-party/imgui",
	}

	links {
		"glfw",
		"glad",
		"imgui",
		"opengl32.lib",
	}

	buildoptions {
		"/utf-8",
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines {
			"MST_PLATFORM_WINDOWS",
			"MST_BUILD_DLL",
		}

		postbuildcommands {
			("{MKDIR} ../bin/" .. outputdir .. "/" .. appname),
			("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/" .. appname),
		}

	filter "configurations:Debug"
		defines "MST_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "MST_RELEASE"
		runtime "Release"
		optimize "On"

project (appname)
	location (appname)
	kind "ConsoleApp"
	language "C++"

	objdir ("bin/tmp/" .. outputdir .. "/%{prj.name}")
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs {
		"Mistletoe/src",
		"Mistletoe/third-party/spdlog/include",
	}

	links {
		"Mistletoe",
	}

	buildoptions {
		"/utf-8",
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines {
			"MST_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		runtime "Release"
		optimize "On"