
cmake_minimum_required (VERSION 3.8)

project ("32.5.2")

set(CMAKE_CXX_STANDARD 14)
set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)
add_executable (32.5.2 "32.5.2.cpp" )

target_link_libraries(32.5.2 PRIVATE nlohmann_json::nlohmann_json)

