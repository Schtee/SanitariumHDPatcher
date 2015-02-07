include_directories(../include
	../thirdparty/rapidjson/include
	../thirdparty/tclap/include)

add_executable("SanitariumHDPatcher"
	main.cpp
	md5.cpp
	Patch.cpp
	PatchCollection.cpp
	PatchesJSONParser.cpp)
