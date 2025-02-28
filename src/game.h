#ifndef SUDOKU_GAME_H
#define SUDOKU_GAME_H
#include "raylib.h"
//#include "sudoku.h"
#include "scene.h"
#include "mainMenu/mainMenuScene.h"
#include "sudoku/gameScene.h"
#include "settings/settingsScene.h"
#include "sceneHandler.h"
#include "sceneList.h"
#include <memory>
#include <stack>
class Game {
    private:
    public:
        Game();
        void playGame() {
            std::unique_ptr<Scene> scene;

            SceneList nextScene = GAMESCENE;
            while (!WindowShouldClose()) {

                switch (nextScene) {
                    case MAINMENUSCENE:
                        scene.reset(new MainMenuScene());
                        break;
                    case GAMESCENE:
                        scene.reset(new GameScene());
                        break;
                    case SETTINGSSCENE: 
                        break;
                    default:
                        scene.reset(new MainMenuScene());
                }


                nextScene = scene->startScene();       

            }
        }
        ~Game();

};


#endif
