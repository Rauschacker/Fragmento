get_filename_component(SubDirName ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${SubDirName})
set(SubDirName "${DirName}/${SubDirName}")

file(GLOB ${CMAKE_CURRENT_SOURCE_DIR}
     "*.h"
     "*.cpp"
)



include(GoogleTest)

set(unitTest_src 
    utility.cpp
    main.cpp
)

add_executable(unitTest ${unitTest_src})

target_link_libraries(unitTest Editor)
target_link_libraries(unitTest gtest_main)


gtest_discover_tests(unitTest)

set_target_properties (unitTest PROPERTIES
    FOLDER ${SubDirName}
)

