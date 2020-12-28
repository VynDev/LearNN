workspace "LearNN"
	configurations {"Debug", "Release"}

	-- Library

	project "LearNN"
		kind "StaticLib"
		language "C++"; cppdialect "C++17"
		targetdir "bin"

		includedirs {"include", "libs/json-parser/include"} -- includes
		links {"libs/json-parser/bin/json-parser"} -- libraries

		files {"source/**.cpp"} -- sources
		removefiles {"source/**.test.cpp"} -- ignore test source files
		
		prebuildcommands {"cd ./libs/json-parser && premake5 gmake && make"} -- Build dependencies

	-- Tests

	project "tests"
		kind "ConsoleApp"
		language "C++"; cppdialect "C++17"
		targetdir "bin"

		includedirs {"include", "tests"}
		links {"LearNN", "libs/json-parser/bin/json-parser"}

		files {"tests/**.test.cpp", "source/**.test.cpp"}

	-- Examples

	project "xor"
		kind "ConsoleApp"
		language "C++"; cppdialect "C++17"
		targetdir "bin"

		includedirs {"include"}
		links {"LearNN", "libs/json-parser/bin/json-parser"}

		files {"examples/xor.cpp"}

-- Actions

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
	trigger = "examples",
	description = "Run the examples, for dev testing purpose",
	execute = function ()
		os.execute("./bin/xor")
	end
}

newaction {
	trigger = "tests",
	description = "run tests",
	execute = function ()
		os.execute("./bin/tests")
	end
}