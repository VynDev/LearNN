solution "LearNN"
	configurations {"Static", "Shared"}

	project "LearNN"
		language "C++"
		includedirs {"include"}
		files {"source/**.cpp"}
		removefiles {"source/**.test.cpp"}
		targetdir "bin"

		configuration "Static"
			kind "StaticLib"

		configuration "Shared"
			kind "SharedLib"

	project "tests"
		kind "ConsoleApp"
		language "C++"
		includedirs {"include", "tests"}
		files {"tests/**.test.cpp", "source/**.test.cpp"}
		links {"LearNN"}
		targetdir "bin"

	project "xor"
		kind "ConsoleApp"
		language "C++"
		includedirs {"include"}
		files {"examples/xor/**.h", "examples/xor/**.cpp"}
		links {"LearNN"}
		targetdir "bin"

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