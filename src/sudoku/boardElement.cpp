#include "boardElement.h"



BoardElement::BoardElement(std::shared_ptr<std::array<std::array<Tile, 9>, 9>> board, 
        std::shared_ptr<std::array<std::array<Note, 9>, 9>> notes, 
        int x, int y, double sizeScale = 1) : Element(x, y, sizeScale), board(board), notes(notes) {
    selectedSquare.first = -1;
    selectedSquare.second = -1;
    smallRectangleSize = BASE_BOARD_SIZE*Element::sizeScale/9;
    presetSquareColor.r = 0;
    presetSquareColor.g = 0;
    presetSquareColor.b = 0;
    presetSquareColor.a = 20;

    tileTint.r = 0;
    tileTint.g = 0;
    tileTint.b = 255;
    tileTint.a = 20;

    lineColors.r = 0;
    lineColors.g = 0;
    lineColors.b = 0;
    lineColors.a = 255;

}

BoardElement::BoardElement(std::shared_ptr<std::array<std::array<Tile, 9>, 9>> board,
       std::shared_ptr<std::array<std::array<Note, 9>, 9>> notes,
       Vector2 position, double sizeScale = 1) : Element(position, sizeScale), board(board), notes(notes) {
    selectedSquare.first = -1;
    selectedSquare.second = -1;
    smallRectangleSize = BASE_BOARD_SIZE*Element::sizeScale/9;

    presetSquareColor.r = 0;
    presetSquareColor.g = 0;
    presetSquareColor.b = 0;
    presetSquareColor.a = 20;

    tileTint.r = 0;
    tileTint.g = 0;
    tileTint.b = 255;
    tileTint.a = 40;

    lineColors.r = 0;
    lineColors.g = 0;
    lineColors.b = 0;
    lineColors.a = 255;

}

void BoardElement::drawRowHighlight() { 
    Rectangle currentRectangle;

    //highlight row
    currentRectangle.y = Element::position.y+selectedSquare.second*smallRectangleSize;
    currentRectangle.width = smallRectangleSize;
    currentRectangle.height = smallRectangleSize;
    for(int i = 0; i < 9; i++) { 
        currentRectangle.x = Element::position.x+i*smallRectangleSize;
        DrawRectangleRec(currentRectangle, tileTint);
    } 
}

void BoardElement::drawColumnHighlight() {

    Rectangle currentRectangle;
    //highlight column
    currentRectangle.x = Element::position.x+selectedSquare.first*smallRectangleSize;
    currentRectangle.width = smallRectangleSize;
    currentRectangle.height = smallRectangleSize;
    for(int i = 0; i < 9; i++) { 
        currentRectangle.y = Element::position.y+i*smallRectangleSize;
        DrawRectangleRec(currentRectangle, tileTint);
    } 
}


void BoardElement::drawSquareHighlight() {

    Rectangle currentRectangle;
    currentRectangle.width = smallRectangleSize;
    currentRectangle.height = smallRectangleSize;

    int x, y, xOffset, yOffset;

    x = ((int)selectedSquare.first)%3;
    xOffset = ((int)selectedSquare.first)/3;

    y = ((int)selectedSquare.second)%3;
    yOffset = ((int)selectedSquare.second)/3;

    for (int i = (y+1)%3; i != y; i = (i+1)%3) {
        for(int j = (x+1)%3; j != x; j = (j+1)%3) {
            currentRectangle.y = Element::position.y+(i+yOffset*3)*smallRectangleSize;
            currentRectangle.x = Element::position.x+(j+xOffset*3)*smallRectangleSize;
            DrawRectangleRec(currentRectangle, tileTint);
        }
    }
}

void BoardElement::drawPresetSquares() {

    Rectangle currentRectangle;
    currentRectangle.width = smallRectangleSize;
    currentRectangle.height = smallRectangleSize;
    for(int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            presetSquareColor.a = board->at(i).at(j).getPreset()*50;         
            currentRectangle.y = Element::position.y+j*smallRectangleSize;
            currentRectangle.x = Element::position.x+i*smallRectangleSize;
            DrawRectangleRec(currentRectangle, presetSquareColor);
        }
    }

}

void BoardElement::draw() {

    Rectangle currentRectangle;

    currentRectangle.height = smallRectangleSize;
    currentRectangle.width = smallRectangleSize;
    //draw boardbackground
    DrawRectangle(Element::position.x, Element::position.y, BASE_BOARD_SIZE*Element::sizeScale, BASE_BOARD_SIZE*Element::sizeScale, WHITE);

    char currchar[1];

    //draw alternate tiles
    //  for (int i = 0; i < 9; i++) {
    //      for (int j = i%2; j < 9; j += 2) {
    //          currentRectangle.x = Element::position.x+j*smallRectangleSize;
    //          currentRectangle.y = Element::position.y+i*smallRectangleSize;

    //          DrawRectangleRec(currentRectangle, altTileColor);
    //      }
    //  }


    //highlight selected row and column
    if ((selectedSquare.first >= 0 && selectedSquare.second >= 0)) [[likely]] {

        drawRowHighlight();
        drawColumnHighlight();
        drawSquareHighlight();
    }
    drawPresetSquares();


    //draw lines around boxes

    //draw horizontal lines
    currentRectangle.width = BASE_BOARD_SIZE*Element::sizeScale;
    currentRectangle.height = 2; 
    currentRectangle.x = Element::position.x;
    for (int i = 0; i < 10; i++) {
        currentRectangle.y = Element::position.y+i*smallRectangleSize-currentRectangle.height/2;
        DrawRectangleRec(currentRectangle, lineColors);
    }

    //draw horizontal large lines
    currentRectangle.height = 4;
    currentRectangle.x -= currentRectangle.height/2;
    currentRectangle.width += currentRectangle.height;
    for (int i = 0; i < 10; i += 3) {
        currentRectangle.y = Element::position.y+i*smallRectangleSize-currentRectangle.height/2;
        DrawRectangleRec(currentRectangle, lineColors);
    }

    //draw vertical lines
    currentRectangle.width = 2;
    currentRectangle.height = BASE_BOARD_SIZE*Element::sizeScale;
    currentRectangle.y = Element::position.y;
    for (int i = 0; i < 10; i++) {
        currentRectangle.x = Element::position.x+i*smallRectangleSize-currentRectangle.width/2;
        DrawRectangleRec(currentRectangle, lineColors);
    }



    currentRectangle.width = 4;
    currentRectangle.y -= currentRectangle.width/2;
    currentRectangle.height += currentRectangle.width;
    for (int i = 0; i < 10; i += 3) {
        currentRectangle.x = Element::position.x+i*smallRectangleSize-currentRectangle.width/2;
        DrawRectangleRec(currentRectangle, lineColors);
    }

}

void BoardElement::drawNumbers(std::unordered_set<std::pair<int,int>, IntPairHash> collisions) {
    char currChar[1];
    for (int i = 0; i < 9; i++) {    
        for(int j = 0; j < 9; j++) {
            currChar[0] = board->at(i).at(j).getNumber(true);
            if (currChar[0] > '0') { 

                if (collisions.find({i,j}) == collisions.end()) {
                    DrawText(currChar, position.x+smallRectangleSize*i+16, position.y+4+smallRectangleSize*j, smallRectangleSize, BLACK);
                } else {
                    DrawText(currChar, position.x+smallRectangleSize*i+16, position.y+4+smallRectangleSize*j, smallRectangleSize, RED);
                }
            } else {
                for (int k = 1; k <= 9; k++) {
                    currChar[0] = k+'0';
                    if (notes->at(i).at(j).contains(k)) {

                    DrawText(currChar, position.x+smallRectangleSize*(i+((double)((k-1)%3)/3))+ 6, 
                            position.y+smallRectangleSize*(j+((double)((k-1)/3)/3)) + 6, 
                            smallRectangleSize/4, BLACK);
                    }
                }
            }
        }
    }
}


bool BoardElement::mouseHovered() {
    return GetMousePosition().x >  Element::position.x && GetMousePosition().y > Element::position.y && 
        GetMousePosition().x < Element::position.x + BASE_BOARD_SIZE*sizeScale && 
        GetMousePosition().y < Element::position.y + BASE_BOARD_SIZE*sizeScale;
}

void BoardElement::setSelectedSquare(std::pair<int,int> selectedSquare) {
    this->selectedSquare = selectedSquare;
}

double BoardElement::getSmallSquareSize() {
    return BASE_BOARD_SIZE/9.0*sizeScale; 
}

Vector2 BoardElement::getPosition() {
    return Element::position;
}

