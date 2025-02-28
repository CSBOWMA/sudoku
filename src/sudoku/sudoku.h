#ifndef SUDOKU
#define SUDOKU
#include "boardDetails.h"
#include "raylib.h"
#include "note.h"
#include <memory>
#include "intPairHash.h"
#include "unordered_set"
#include "unordered_map"
#include "boardLoader.h"

class Sudoku {
    
    private:
        std::shared_ptr<std::array<std::array<Tile, 9>, 9>> board;
        std::unique_ptr<BoardDetails> boardDetails; 
        std::shared_ptr<std::array<std::array<Note, 9>, 9>> notes;
        
        void removeNotes(int x, int y, int num);
        void removeNotesRow(int row, int num);
        void removeNotesColumn(int column, int num);
        void removeNotesSquare(int square, int num); 

        void addNotes(int x, int y, int num);
        void addNotesRow(int row, int num);
        void addNotesColumn(int column, int num);
        void addNotesSquare(int square, int num); 
    public:
        Sudoku(int seed = -1);
        void loadBoard();
        void startGame();
        std::shared_ptr<std::array<std::array<Tile, 9>, 9>> getBoard();
        std::shared_ptr<std::array<std::array<Note, 9>, 9>> getNotes();
        void StartLoadedGame(int BoardID = 0);
        int setTile(int x, int y, int num);
        void endGame();
        void SaveGame();
        int getSeed();
        void printBoard();
        std::unordered_set<std::pair<int,int>, IntPairHash> getCollisions();
        void emptyNotes();
        void autoNotes();
        void initAutoNotes();
        void invertNote(int x, int y, int num);
        bool gameWon();
        //int getBoardID();
        //int getDifficulty();
//      int getSetTiles();

};

#endif
