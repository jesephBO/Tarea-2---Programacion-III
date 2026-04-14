cmake_minimum_required(VERSION 4.2)
project(Tarea2)

set(CMAKE_CXX_STANDARD 26)

add_executable(Tarea2
        core_numeric.hpp
        clasesPrueba.cpp
        clasesPrueba.h
        testTransformReduce.cpp
        testMax.cpp
        testVariance.cpp
        testMean.cpp
        testSum.cpp
        testSumVar.cpp
        testMeanVar.cpp
        testVarianceVar.cpp
        testMaxVar.cpp)
