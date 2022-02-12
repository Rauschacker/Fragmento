cmake_minimum_required(VERSION 3.10)


set(CMAKE_CXX_STANDARD 20)
include(FetchContent)
# Set the project name
project (Fragmento)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)



add_subdirectory(vendor)
add_subdirectory(src)
add_subdirectory(Editor)
add_subdirectory(test)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test)


file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

