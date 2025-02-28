#include "inputNumber.h"
InputNumber::InputNumber(int x, int y, double sizeScale) : Element(x,y,sizeScale) {

}
InputNumber::InputNumber(Vector2 pos, double sizeScale) : Element(pos.x,pos.y,sizeScale) {

}

void InputNumber::setPosition(int x, int y) {
    Element::position.x = x;
    Element::position.y = y;
}

void InputNumber::setPosition(Vector2 pos) {
    Element::position.x = pos.x;
    Element::position.y = pos.y;
}

bool InputNumber::mouseHovered() {
    return GetMousePosition().x > Element::position.x-INPUT_NUMBER_SIZE*sizeScale*.4 && GetMousePosition().x < Element::position.x + INPUT_NUMBER_SIZE*sizeScale*2.4 &&
        GetMousePosition().y > Element::position.y-INPUT_NUMBER_SIZE*sizeScale*.8 && GetMousePosition().y < Element::position.y + INPUT_NUMBER_SIZE*sizeScale*1.6;
}
void InputNumber::draw() {
    DrawCircle(Element::position.x, Element::position.y, INPUT_NUMBER_SIZE*sizeScale, BLACK);
    DrawRectangle(Element::position.x, Element::position.y-INPUT_NUMBER_SIZE*sizeScale, INPUT_NUMBER_SIZE*sizeScale*2, INPUT_NUMBER_SIZE*sizeScale*2, BLACK);
    DrawCircle(Element::position.x+2*INPUT_NUMBER_SIZE*sizeScale, Element::position.y, INPUT_NUMBER_SIZE*sizeScale, BLACK);

    DrawCircle(Element::position.x, Element::position.y, INPUT_NUMBER_SIZE*sizeScale*0.8, GRAY);
    DrawRectangle(Element::position.x, Element::position.y-INPUT_NUMBER_SIZE*sizeScale*.8, INPUT_NUMBER_SIZE*sizeScale*2, INPUT_NUMBER_SIZE*sizeScale*1.6, GRAY);
    DrawCircle(Element::position.x+2*INPUT_NUMBER_SIZE*sizeScale, Element::position.y, INPUT_NUMBER_SIZE*sizeScale*0.8, GRAY);


}


void InputNumber::draw(int num) {
    num = num * (num >= 0 && num <= 9);
    char buff[1];
    buff[0] = num + '0';
    DrawCircle(Element::position.x, Element::position.y, INPUT_NUMBER_SIZE*sizeScale, BLACK);
    DrawRectangle(Element::position.x, Element::position.y-INPUT_NUMBER_SIZE*sizeScale, INPUT_NUMBER_SIZE*sizeScale*2, INPUT_NUMBER_SIZE*sizeScale*2, BLACK);
    DrawCircle(Element::position.x+2*INPUT_NUMBER_SIZE*sizeScale, Element::position.y, INPUT_NUMBER_SIZE*sizeScale, BLACK);

    DrawCircle(Element::position.x, Element::position.y, INPUT_NUMBER_SIZE*sizeScale*0.8, GRAY);
    DrawRectangle(Element::position.x, Element::position.y-INPUT_NUMBER_SIZE*sizeScale*.8, INPUT_NUMBER_SIZE*sizeScale*2, INPUT_NUMBER_SIZE*sizeScale*1.6, GRAY);
    DrawCircle(Element::position.x+2*INPUT_NUMBER_SIZE*sizeScale, Element::position.y, INPUT_NUMBER_SIZE*sizeScale*0.8, GRAY);

    DrawText(buff, Element::position.x+INPUT_NUMBER_SIZE*sizeScale*.5, Element::position.y-INPUT_NUMBER_SIZE*sizeScale*.8, INPUT_NUMBER_SIZE*sizeScale*2*.9, BLACK);

}
