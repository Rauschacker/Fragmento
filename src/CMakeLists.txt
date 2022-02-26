

get_filename_component(DirName ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${DirName})
set(DirName "${fragmento_root_dir}/${DirName}")


message("source_dir: " ${DirName})

##############################
#          CORE              #
##############################

set(fragmento_core_headers 
    core/Input.h
    core/Timer.h 
    core/Window.h
    core/Application.h
)
set(fragmento_core_src 
    core/Input.cpp 
    core/Timer.cpp 
    core/Window.cpp 
    core/Application.cpp
)

set(fragmento_core 
    ${fragmento_core_src} 
    ${fragmento_core_headers})

source_group("src/core" FILES ${fragmento_core_src} ${fragmento_core_headers})


##############################
#          Entity            #
##############################

set(fragmento_entity_headers 
    entity/Entity.h 
    entity/EntityRegistry.h 
    entity/EntityObserver.h 
    entity/EntityGroup.h 
)

set(fragmento_entity_src 
    entity/Entity.cpp 
    entity/EntityRegistry.cpp 
    entity/EntityObserver.cpp 
)

set(fragmento_entity_main 
    ${fragmento_entity_src} 
    ${fragmento_entity_headers}
)

source_group("src/entity" FILES ${fragmento_entity_src}  ${fragmento_entity_headers})

##############################
#     Entity Components      #
##############################

set(fragmento_enitity_components_headers 
    entity/components/Components.h 
    entity/components/Selectable.h 
    entity/components/Shapes.h 
    entity/components/Components.cpp
)

set(fragmento_entity_components_src 
    
)

set(fragmento_entity_component 
    ${fragmento_enitity_components_headers}
    ${fragmento_entity_components_src}
)

source_group("src/entity/components" FILES ${fragmento_entity_components_src}  ${fragmento_enitity_components_headers})

set(fragmento_entity 
    ${fragmento_entity_main} 
    ${fragmento_entity_component}
)

##############################
#          scene             #
##############################

set(fragmento_scene_headers 
    scene/SceneState.h 
    scene/Scene.h 
    scene/SceneHandler.h
)


set(fragmento_scene_src
    scene/Scene.cpp
    scene/SceneHandler.cpp
)

set(fragmento_scene ${fragmento_scene_headers} ${fragmento_scene_src})

source_group("src/scene" FILES ${fragmento_scene})





##############################
#          UI                #
##############################

set(fragmento_uiPanels_headers
#    modules/uiPanels/CameraInfo.h 
#    modules/uiPanels/EntityInfo.h 
#    modules/uiPanels/MouseInfo.h
#    modules/uiPanels/EntityList.h
    ui/panels/BasicPanels.h
)   

set(fragemento_uiPanels_src 
 #   modules/uiPanels/EntityList.cpp
     ui/panels/BasicPanels.cpp
)

set(fragmento_uiPanels ${fragmento_uiPanels_headers} ${fragemento_uiPanels_src})
source_group("src/ui/panels" FILES ${fragmento_uiPanels})



set(fragmento_ui_headers 
    ui/GuiWrapper.h
    ui/ImGuiPanel.h
    ui/themes.h
)


set(fragmento_ui_src
    ui/GuiWrapper.cpp 
)


set(fragmento_ui ${fragmento_ui_headers} ${fragmento_ui_src} ${fragmento_uiPanels})

source_group("src/ui" FILES ${fragmento_ui_headers} ${fragmento_ui_src})


##############################
#          MODUELS           #
##############################


######################### Camera ###########################################

set(fragmento_camera_headers 
    modules/camera/Camera.h 
)

set(fragemento_camera_src 

)

set(fragmento_camera ${fragmento_camera_headers} ${fragemento_camera_src})
source_group("src/modules/camera" FILES ${fragmento_camera})
###########################################################################

######################### cameraController ################################

set(fragmento_cameraController_headers 
    modules/camerController/CameraController.h
)

set(fragemento_cameraController_src 

)

set(fragmento_cameraController ${fragmento_cameraController_headers} ${fragemento_cameraController_src})
source_group("src/modules/cameraController" FILES ${fragmento_cameraController})
###########################################################################


######################### gridScene ################################

set(fragmento_gridScene_headers 
    modules/gridScene/GridScene.h
    modules/gridScene/EntityGrid.h
)

set(fragemento_gridScene_src 

)

set(fragmento_gridScene ${fragmento_gridScene_headers} ${fragemento_gridScene_src})
source_group("src/modules/gridScene" FILES ${fragmento_gridScene})
###########################################################################

######################### worldGrid #######################################

set(fragmento_worldGrid_headers 
    modules/worldGrid/WorldGrid.h
)

set(fragemento_worldGrid_src 
modules/worldGrid/WorldGrid.cpp
)

set(fragmento_worldGrid ${fragmento_worldGrid_headers} ${fragemento_worldGrid_src})
source_group("src/modules/worldGrid" FILES ${fragmento_worldGrid})
###########################################################################

######################### entityGrid #######################################

set(fragmento_entityGrid_headers
    modules/entityGrid/EntityGrid.h 
)

set(fragemento_entityGrid_src 

)

set(fragmento_entityGrid ${fragmento_entityGrid_headers} ${fragemento_entityGrid_src})
source_group("src/modules/entityGrid" FILES ${fragmento_entityGrid})
###########################################################################


######################### Entity Components #######################################

set(fragmento_entityComponents_headers
    
)

set(fragmento_entityComponents_src 

)

set(fragmento_entityComponents ${fragmento_entityComponents_headers} ${fragmento_entityComponents_src})
source_group("src/modules/entityComponents" FILES ${fragmento_entityComponents})
###########################################################################


### MODULES ###
set(fragmento_modules 
    ${fragmento_camera}
    ${fragmento_cameraController}
    ${fragmento_gridScene}
    ${fragmento_worldGrid}
    ${fragmento_entityGrid}
    ${fragmento_entityComponents}
)



##############################
#          Utility           #
##############################


set(fragmento_utility_headers 
    utility/Logger.h
    utility/FileLoader.h
)

set(fragmento_utility_src 
    utility/FileLoader.cpp
)

set(fragmento_utility ${fragmento_utility_headers} ${fragmento_utility_src})
source_group("src/utility" FILES ${fragmento_utility})

##############################
#          animation         #
##############################


set(fragmento_animation_headers 
    modules/animation/Animation.h
)

set(fragmento_animation_src

)

set(fragmento_animation ${fragmento_animation_headers} ${fragmento_animation_src})
source_group("src/animation" FILES ${fragmento_animation})


##############################
#          Renderer          #
##############################


set(fragmento_renderer_headers 
    renderer/Draw.h
    renderer/Draw.cpp
)

set(fragmento_renderer_src

)

set(fragmento_renderer ${fragmento_renderer_headers} ${fragmento_renderer_src})
source_group("src/renderer" FILES ${fragmento_renderer})

##############################
#          ALL               #
##############################

set(fragmento_all
${fragmento_core}
${fragmento_entity} 
${fragmento_ui}
${fragmento_modules}
${fragmento_scene}
${fragmento_utility}
${fragmento_renderer}
${fragmento_animation}
)

##############################
#     CREATING LIBRARY       #
##############################

add_library(Fragmento ${fragmento_all})
set_target_properties(Fragmento PROPERTIES FOLDER ${DirName})
target_include_directories(Fragmento PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_directories(Fragmento PUBLIC)
set_target_properties(Fragmento PROPERTIES VS_GLOBAL_VcpkgEnabled false)

##############################
#        DEPENDICIES         #
##############################

##############################
#          Raylib            #
##############################
target_link_libraries(Fragmento PUBLIC raylib)

##############################
#         imgui              #
##############################
target_link_libraries(Fragmento PUBLIC imgui)

##############################
#          box2d             #
##############################
target_link_libraries(Fragmento PUBLIC box2d)

##############################
#          entt              #
##############################
target_link_libraries(Fragmento PUBLIC enTT)

##############################
#          bitflags          #
##############################
target_link_libraries(Fragmento PUBLIC bitflags)

##############################
#          extras            #
##############################
target_link_libraries(Fragmento PUBLIC raylibExtras)

##############################
#         rlImGui            #
##############################
target_link_libraries(Fragmento PUBLIC rlImGui)

##############################
#          Raygui            #
##############################
target_link_libraries(Fragmento PUBLIC raylibExtras)

##############################
#          spdlog            #
##############################
target_link_libraries(Fragmento PUBLIC spdlog)

##############################
#          fmt               #
##############################
target_link_libraries(Fragmento PUBLIC fmt)