cmake_minimum_required(VERSION 2.8)
cmake_policy(SET CMP0015 NEW)

project(gta)

include_directories(include/)

file(GLOB PG_GTA include/*.h)
file(GLOB HD_GTA src/*.cpp)

add_executable(gta ${PG_GTA} ${HD_GTA})

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_EXTENSIONS OFF)