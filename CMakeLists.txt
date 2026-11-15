cmake_minimum_required(VERSION 3.28..4.4)

project(
    ControllableCharacter
    VERSION 1.0
    DESCRIPTION "A mini character controllable character."
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(
    ControllableCharacter
    ${CMAKE_SOURCE_DIR}/src/main.cpp
)

add_subdirectory(${CMAKE_SOURCE_DIR}/src/Input)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/Player)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/Application)

target_link_libraries(
    ControllableCharacter
    PRIVATE
    ControllableCharacter::App
)

target_include_directories(${CMAKE_SOURCE_DIR}/src)