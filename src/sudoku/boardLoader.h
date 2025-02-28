#ifndef SUDOKUBOARDLOADER_H
#define SUDOKUBOARDLOADER_H

#include "boardDetails.h"
#include "tile.h"
#include "BoardLoaderError.h"
#include <string>
#include <array>
#include "memory"
#include "fstream"
#include "string"
#include "iostream"
class BoardLoader {
   
    private:
        static bool validLine(std::string line) {
                
                bool invalid = false; 
                invalid += line.size() == 9;
                std::cout << "size: " << line.size() << std::endl;
                for (int i = 0; i < 9; i++) {
                    invalid += line.at(i) < '0' || line.at(i) > '9';
                    std::cout << "line at: " << i << " is " << line.at(i) << std::endl;
                }

                return !invalid;
        }

    public:
        

        static void loadBoard(std::shared_ptr<std::array<std::array<Tile, 9>, 9>> board, int boardID) {
            std::string fileName = "../boards/board" + std::to_string(boardID) + ".su";
            std::ifstream file(fileName);
            std::string currentLine;

            if (!file.is_open()) {
                throw BoardLoaderError("file not found");
            }
            
            for (int i = 0; i < 9; i++) {
                if (file.eof()) {
                    throw BoardLoaderError("invalid file");
                }
                file >> currentLine; 
                if (validLine(currentLine)) {
                    throw BoardLoaderError("invalid line");
                }
                for (int j = 0; j < 9; j++) {
                    board->at(j).at(i).setNumber(currentLine.at(j));
                    board->at(j).at(i).setPreset(currentLine.at(j) != '0');
                }
            }
        }
};


#endif
