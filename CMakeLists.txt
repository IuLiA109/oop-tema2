cmake_minimum_required(VERSION 3.24)
project(oop_tema2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(oop_tema2
        Depozit.cpp
        Depozit.h Automobil.cpp Automobil.h Autobus.h Autobus.cpp Sedan.cpp Sedan.h main.cpp)
