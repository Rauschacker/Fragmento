


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
target_link_libraries(rlImGui PRIVATE imgui)
target_link_libraries(rlImGui PRIVATE raylib)
target_include_directories(rlImGui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
