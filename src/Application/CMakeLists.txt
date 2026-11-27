add_library(
    Application
    STATIC
    ${CMAKE_SOURCE_DIR}/include/Application/Application.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Application.cpp
)

add_library(ControllableCharacter::App ALIAS Application)

find_package(SDL3 CONFIG REQUIRED)

target_link_libraries(
    Application
    PUBLIC
    SDL3::SDL3
    ControllableCharacter::InputManager
)