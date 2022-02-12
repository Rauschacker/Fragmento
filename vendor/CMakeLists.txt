

##############################
#          Raylib            #
##############################
set(RAYLIB_IS_MAIN FALSE)
set(INCLUDE_EVERYTHING ${OFF})
add_subdirectory(raylib)
set_target_properties (raylib PROPERTIES
    FOLDER vendor/raylib
)

##############################
#          glfw              #
##############################
set_target_properties (glfw PROPERTIES
    FOLDER vendor/glfw
)

##############################
#          imgui            #
##############################
add_subdirectory(imgui)


##############################
#          box2d             #
##############################
set(BOX2D_BUILD_TESTBED false)
add_subdirectory(box2d)
set_target_properties(box2d PROPERTIES
    FOLDER vendor/box2d)
    set_target_properties(unit_test PROPERTIES
    FOLDER vendor/box2d)


##############################
#          extras            #
##############################
add_subdirectory(raylibExtras)

##############################
#          rlImGUi           #
##############################
add_subdirectory(rlImGui)

##############################
#          sppdlog           #
##############################
add_subdirectory(spdlog)
set_target_properties(spdlog PROPERTIES
    FOLDER vendor/spdlog)
