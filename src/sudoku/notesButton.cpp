#include "notesButton.h"




NotesButton::NotesButton(int x, int y, double sizeScale = 1) : Element(x, y, sizeScale), on(false){
}
NotesButton::NotesButton(Vector2 pos, double sizeScale = 1) : Element(pos.x, pos.y, sizeScale), on(false) {
}

void NotesButton::draw() {

    DrawCircle(Element::position.x, Element::position.y, NOTES_BUTTON_SIZE*sizeScale, BLACK);
    DrawRectangle(Element::position.x, Element::position.y-NOTES_BUTTON_SIZE*sizeScale, NOTES_BUTTON_SIZE*sizeScale*6, NOTES_BUTTON_SIZE*sizeScale*2, BLACK);
    DrawCircle(Element::position.x+6*NOTES_BUTTON_SIZE*sizeScale, Element::position.y, NOTES_BUTTON_SIZE*sizeScale, BLACK);
    
    Color buttonColor;
    Color textColor;
    
    buttonColor.r = 130*!on;
    buttonColor.g = 130*!on;
    buttonColor.b = 130*!on+255*on;
    buttonColor.a = 255;

    textColor.r = 255*on;
    textColor.g = 255*on;
    textColor.b = 255*on;
    textColor.a = 255;

    DrawCircle(Element::position.x, Element::position.y, NOTES_BUTTON_SIZE*sizeScale*0.8, buttonColor);
    DrawRectangle(Element::position.x, Element::position.y-NOTES_BUTTON_SIZE*sizeScale*.8, NOTES_BUTTON_SIZE*sizeScale*6, NOTES_BUTTON_SIZE*sizeScale*1.6, buttonColor);
    
    DrawCircle(Element::position.x+6*NOTES_BUTTON_SIZE*sizeScale, Element::position.y, NOTES_BUTTON_SIZE*sizeScale*0.8, buttonColor);
    

    DrawText("notes", Element::position.x+NOTES_BUTTON_SIZE*sizeScale*.5, Element::position.y-NOTES_BUTTON_SIZE*sizeScale*.8, NOTES_BUTTON_SIZE*sizeScale*2*.9, textColor);
}

bool NotesButton::mouseHovered() {
    return GetMousePosition().x > Element::position.x-NOTES_BUTTON_SIZE*sizeScale*.6 && GetMousePosition().x < Element::position.x + NOTES_BUTTON_SIZE*sizeScale*6.6 &&
        GetMousePosition().y > Element::position.y-NOTES_BUTTON_SIZE*sizeScale*.8 && GetMousePosition().y < Element::position.y + NOTES_BUTTON_SIZE*sizeScale;
}

void NotesButton::invert() {
    on = !on;
}

bool NotesButton::isOn() {
    return on;
}
