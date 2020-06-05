cmake_minimum_required(VERSION 3.16)
set(This scan_dir_lib)

project(${This})

set(CMAKE_CXX_STANDARD 17)

find_package(Boost REQUIRED COMPONENTS filesystem system) 

INCLUDE_DIRECTORIES( 
    "."
    ${Boost_INCLUDE_DIR} 
)

set(Sources
    scan_dir.cpp
)

add_library(${This} STATIC 
    ${Sources}
)

set_target_properties( ${This}
    PROPERTIES LINKER_LANGUAGE CXX
)

TARGET_LINK_LIBRARIES( ${This} LINK_PUBLIC 
    ${Boost_LIBRARIES}
)

#######################################
# Test
enable_testing()
add_subdirectory(test)
