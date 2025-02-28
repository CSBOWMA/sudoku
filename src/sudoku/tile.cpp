#include "tile.h"

//when the board is not in use make tiles invalid 
void Tile::invalidate() {
    number = 0x80;
}

//checks if a tile is valid, i.e. if it is possible to win with this tile
bool Tile::valid() {
    return number != 0x80;
}

//retruns the first 7 bits of number to represent the number stored
int Tile::getNumber(bool asChar) {
    //if the user wants it as a char it increases the value by '0' to be in char form
    return (number & 0x7f) + '0' * asChar;
}

//sets first 7 bits of of number to represent the number stored
//Only sets the value if the value is between '0' and '9' otherwise does not change value
void Tile::setNumber(char number) {
    //convert number to int between 0 and 9
    number = number - '0';

    this->number = ((number) | (this->number & 0X80) * (number >= 0 && number <= 9)) + this->number * !(number >= 0 && number <= 9);
    //same as if(number >= 0 && number <= 9){this->number = number;}
}
//need to fix
void Tile::setNumber(int number) {
    this->number = (((number) | (this->number & 0X80))  * (number >= 0 && number <= 9)) + this->number * !(number >= 0 && number <= 9);
    //same as if(number >= '0' && number <= '9'){this->number = number;}
}


//only sets a number if it is not preset and if it is in the valid range
//returns if the value could be updated
bool Tile::updateNumber(char number) {
        number = number - (number >= '0' && number <= '9')*'0';
    this->number = (number | (this->number & 0x80)) * (!(this->number & 0x80) && number >= 0 && number <= 9)
        + this->number*!(!(this->number & 0x80) && number >= 0 && number <= 9);
    //same as if(preset == false && number >= '0' && number <= '9') {this->number = number;}
    
    return (!(this->number & 0x80) && number >= 0 && number <= 9);
}

//overloaded function that takes in the int value between 0 and 9 and converts it to a value between '0' and '9'
//then performs standard updateNumber fonctionality
bool Tile::updateNumber(int number) {
        
    this->number = (number | (this->number & 0x80)) * (!(this->number & 0x80) && number >= 0 && number <= 9)
        + this->number*!(!(this->number & 0x80) && number >= 0 && number <= 9);
    //same as if(preset == false && number >= 0 && number <= 9) {this->number = number + '0';}
    return (!(this->number & 0x80) && number >= 0 && number <= 9);
}

//returns the 8th bit of number representing if the tile has been preset, i.e. it may not be changed
bool Tile::getPreset() {
    return this->number & 0x80;
}

//sets the 8th bit of number representing if the tile has been preset, i.e. it may not be changed
void Tile::setPreset(bool preset) {
    this->number = (this->number & 0x7f) | (preset << 7); 
}
//initializes a Tile with a char value, if the value is greater than '0' and less that '9' it is considered preset 
Tile::Tile(char number) {
    number = number - '0';
    this->number = number * (number >= 0 && number <= 9);
    this->number = this->number | ((this->number <= 9 && this->number > 0) << 7); 
}

//initializes a Tile with an int value, if the value is greater than '0' and less that '9' it is considered preset 
Tile::Tile(int number) {
    this->number = number * (number >= 0 && number <= 9);
    this->number = this->number | ((this->number <= 9 && this->number > 0) << 7); 
}
//default contructor initializes number to '0' with preset false
Tile::Tile() {
    this->number = 0x00;
}
