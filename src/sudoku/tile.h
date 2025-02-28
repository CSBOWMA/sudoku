#ifndef SUDOKUTILE_H
#define SUDOKUTILE_H
#include "cinttypes"

class Tile {
    public:
        void invalidate();
        bool valid();
        int getNumber(bool asChar = false);
        void setNumber(char number);
        void setNumber(int number);
        bool updateNumber(char number);
        bool updateNumber(int number);
        bool getPreset();
        void setPreset(bool preset);

        Tile(char);
        Tile(int);
        Tile();
    private:
        uint8_t number;       
};

#endif 
