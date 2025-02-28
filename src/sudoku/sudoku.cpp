#include "sudoku.h"
#include <stdio.h>

Sudoku::Sudoku(int seed) : board(std::make_shared<std::array<std::array<Tile, 9>, 9>>()),
    boardDetails(std::make_unique<BoardDetails>(seed)),
    notes(std::make_shared<std::array<std::array<Note, 9>, 9>>()) {}


    //added later

    /*
       void Sudoku::startRandomGame() {

       srand(time(NULL));
       boardDetails->setSeed(rand() * (boardDetails->getSeed() < 0) + boardDetails->getSeed() * !(boardDetails->getSeed() < 0)) ;
       BoardGenerator::generateBoard(board, boardDetails->getSeed());      
       }
       */

    void Sudoku::StartLoadedGame(int boardID) {
        boardDetails->setSeed(-1);
        BoardLoader::loadBoard(board, boardID);
    }

std::shared_ptr<std::array<std::array<Tile, 9>, 9>> Sudoku::getBoard() {
    return board;
}

void SaveGame() {

}

//int Sudoku::getBoardID() {
//    return boardDetails->getBoardID();
//}


int Sudoku::getSeed() {
    return boardDetails->getSeed();
}

void Sudoku::printBoard() {
    char buff[0];
    for (int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            buff[0] = board->at(i).at(j).getNumber();
            TraceLog(LOG_DEBUG, buff);
        } 
    }
}


int Sudoku::setTile(int x, int y, int number) {

    int invalidUpdate = 0;

    //valid number check
    invalidUpdate |= !(number >= 0 && number <= 9);

    //in range check
    invalidUpdate |= !(x >= 0 && x <= 9 && y >= 0 && y <= 9) << 1; 
    //if given an out or range value set position to (0,0) and give an invalid value so the number does not update
    x *= !(invalidUpdate >> 1); 
    y *= !(invalidUpdate >> 1);
    number -= (invalidUpdate >> 1) * (number+1);
    //checks if the square is preset
    invalidUpdate |= (board->at(x).at(y).getPreset() << 2); 
    //    boardDetails->increaseSetTiles(board->at(x).at(y).getNumber() == '0' && number > '0' && !invalidUpdate);  
    //    boardDetails->increaseSetTiles(-(board->at(x).at(y).getNumber() > '0' && number == '0' && !invalidUpdate));
    if (!invalidUpdate && boardDetails->getAutoNotes() &&board->at(x).at(y).getNumber() != number ) {
            
        removeNotes(x, y, number);
            addNotes(x, y, board->at(x).at(y).getNumber());
    }
    board->at(x).at(y).updateNumber(number);
    //autonotes mode remove the number set from all other tiles
    //if value is 0 add the old value back
    return invalidUpdate;
}


//finds if there are multiple of the same element in a set and returns the collision positions
//only needs to check 9 squares to check every set e.g. only need to check X spots
//X00 000 000
//000 X00 000
//000 000 X00
//
//0X0 000 000
//000 0X0 000
//000 000 0X0
//
//00X 000 000
//000 00X 000
//000 000 00X
std::unordered_set<std::pair<int,int>, IntPairHash> Sudoku::getCollisions() {

    std::unordered_set<std::pair<int,int>, IntPairHash> collisions;
    std::array<int, 9> squaresToCheck = {0,12,24,27,39,51,54,66,78};
    std::unordered_map<int,std::pair<int,int>> currentRow;
    std::unordered_map<int,std::pair<int,int>> currentColumn;
    std::unordered_map<int,std::pair<int,int>> currentSquare;

    int currentRowVal;
    int currentColumnVal;
    int currentSquareVal;
    int currentSquareOffset;
    for(int square : squaresToCheck) {

        currentSquareOffset = square/27*3+(square%9/3);

        for(int i = 0; i < 9; i++) {
            currentRowVal = board->at(i).at(square/9).getNumber();
            currentColumnVal = board->at(square%9).at(i).getNumber();
            currentSquareVal = board->at(currentSquareOffset%3*3+i%3).at(currentSquareOffset/3*3+i/3).getNumber();
            if(currentRowVal != 0) {

                if (currentRow.find(currentRowVal) != currentRow.end()) {
                    collisions.insert(currentRow[currentRowVal]);
                    collisions.emplace(i, square/9);
                } else {
                    currentRow.emplace(std::make_pair(currentRowVal, std::make_pair(i, square/9)));
                }
            }
            if (currentColumnVal != 0) {

                if (currentColumn.find(currentColumnVal) != currentColumn.end()) {
                    collisions.insert(currentColumn[currentColumnVal]);
                    collisions.emplace(square%9, i);
                } else {
                    currentColumn.emplace(std::make_pair(currentColumnVal, std::make_pair(square%9, i)));
                }
            }
            if (currentSquareVal != 0) {

                if (currentSquare.find(currentSquareVal) != currentSquare.end()) {
                    collisions.insert(currentSquare[currentSquareVal]);

                    collisions.emplace(currentSquareOffset%3*3+i%3, currentSquareOffset/3*3+i/3);
                } else {
                    currentSquare.emplace(std::make_pair(currentSquareVal, 
                                std::make_pair(currentSquareOffset%3*3+i%3, currentSquareOffset/3*3+i/3)));
                }
            }
        } 

        currentRow.clear();
        currentColumn.clear();
        currentSquare.clear();

    }
    return collisions; 
}



void Sudoku::emptyNotes() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            notes->at(i).at(j).emptyNote();
        }
    }
}
void Sudoku::autoNotes() {

}

std::shared_ptr<std::array<std::array<Note, 9>, 9>> Sudoku::getNotes() {
    return notes;
}

void Sudoku::initAutoNotes() {

    std::unordered_set<int> rows[9];
    std::unordered_set<int> columns[9];
    std::unordered_set<int> squares[9];

    std::array<int, 9> squaresToCheck = {0,12,24,27,39,51,54,66,78};
    int currentRowVal;
    int currentColumnVal;
    int currentSquareVal;
    int currentSquareOffset;
    for (int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            notes->at(i).at(j).fillNote();
        }
    }

    for (int square : squaresToCheck) {
        currentSquareOffset = square/27*3+(square%9/3);

        for (int i = 0; i < 9; i++) { 
            currentRowVal = board->at(i).at(square/9).getNumber();
            currentColumnVal = board->at(square%9).at(i).getNumber();
            currentSquareVal = board->at(currentSquareOffset%3*3+i%3).at(currentSquareOffset/3*3+i/3).getNumber();
            rows[square/9].insert(currentRowVal);
            columns[square%9].insert(currentColumnVal);
            squares[currentSquareOffset].insert(currentSquareVal);
        }   
    }

    for (int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            currentSquareOffset = i/3*3+j/3;
            for (int number : rows[i]) {
                notes->at(j).at(i).removeNote(number);
            } 
            for (int number : columns[j]) {
                notes->at(j).at(i).removeNote(number);
            } 
            for (int number : squares[currentSquareOffset]) {
                notes->at(j).at(i).removeNote(number);
            } 
        }
    }
    boardDetails->setAutoNotes(true);
}


//when taking notes if the user inputs a number it inverts it
//i.e. remvoes when its there adds when it isnt
void Sudoku::invertNote(int x, int y, int num) {

    notes->at(x).at(y).invertNote(num);
}

void Sudoku::removeNotes(int x, int y, int num) {
    int currentSquare = y/3*3+(x/3);
    removeNotesRow(y, num);
    removeNotesColumn(x, num);
    removeNotesSquare(currentSquare, num);
}

void Sudoku::removeNotesRow(int row, int num) {
    for (int i = 0; i < 9; i++) {
        notes->at(i).at(row).removeNote(num); 
    } 
}

void Sudoku::removeNotesColumn(int column, int num) {

    for (int i = 0; i < 9; i++) {
        notes->at(column).at(i).removeNote(num); 
    } 
}

void Sudoku::removeNotesSquare(int square, int num) {
    int xOffset = square%3*3;
    int yOffset = square/3*3;
    for (int i = 0; i < 9; i++) {
        notes->at(xOffset+i%3).at(yOffset+i/3).removeNote(num);
    }
}


void Sudoku::addNotes(int x, int y, int num) {

    int currentSquare = y/3*3+(x/3);
    addNotesRow(y, num);
    addNotesColumn(x, num);
    addNotesSquare(currentSquare, num);
}

void Sudoku::addNotesRow(int row, int num) {

    for (int i = 0; i < 9; i++) {
        notes->at(i).at(row).addNote(num); 
    } 
}
void Sudoku::addNotesColumn(int column, int num) {

    for (int i = 0; i < 9; i++) {
        notes->at(column).at(i).addNote(num); 
    } 
}
void Sudoku::addNotesSquare(int square, int num) {

    int xOffset = square%3*3;
    int yOffset = square/3*3;
    for (int i = 0; i < 9; i++) {
        notes->at(xOffset+i%3).at(yOffset+i/3).addNote(num);
    }
}
bool Sudoku::gameWon() {
    bool EmptySlots = false;

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            EmptySlots += board->at(i).at(j).getNumber() == '0';
        }
    }

    return getCollisions().empty() && EmptySlots;

}
//int Sudoku::getDifficulty() {
//    return boardDetails->getDifficulty();
//}


/*
   int Sudoku::getSetTiles() {
   return boardDetails->getSetTiles();
   }
   */

