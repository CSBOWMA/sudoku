#include "game.h"
#include "scene.h"
//#include "gameScene.h"
//#include "settingsScene.h"
#include "sceneHandler.h"
std::stack<std::unique_ptr<Scene>> SceneHandler::Scenes;
Game::Game() {
    InitWindow(1920, 1080, "Sudoku");
    //SetExitKey(KEY_NULL);
    SetTargetFPS(60);
}


Game::~Game() {
    CloseWindow();
}
