#ifndef TIMER_ELEMENT_H
#define TIMER_ELEMENT_H
#include "../element.h"
#include "chrono"
#include <string>
#define TIMER_FONT_SIZE 48


class TimerElement : public Element {
    private:
        std::chrono::time_point<std::chrono::system_clock> startTime;
    public:
    TimerElement(int x, int y, double sizeScale);
    TimerElement(Vector2 pos, double sizeScale);
    void restartTimer();
    void draw() override;


};

#endif
