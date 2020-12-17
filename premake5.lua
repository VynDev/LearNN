workspace "LearNN"
	configurations {"Debug", "Release"}

	project "LearNN"
		kind "StaticLib"
		language "C++"; cppdialect "C++17"
		targetdir "bin"

		includedirs {"include", "libs/json-parser/include"} -- includes
		links {"libs/json-parser/bin/json-parser"} -- libraries

		files {"source/**.cpp"} -- sources
		removefiles {"source/**.test.cpp"} -- ignore test source files
		
		prebuildcommands {"cd ./libs/json-parser && premake5 gmake && make"} -- Build dependencies
	
	filter "configurations:Debug"
		postbuildcommands {"ar -q bin/libLearNN.a libs/json-parser/obj/Debug/json-parser/*.o"} -- Merge the libraries to not have to link it in other projects
	
	filter "configurations:Release"
		postbuildcommands {"ar -q bin/libLearNN.a libs/json-parser/obj/Debug/json-parser/*.o"} -- Merge the libraries to not have to link it in other projects
	
	project "xor"
		kind "ConsoleApp"
		language "C++"; cppdialect "C++17"
		targetdir "bin"

		includedirs {"include"}
		links {"LearNN"}

		files {"examples/xor/**.h", "examples/xor/**.cpp",}
		

	--[[
	project "tests"
		kind "ConsoleApp"
		language "C++"; cppdialect "C++17"
		targetdir "bin"
		
		includedirs {"include", "tests"}
		links {"LearNN"}

		files {"tests/**.test.cpp", "source/**.test.cpp"}
	]]

newaction {
	trigger = "clean",
	description = "clean the software",
	execute = function ()
		print("cleaning the build...")
		os.rmdir("./bin")
		os.rmdir("./obj")
		os.remove("./Makefile")
		os.remove("./*.make")
		print("done.")
	end
}

newaction {
	trigger = "tests",
	description = "run tests",
	execute = function ()
		os.execute("./bin/xor")
	end
}