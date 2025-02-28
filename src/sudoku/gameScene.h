#ifndef GAME_SCENE_H
#define GAME_SCENE_H
#include "../scene.h"
#include "boardElement.h"
#include "inputNumber.h"
#include "timer.h"
#include "sudoku.h"
#include "notesButton.h"
#include <array>
#include "autoNotesButton.h"



class MainMenuScene;

class GameScene : public Scene {

    private:
        
    Sudoku sudoku;
    std::unordered_set<std::pair<int,int>, IntPairHash> collisions;
    bool notesMode = false;

    BoardElement board;
    std::array<InputNumber, 10> inputNumbers;
    NotesButton notesButton;
    AutoNotesButton autoNotesButton;
    TimerElement timer;
    public:

        GameScene();
        void renderScreen() override;
        void loadScene() override;
        void unloadScene() override;
        SceneList startScene() override;
        ~GameScene() override;
};

#endif 

