#ifndef INPUT_NUMBER_H
#define INPUT_NUMBER_H
#include "../element.h"
#include "raylib.h"

#define INPUT_NUMBER_SIZE 30

class InputNumber : public Element {
    private:

    public:
    InputNumber(int x = 0, int y = 0, double sizeScale = 1);
    InputNumber(Vector2 pos, double sizeScale);
    void setPosition(int x, int y);
    void setPosition(Vector2 pos);

    bool mouseHovered();
    void draw() override;
    void draw(int num);
};

#endif
