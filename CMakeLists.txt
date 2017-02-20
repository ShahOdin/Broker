cmake_minimum_required(VERSION 3.6)
project(broker)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES
        main.cpp
        Source/interface/Role.cpp
        Source/interface/Relationship.cpp
        Source/SquashGame.cpp
        Source/BiblicalMarriage.cpp
        )
add_executable(${PROJECT_NAME} ${SOURCE_FILES})