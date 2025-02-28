#include <iostream>
#include <string>
#include "game.h"
#include "raylib.h"
#include <vector>
#include <iostream>

int main() {

        Game game;
        game.playGame();
    //    std::vector<std::vector<SudokuTile>> board;
    //    SudokuBoard game;
    //    std::string in1, in2, in3;
    //    game.generateBoard(0);
    //    board = game.getGameBoard();
    //    std::cout << std::endl;
    //    std::cout << sizeof(char) << " " << sizeof(uint8_t) << " " << sizeof(bool) << " " << sizeof(SudokuTile);
    //    std::cout << std::endl;
    //
    //    while (!game.wonGame()) {
    //        for (int i = 0; i < 9; i++) {
    //
    //            if (!(i%3)) {
    //                std::cout << '\n';
    //            }
    //            for (int j = 0; j < 9; j++) {
    //                if (!(j%3)) {
    //                    std::cout << " ";
    //                }
    //                std::cout << game.gameBoard.at(j).at(i).number << " ";
    //            }
    //            std::cout << '\n';
    //        }
    //        std::cout << std::endl;
    //        std::cin >> in1;
    //        std::cin >> in2;
    //        std::cin >> in3;
    //
    //        switch (game.setTile(in1.at(0), in2.at(0), in3.at(0))) {
    //            case 0:
    //
    //                system("clear");
    //
    //        std::cout << "collisions: " << std::flush;
    //        for (Position p : game.getCollisions(in1.at(0), in2.at(0))) {
    //            std::cout << '(' << (char)(p.x+'0') << ", " << (char)(p.y+'0') << ')';
    //        }
    //                break;
    //            case 1:
    //                std::cout << "out of bounds" << std::endl;
    //                break;
    //            case 2:
    //
    //                std::cout << "invalid number" << std::endl;
    //                break;
    //            case 3:
    //                std::cout << "preset" << std::endl;
    //                break;
    //        }
    //    }
}
