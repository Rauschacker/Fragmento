

set(extras_sources 
    FPCamera.cpp
)   


set(extras_headers 
    FPCamera.h
)

add_library(raylibExtras ${extras_sources} ${extras_headers})


set_target_properties (raylibExtras PROPERTIES
    FOLDER vendor/extras
)


