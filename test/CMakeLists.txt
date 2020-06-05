cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

set(This scan_dir_test)

find_package(GTest REQUIRED)
find_package(Boost REQUIRED COMPONENTS filesystem system) 

include_directories(
    "../"
    ${Boost_INCLUDE_DIR} 
)

set(Sources
    test.cpp
)

add_executable(${This} 
	${Sources}
)

target_link_libraries(${This} PUBLIC
    ${GTEST_LIBRARIES}
    ${Boost_LIBRARIES}
    scan_dir_lib
    pthread
)

add_test(
    NAME ${This}
    COMMAND ${This}
)
