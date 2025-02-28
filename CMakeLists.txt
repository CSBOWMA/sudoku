cmake_minimum_required(VERSION 3.31.2)
project(sudoku CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(raylib REQUIRED)

set(SOURCES 
    src/game.cpp
    src/main.cpp
    src/mainMenu/mainMenuScene.cpp
    src/sudoku/gameScene.cpp
    src/sudoku/boardElement.cpp
    src/sudoku/sudoku.cpp
    src/sudoku/boardDetails.cpp
    src/sudoku/tile.cpp
    src/sudoku/note.cpp
    src/sudoku/inputNumber.cpp
    src/sudoku/timer.cpp
    src/sudoku/notesButton.cpp
    src/sudoku/autoNotesButton.cpp
)

add_executable(Sudoku ${SOURCES})

target_include_directories(Sudoku PRIVATE src)

target_link_libraries(Sudoku raylib)
