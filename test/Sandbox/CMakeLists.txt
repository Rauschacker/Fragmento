

get_filename_component(SubDirName ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${SubDirName})
set(SubDirName "${DirName}/${SubDirName}")

file(GLOB ${CMAKE_CURRENT_SOURCE_DIR}
     "*.h"
     "*.cpp"
)


set(test_scenes 
   Scenes/scene.h
   Scenes/enttTest.h
   Scenes/imguiFonts.h 
   Scenes/assetsFolderScene.h 
   Scenes/spriteTest.h
   Scenes/imGuiTest.h
)

source_group("Scenes" FILES ${test_scenes})

add_executable(test main.cpp ${test_scenes})

target_link_libraries(test PRIVATE Editor)

set_target_properties (test PROPERTIES
    FOLDER ${SubDirName}
)

target_include_directories(test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Scenes)