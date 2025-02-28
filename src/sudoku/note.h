#ifndef SUDOKU_NOTE_H
#define SUDOKU_NOTE_H
#include "cstdint" 
#include <stdio.h>

class Note {
    private:

        uint16_t note;
    public:
        Note(bool filled = false);
        void addNote(int noteVal);
        bool contains(int num) {
            return note & (0x01 << (num-1));
        }
        void removeNote(int noteVal);
        void invertNote(int noteVal);
        void fillNote();
        void setNote(int note);
        int getNote();
        void printNote();
        void emptyNote();
};


#endif
