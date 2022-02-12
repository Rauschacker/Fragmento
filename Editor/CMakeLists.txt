


set(Editor_headers 
    Editor/Editor.h
)

set(Editor_src 
    Editor/Editor.cpp
)

source_group("src", ${Editor_src} ${Editor_headers})

set(Panel_headers 
    Editor/Panels/Dockspace.h 
    Editor/Panels/MainMenuBar.h
)


source_group("src/Panels" {Panel_headers})

set(Editor_all 
 ${Editor_src}
 ${Editor_headers}
 ${Panel_headers}
)


add_library(Editor ${Editor_all})

target_link_libraries(Editor PUBLIC Fragmento)

set_target_properties (Editor PROPERTIES
    FOLDER Editor
)

target_include_directories(Editor PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
