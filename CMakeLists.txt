cmake_minimum_required(VERSION 3.14)
project(PasswordCracker CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB SOURCES "src/*.cpp")

add_executable(PasswordCracker ${SOURCES})

target_include_directories(PasswordCracker PUBLIC ${CMAKE_SOURCE_DIR}/include)