cmake_minimum_required(VERSION 3.5)

project(02.guessing_game)

add_executable(guessing_game 
    flag.h    
    flag.cpp
    rand.h
    rand.cpp
    repo.h
    repo.cpp
    main.cpp
)

set_target_properties(guessing_game PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
