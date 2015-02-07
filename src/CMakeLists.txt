set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)

include_directories(../include
	../thirdparty/rapidjson/include
	../thirdparty/tclap/include)

configure_file(main.cpp.in
	"${PROJECT_SOURCE_DIR}/src/main.cpp")

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
