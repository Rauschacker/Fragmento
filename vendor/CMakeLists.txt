

get_filename_component(DirName ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${DirName})
set(DirName "${fragmento_root_dir}/${DirName}")



##############################
#          Raylib            #
##############################
set(RAYLIB_IS_MAIN FALSE)
set(INCLUDE_EVERYTHING ${OFF})
add_subdirectory(raylib)
set_target_properties (raylib PROPERTIES
    FOLDER ${DirName}/raylib
)

##############################
#          glfw              #
##############################
set_target_properties (glfw PROPERTIES
    FOLDER ${DirName}/glfw
)

##############################
#          imgui            #
##############################
add_subdirectory(imgui)
set_target_properties (imgui PROPERTIES
    FOLDER ${DirName}/imgui
)

##############################
#          box2d             #
##############################
set(BOX2D_BUILD_TESTBED false)
add_subdirectory(box2d)
set_target_properties(box2d PROPERTIES
    FOLDER ${DirName}/box2d)
    set_target_properties(unit_test PROPERTIES
    FOLDER ${DirName}/box2d)


##############################
#          extras            #
##############################
add_subdirectory(raylibExtras)
set_target_properties (raylibExtras PROPERTIES
    FOLDER ${DirName}/extras
)

##############################
#          rlImGUi           #
##############################
add_subdirectory(rlImGui)
set_target_properties (rlImGui PROPERTIES
    FOLDER ${DirName}/rlImGui
)

##############################
#          fmt 		     #
##############################
add_subdirectory(fmt)
set_target_properties (fmt PROPERTIES
    FOLDER ${DirName}/fmt
)


##############################
#          sppdlog           #
##############################
set(SPDLOG_FMT_EXTERNAL ON)
add_subdirectory(spdlog)
set_target_properties(spdlog PROPERTIES
    FOLDER ${DirName}/spdlog)

##############################
#          entt              #
##############################
add_library(enTT INTERFACE)
target_include_directories(enTT INTERFACE entt/)

##############################
#          bitflags          #
##############################
add_library(bitflags INTERFACE)
target_include_directories(bitflags INTERFACE bitflags/)

##############################
#          Raygui            #
##############################
add_library(raygui INTERFACE)
target_include_directories(raygui INTERFACE raygui/)

##############################
#          boost             #
##############################


##############################
#          googletest        #
##############################
set(BUILD_GMOCK OFF)
set(INSTALL_GTEST OFF)
add_subdirectory(googletest)
set_target_properties (gtest PROPERTIES
    FOLDER ${DirName}/googletest
)
set_target_properties (gtest_main PROPERTIES
    FOLDER ${DirName}/googletest
)


