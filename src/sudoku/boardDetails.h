#ifndef SUDOKUBOARDDETAILS_H
#define SUDOKUBOARDDETAILS_H
#include <cstdint>
#include <random>
//#define EASYSUDOKUBOARD 0
//#define MEDIUMSUDOKUBOARD 1
//#define HARDSUDOKUBOARD 2
//#define INSANESUDOKUBOARD 3

//details are stored in game in case
//I want to add more details later
class BoardDetails { 
    private:

        int seed;
        bool autoNotes;
        //int boardID;
        //int8_t setTiles;
        //int8_t difficulty;

    public:
        BoardDetails();
        BoardDetails(int seed);
        int getSeed();
        void setSeed(int);
        void setAutoNotes(bool);
        bool getAutoNotes();
        //int getBoardID();
        //void setBoardID(int);
        //int getSetTiles();
        //void setSetTiles(int);
        //int getDifficulty();
        //void setDifficulty(int);
        //void increaseSetTiles(int);
};

#endif
