#include "boardDetails.h"



BoardDetails::BoardDetails() : seed(rand()), autoNotes(false) {
//    this->boardID = -1;
//    this->setTiles = -1;
//   this->difficulty = -1;
}
BoardDetails::BoardDetails (int seed) : seed(seed), autoNotes(false) {
    
    //this->boardID = boardID;
  //  this->setTiles = setTiles;
    //this->difficulty = difficulty;

}

int BoardDetails::getSeed() {
    return seed;
}


void BoardDetails::setSeed(int seed) {
    this->seed = seed;
}


void BoardDetails::setAutoNotes(bool autoNotes) {
   this->autoNotes = autoNotes; 
}
bool BoardDetails::getAutoNotes() {
    return autoNotes;
}

/*
int BoardDetails::getBoardID() {
    return boardID;
}

void BoardDetails::setBoardID(int boardID) {
    this->boardID = boardID; 
}
*/

/*
int BoardDetails::getSetTiles() {
    return setTiles;
}

void BoardDetails::setSetTiles(int setTiles) {
    this->setTiles = setTiles; 
}
*/

/*
int BoardDetails::getDifficulty() {
    return difficulty;
}

void BoardDetails::setDifficulty(int difficulty) {
    this->difficulty = difficulty;
}
*/

/*
void BoardDetails::increaseSetTiles(int amount) {
    setTiles += amount;
}
*/
