cmake_minimum_required(VERSION 3.26)
project(Gaussian_Elimination)

set(CMAKE_CXX_STANDARD 14)

include_directories(interface)
include_directories(src)

add_executable(Gaussian_Elimination
        interface/GEA.h
        interface/iterator.h
        interface/matrix.h
        interface/overloads.h
        src/backward_phase.cpp
        src/forward_phase.cpp
        src/GEA.cpp
        src/iterator.cpp
        src/matrix.cpp)
