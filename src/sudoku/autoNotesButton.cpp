#include "autoNotesButton.h"

AutoNotesButton::AutoNotesButton(int x, int y, double sizeScale = 1) : Element(x, y, sizeScale) {
}
AutoNotesButton::AutoNotesButton(Vector2 pos, double sizeScale = 1) : Element(pos.x, pos.y, sizeScale) {
}

void AutoNotesButton::draw() {

    DrawCircle(Element::position.x, Element::position.y, AUTO_NOTES_BUTTON_SIZE*sizeScale, BLACK);
    DrawRectangle(Element::position.x, Element::position.y-AUTO_NOTES_BUTTON_SIZE*sizeScale, AUTO_NOTES_BUTTON_SIZE*sizeScale*12, AUTO_NOTES_BUTTON_SIZE*sizeScale*2, BLACK);
    DrawCircle(Element::position.x+12*AUTO_NOTES_BUTTON_SIZE*sizeScale, Element::position.y, AUTO_NOTES_BUTTON_SIZE*sizeScale, BLACK);
    

    DrawCircle(Element::position.x, Element::position.y, AUTO_NOTES_BUTTON_SIZE*sizeScale*0.8, WHITE);
    DrawRectangle(Element::position.x, Element::position.y-AUTO_NOTES_BUTTON_SIZE*sizeScale*.8, AUTO_NOTES_BUTTON_SIZE*sizeScale*12, AUTO_NOTES_BUTTON_SIZE*sizeScale*1.6, WHITE);
    
    DrawCircle(Element::position.x+12*AUTO_NOTES_BUTTON_SIZE*sizeScale, Element::position.y, AUTO_NOTES_BUTTON_SIZE*sizeScale*0.8, WHITE);
    

    DrawText("AUTO NOTES", Element::position.x+AUTO_NOTES_BUTTON_SIZE*sizeScale*.55, Element::position.y-AUTO_NOTES_BUTTON_SIZE*sizeScale*.7, AUTO_NOTES_BUTTON_SIZE*sizeScale*2*.8, BLACK);
}

bool AutoNotesButton::mouseHovered() {
    return GetMousePosition().x > Element::position.x-AUTO_NOTES_BUTTON_SIZE*sizeScale*.6 && GetMousePosition().x < Element::position.x + AUTO_NOTES_BUTTON_SIZE*sizeScale*12.6 &&
        GetMousePosition().y > Element::position.y-AUTO_NOTES_BUTTON_SIZE*sizeScale*.8 && GetMousePosition().y < Element::position.y + AUTO_NOTES_BUTTON_SIZE*sizeScale;
}

