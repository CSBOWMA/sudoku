#include "note.h"

Note::Note(bool filled) {
    note = 0x1ff*filled;
}
void Note::addNote(int noteVal) {
    note |= 0x1 << (noteVal - 1); 
}
void Note::removeNote(int noteVal) {
    note &= 0x1ff ^ 0x1 << (noteVal-1);
}


void Note::invertNote(int noteVal) {
    note ^= 0x01 << (noteVal-1);
}
void Note::fillNote() {
    note = 0x1ff;
}
void Note::setNote(int note) {
    note = note;
}

int Note::getNote() {
    return note;
}

void Note::printNote() {

        printf("note is: %d\n", note);
    for (int i = 1; i < 65536; i = i*2) {
        if (note & i) {
            printf("note at %d\n", i);
        }
    }
    printf("\n");
    fflush(stdout);
}

void Note::emptyNote() {
    note = 0x00;
}



