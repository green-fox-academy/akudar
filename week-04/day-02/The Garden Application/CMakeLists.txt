cmake_minimum_required(VERSION 3.13)
project(The_Garden_Application)

set(CMAKE_CXX_STANDARD 14)

add_executable(The_Garden_Application main.cpp garden.cpp garden.h tree.cpp tree.h flower.cpp flower.h plants.cpp plants.h)