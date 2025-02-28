#ifndef SUDOKUBOARDGENERATOR_H
#define SUDOKUBOARDGENERATOR_H
#include "iostream"
#include "boardValidator.h"
#include "boardDetails.h"
#include "board.h"
#include "tile.h"
#include <memory>
#include <unordered_set>
#include <array>
#include <algorithm>

class BoardGenerator {
    static void NumbersInRow();

    static void shuffle() {

    }

    static int currentColumn(int currentPos) {

        return currentPos%9;
    }
    
    static int currentSquare(int currentPos) {

        return (currentPos/27)*3 + (currentPos%9)/3;
    }

    public:

    static void positionTests() {
        for (int i = 0; i < 81; i++) {
            std::cout << i << " column: " << currentColumn(i) << " square: " << currentSquare(i) << std::endl;
        }
    }

    static void generateBoard(std::shared_ptr<std::array<std::array<Tile, 9>, 9>> board, int seed) {
        srand(seed);
        std::unordered_set<int> columns[9];
        std::unordered_set<int> squares[9];
        std::array<int, 9> currentRow = {1,2,3,4,5,6,7,8,9};
        int rowPos;
        printf("start generating\n");
        fflush(stdout);
        int currentPos = 0;
        int curColumn;
        int curSquare;
        for (int i = 0; i < 8; i++) {
            
            //shuffle current row
            for (int j = 8; j > 0; j--) {
                std::swap(currentRow[j], currentRow[rand()%(j+1)]);
            }

            printf("row: %d shuffled\n", i);
            fflush(stdout);

            rowPos = 0;
            while (currentPos < i*9+9) {
                curColumn = currentColumn(currentPos);
                curSquare = currentSquare(currentPos);

                printf("current %d \n", currentPos);
                printf("rowPos: %d \n", rowPos);
                //fix logic
                if (columns[curColumn].find(currentRow[rowPos]) == columns[curColumn].end() && 
                        squares[curSquare].find(currentRow[rowPos]) == squares[curSquare].end()) {
                    printf("not found\n");
                    
                    board->at(currentPos%9).at(currentPos/9).setNumber(currentRow.at(rowPos));
                    columns[curColumn].insert(currentRow.at(rowPos));
                    squares[curSquare].insert(currentRow.at(rowPos));
                    std::swap(currentRow[rowPos], currentRow[8-currentPos%9]);
                    rowPos = 0;
                    currentPos++;
                } else {
                    rowPos++;
                    printf("found\n");
                }
                fflush(stdout);

            }


        }

        printf("board made");
        
    }
};

#endif
