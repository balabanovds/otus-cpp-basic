cmake_minimum_required(VERSION 3.7.2)
project(containers)

add_executable(containers
        containers.cpp)

set_target_properties(containers PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
