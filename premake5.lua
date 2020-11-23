solution "LearNN"
	configurations {"Debug", "Release"}

	project "LearNN"
		kind "StaticLib"
		language "C++"
		files {"src/**.h", "src/**.cpp"}
		removefiles {"src/**.test.cpp"}
		targetdir "lib"

	configuration "Debug"
		defines {"DEBUG"}

	configuration "Release"
		defines {"NDEBUG"}

	project "tests"
		kind "ConsoleApp"
		language "C++"
		files {"src/**.test.cpp", "src/catch.h"}
		links {"LearNN"}
		targetdir "bin"

	project "xor"
		kind "ConsoleApp"
		language "C++"
		files {"examples/xor/**.h", "examples/xor/**.cpp"}
		links {"LearNN"}
		targetdir "bin"

	configuration "Debug"
		defines {"DEBUG"}

	configuration "Release"
		defines {"NDEBUG"}
	

newaction {
	trigger = "clean",
	description = "clean the software",
	execute = function ()
		print("clean the build...")
		os.rmdir("./bin")
		os.rmdir("./obj")
		os.rmdir("./lib")
		os.remove("./Makefile")
		os.remove("./*.make")
		print("done.")
	end
}