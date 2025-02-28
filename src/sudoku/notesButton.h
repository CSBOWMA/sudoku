#ifndef NOTES_BUTTON_H
#define NOTES_BUTTON_H
#include "../element.h"
#include "raylib.h"
#define NOTES_BUTTON_SIZE 40


class NotesButton : public Element {
    private:
        bool on;
    public:
        NotesButton(int x, int y, double sizeScale);
        NotesButton(Vector2 pos, double sizeScale);
        void draw() override;
        void invert();
        bool isOn();
        bool mouseHovered();
};

#endif
