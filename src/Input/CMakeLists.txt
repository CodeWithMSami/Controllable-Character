add_library(
    InputManager
    STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/InputManager.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/InputManager.cpp
)

add_library(ControllableCharacter::InputManager ALIAS InputManager)