add_library(
    Player
    STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Player.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Player.cpp
)

add_library(ControllableCharacter::Player ALIAS Player)