#ifndef ELEMENT_H
#define ELEMENT_H

#include "raylib.h"

    class Element {
        protected:
        Vector2 position;
        double sizeScale;

        public:
        Element(int x, int y, double sizeScale = 1) {
            position.x = x;
            position.y = y;
            this->sizeScale = sizeScale;
        }
        Element(Vector2 position, double sizeScale = 1) {
            this->position = position;
            this->sizeScale = sizeScale;
        }
        virtual void draw() = 0;
    //    virtual void getCollsionBox() = 0;
    };

#endif 
