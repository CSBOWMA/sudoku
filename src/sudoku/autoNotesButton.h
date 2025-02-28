#ifndef AUTO_NOTES_BUTTON_H
#define AUTO_NOTES_BUTTON_H

#include "../element.h"

#define AUTO_NOTES_BUTTON_SIZE 40

class AutoNotesButton : public Element{

    public: 
        AutoNotesButton(int x, int y, double sizeScale);
        AutoNotesButton(Vector2 pos, double sizeScale);
        void draw() override;
        bool mouseHovered();

};

#endif



