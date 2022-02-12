




set(imgui_headers 
    imgui/imconfig.h 
    imgui/imgui_impl_glfw.h
    imgui/imgui_impl_opengl3_loader.h 
    imgui/imgui_impl_opengl3.h 
    imgui/imgui_internal.h 
    imgui/imgui.h 
    imgui/imstb_rectpack.h 
    imgui/imstb_textedit.h 
    imgui/imstb_truetype.h
)

set(imgui_src
    imgui_demo.cpp
    imgui_draw.cpp 
    imgui_impl_glfw.cpp 
    imgui_impl_opengl3.cpp 
    imgui_tables.cpp 
    imgui_widgets.cpp 
    imgui.cpp
)


add_library(imgui ${imgui_headers} ${imgui_src})
set_target_properties (imgui PROPERTIES
    FOLDER vendor/imgui
)

target_compile_definitions(imgui PRIVATE IMGUI_DISABLE_WIN32_FUNCTIONS=1)

target_link_libraries(imgui glfw)
target_link_libraries(imgui raylib)





#include dirs
target_include_directories(imgui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(imgui PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/imgui)

