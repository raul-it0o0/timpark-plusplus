cmake_minimum_required(VERSION 3.27)
project(TimPark__)

set(CMAKE_CXX_STANDARD 23)

add_executable(TimPark__ main.cpp
        menus.cpp
        menus.h
        handlers.cpp
        handlers.h)
