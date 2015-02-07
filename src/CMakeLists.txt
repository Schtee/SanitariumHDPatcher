include_directories(../include)

add_executable("SanitariumHDPatcher"
	main.cpp
	md5.cpp
	Patch.cpp
	PatchCollection.cpp
	PatchesJSONParser.cpp)
