cmake_minimum_required(VERSION 3.5)

project(
    TicTacToe
    LANGUAGES CXX
)

add_library(
    tttlib ./src/tictactoe.hxx ./src/tictactoe.cxx
)

add_executable(
    TicTacToe ./main.cxx
)

target_link_libraries(
    TicTacToe tttlib
)