cmake_minimum_required(VERSION 3.14)
project(PasswordCracker CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES "*.cpp")

add_executable(PasswordCracker ${SOURCES})

target_include_directories(PasswordCracker PUBLIC .)