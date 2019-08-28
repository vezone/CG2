workspace "ComputerGraphic2"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include dirs
IncludeDirs = {}
IncludeDirs["GLFW"] = "Dependencies/GLFW/include" 
IncludeDirs["Glad"] = "Dependencies/Glad/include" 
IncludeDirs["glm"] = "Dependencies/glm" 

group "Dependencies"
	include "Dependencies/GLFW"
	include "Dependencies/Glad"

project "ComputerGraphic2"
	location "ComputerGraphic2"
	kind "ConsoleApp"
	language "C"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin/Intermidiates/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/**.c",
		"%{prj.name}/src/**.c",
		"Dependencies/glm/glm/**.hpp",
		"Dependencies/glm/glm/**.inl"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}

	includedirs
	{
		"%{prj.name}/src", 
		"%{IncludeDirs.GLFW}",
		"%{IncludeDirs.Glad}",
		"%{IncludeDirs.glm}"
	}

	links 
	{
		"GLFW",
		"Glad",
		"opengl32.lib"
	}

	filter "configurations:Debug"
		defines "CG_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "CG_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "CG_DIST"
		buildoptions "/MD"
		optimize "On"
