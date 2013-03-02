-----------------------------------------------------------------
--                     Solution Settings                       --
-----------------------------------------------------------------
solution ( "../vs/Serialization" )
  -- Different types of configurations for the solution
  configurations { "Debug", "Release" }

-----------------------------------------------------------------
--      This entire section belongs to a single project        --
-----------------------------------------------------------------
project ( "Serialization" )
  language ( "C" )
  kind ( "ConsoleApp" )
  location ( "../vs" )
  objdir ( "../objs" )
  targetdir ( "../bin" )
  libdirs { "../dependencies/" .. "**" }
  includedirs { "../dependencies/include", "../src/serialization/" }

  -- Types of files to include within this project
  files {
    "../src/serialization/**.h",
    "../src/serialization/**.hpp",
    "../src/serialization/**.cpp",
    "../src/serialization/**.c",
    "../src/serialization/**.txt",
    "../src/serialization/**.fx"
  }

  -- Debug Configuration Settings
  configuration "Debug"
    defines { "_DEBUG" }
    flags {
      "Symbols",
      "NoMinimalRebuild",
      "NoEditAndContinue",
      "FloatStrict",
      "StaticRuntime",
      "WinMain",
      "NoRTTI"
      }
      
    links {
    }
    
    pchheader ( "Precompiled.h" )
    pchsource ( "../src/serialization/Precompiled.c" )

    -- disable specific warnings:
    buildoptions { "/wd4100", "/wd4996", "/wd4201", "/wd4238", "/wd4800", "/wd4239", "/wd4505" }

  -- Release Configuration Settings
  configuration "Release"
    defines { "NDEBUG" }
    flags {
      "Symbols",
      "NoMinimalRebuild",
      "NoEditAndContinue",
      "FloatFast",
      "StaticRuntime",
      "WinMain",
      "OptimizeSpeed",
      "NoRTTI"
      }
      
    links {
      "vld"
    }
    
    pchheader ( "Precompiled.h" )
    pchsource ( "../src/serialization/Precompiled.c" )

    -- disable specific warnings:
    buildoptions { "/wd4100", "/wd4996", "/wd4201", "/wd4238", "/wd4800", "/wd4239", "/wd4505" }
