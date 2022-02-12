


### rlImGui ###

set(rlImGui_headers 
    rlImGui/FA5FreeRegularFontData.h
    rlImGui/FA5FreeSolidFontData.h
    rlImGui/ForkAwesomeFontData.h
    rlImGui/IconsFontAwesome5.h
    rlImGui/IconsForkAwesome.h
    rlImGui/rlImGui.h
)

set(rlImGui_src
    rlImGui/rlImGui.cpp
)

add_library(rlImGui ${rlImGui_headers} ${rlImGui_src})

set_target_properties (rlImGui PROPERTIES
    FOLDER vendor/rlImGui
)

target_link_libraries(rlImGui PUBLIC imgui)
target_include_directories(rlImGui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
