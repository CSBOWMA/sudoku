#include "note.h"


int main () {
    Note note(false);
//    Note note2(true);

    note.printNote();
  //  note2.printNote();

    note.invertNote(9);
    note.invertNote(8);
    note.invertNote(7);
    note.invertNote(6);
    note.invertNote(5);
    note.invertNote(4);
    note.invertNote(3);
    note.invertNote(2);
    note.invertNote(1);
    note.printNote();
    note.removeNote(2);
    note.removeNote(4);
    note.printNote();

    note.removeNote(2);
    note.removeNote(4);
    note.printNote();
    note.addNote(2);
    note.addNote(4);
    note.printNote();

    note.addNote(2);
    note.addNote(4);
    note.printNote();

  //  note2.invertNote(3);
    note.printNote();
 //   note.printNote();
}
