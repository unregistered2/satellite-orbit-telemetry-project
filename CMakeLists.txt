cmake_minimum_required(VERSION 3.20)
project(SatelliteOrbitSimulator VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(sat_sim
    src/main.cpp
    src/satellite.cpp
)

target_include_directories(sat_sim PRIVATE src)

if(MSVC)
    target_compile_options(sat_sim PRIVATE /W4 /permissive-)
else()
    target_compile_options(sat_sim PRIVATE -Wall -Wextra -pedantic)
endif()