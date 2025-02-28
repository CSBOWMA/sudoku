#ifndef SUDOKU_BOARD_ELEMENT
#define SUDOKU_BOARD_ELEMENT
#include "../element.h"
#include "raylib.h"
#include <stdlib.h>
#include <array>
#include <memory>
#include <unordered_set>
#include "note.h"
#include "tile.h"
#include "intPairHash.h"

#define BASE_BOARD_SIZE 576

class BoardElement : public Element {

    private:
        std::pair<int,int> selectedSquare;
        double smallRectangleSize;
        Color tileTint;
        Color lineColors;
        Color presetSquareColor;
        void drawRowHighlight();
        void drawColumnHighlight();
        void drawSquareHighlight();
        void drawPresetSquares();
        const std::shared_ptr<std::array<std::array<Tile, 9>, 9>> board;
        const std::shared_ptr<std::array<std::array<Note, 9>, 9>> notes;
    public:
        BoardElement(std::shared_ptr<std::array<std::array<Tile, 9>, 9>> board, 
                std::shared_ptr<std::array<std::array<Note, 9>, 9>> notes,
                int x, int y, double sizeScale);
        BoardElement(std::shared_ptr<std::array<std::array<Tile, 9>, 9>> board,
                std::shared_ptr<std::array<std::array<Note, 9>, 9>> notes,
                Vector2 position, double sizeScale);
        void draw() override;
        void drawNumbers(std::unordered_set<std::pair<int,int>, IntPairHash> collisions);
        bool mouseHovered();
        void setSelectedSquare(std::pair<int,int> selectedSquare);
        double getSmallSquareSize();        
        Vector2 getPosition();
};


#endif
