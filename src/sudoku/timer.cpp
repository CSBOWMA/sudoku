#include "timer.h"

#define SECONDS_IN_100_HOURS 60*60*100



TimerElement::TimerElement(int x, int y, double sizeScale) : Element(x, y, sizeScale), startTime(std::chrono::system_clock::now()) {}

TimerElement::TimerElement(Vector2 pos, double sizeScale) : Element(pos.x, pos.y, sizeScale), startTime(std::chrono::system_clock::now()) {}

void TimerElement::restartTimer() {
    startTime = std::chrono::system_clock::now();
}

void TimerElement::draw() {
    std::chrono::seconds elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now()-startTime);
    std::string text("00:00:00");
    if (elapsedTime.count() < SECONDS_IN_100_HOURS) {
        text.at(7) = elapsedTime.count()%10+ '0';
        text.at(6) = elapsedTime.count()/10%6 + '0';
        text.at(5) = ':';
        text.at(4) = elapsedTime.count()/60%10 + '0';
        text.at(3) = elapsedTime.count()/600%6 + '0';
        text.at(2) = ':';
        text.at(1) = elapsedTime.count()/3600%10 + '0';
        text.at(0) = elapsedTime.count()/36000 + '0';

    }
    DrawText(text.c_str(), Element::position.x, Element::position.y, TIMER_FONT_SIZE*sizeScale, BLACK);
}
