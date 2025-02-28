#ifndef MAINMENUSCREEN_H
#define MAINMENUSCREEN_H
#include "../scene.h"
#include "../element.h"
#include "raylib.h"


class MainMenuScene : public Scene {

    private:
                 
    public:
    MainMenuScene();
    void renderScreen() override;
    void loadScene() override;
    void unloadScene() override;
    SceneList startScene() override;
    ~MainMenuScene() override;

};


#endif
