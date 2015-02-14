set(VERSION_MAJOR 0 CACHE STRING "Major version")
set(VERSION_MINOR 2 CACHE STRING "Minor version")
set(VERSION_PATCH 1 CACHE STRING "Patch version")

include_directories(../include
	../thirdparty/rapidjson/include
	../thirdparty/tclap/include)

configure_file(main.cpp.in
	"${PROJECT_SOURCE_DIR}/src/main.cpp")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL} /MT")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} /MT")

add_executable(SanitariumHDPatcher
	main.cpp
	md5.cpp
	Patch.cpp
	PatchCollection.cpp
	PatchesJSONParser.cpp)

target_link_libraries(SanitariumHDPatcher
	Shlwapi.lib)

install(TARGETS SanitariumHDPatcher DESTINATION ./)
install(FILES "${PROJECT_SOURCE_DIR}/resources/patches.json" DESTINATION ./)
install(FILES "${PROJECT_SOURCE_DIR}/readme.md" DESTINATION ./)
