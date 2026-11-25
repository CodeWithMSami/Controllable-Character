add_library(
    Application
    STATIC
    ${CMAKE_SOURCE_DIR}/include/InputManager.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/InputManager.cpp
)

add_library(ControllableCharacter::App ALIAS Application)

find_package(SDL3 CONFIG REQUIRED)

target_link_libraries(
    Application
    PUBLIC
    SDL3::SDL3
    ControllableCharacter::InputManager
    ControllableCharacter::Player
)