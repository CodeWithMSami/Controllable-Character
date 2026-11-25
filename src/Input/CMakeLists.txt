add_library(
    InputManager
    STATIC
    ${CMAKE_SOURCE_DIR}/include/Input/InputManager.hpp
    ${CMAKE_SOURCE_DIR}/include/Input/InputMapping.hpp
    ${CMAKE_SOURCE_DIR}/include/Input/InputAction.hpp
    ${CMAKE_SOURCE_DIR}/include/Input/KeyboardInput.hpp
    ${CMAKE_SOURCE_DIR}/include/Input/MouseInput.hpp
    ${CMAKE_SOURCE_DIR}/include/Input/GamepadInput.hpp
    ${CMAKE_SOURCE_DIR}/src/Input/InputManager.cpp
    ${CMAKE_SOURCE_DIR}/src/Input/InputMapping.cpp
    ${CMAKE_SOURCE_DIR}/src/Input/KeyboardInput.cpp
    ${CMAKE_SOURCE_DIR}/src/Input/MouseInput.cpp
    ${CMAKE_SOURCE_DIR}/src/Input/GamepadInput.cpp
)

target_include_directories(
    InputManager
    PUBLIC
    ${CMAKE_SOURCE_DIR}/include/
)

add_library(ControllableCharacter::InputManager ALIAS InputManager)