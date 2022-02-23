cmake_minimum_required(VERSION 3.10)


set(CMAKE_CXX_STANDARD 20)
include(FetchContent)
# Set the project name
project (Fragmento)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)




if ("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_CURRENT_SOURCE_DIR}")
  set(FRAGMENTO_IS_MAIN TRUE)
else()
  set(FRAGMENTO_IS_MAIN FALSE)
endif()

if(FRAGMENTO_IS_MAIN)
set(fragmento_root_dir "Fragmento")
else()
set(fragmento_root_dir "vendor/Fragmento")
endif()


add_subdirectory(vendor)
add_subdirectory(src)
add_subdirectory(Editor)

if(FRAGMENTO_IS_MAIN)
add_subdirectory(test)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test)
endif()

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

