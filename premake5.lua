workspace "Mistletoe"
	architecture "x64"
	configurations { "Debug", "Release", "Distribution" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"	--e.g., Debug-Windows-x64
appname = "TestGame"

project "Mistletoe"
	location "Mistletoe"
	kind "SharedLib"
	language "C++"

	objdir ("bin/tmp/" .. outputdir .. "/%{prj.name}")
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/third-party/spdlog/include",
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
			("{MKDIR} bin/" .. outputdir .. "/" .. appname),
			("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/" .. appname),
		}

	filter "configurations:Debug"
		defines "MST_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "MST_RELEASE"
		optimize "On"

	filter "configurations:Distribution"
		defines "MST_DISTRIBUTION"
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

	buildoptions {
		"/utf-8",
	}

	links {
		"Mistletoe",
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines {
			"MST_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "MST_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "MST_RELEASE"
		optimize "On"

	filter "configurations:Distribution"
		defines "MST_DISTRIBUTION"
		optimize "On"
