cmake_minimum_required(VERSION 3.6)
project(templateExperiment)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp Source/interface/Role.cpp Source/interface/Role.h Source/interface/Relationship.cpp Source/interface/Relationship.h Source/SquashGame.cpp Source/SquashGame.h Source/BiblicalMarriage.cpp Source/BiblicalMarriage.h)
add_executable(templateExperiment ${SOURCE_FILES})