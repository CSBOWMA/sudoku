#include "gameScene.h"


GameScene::GameScene() : sudoku(-1), notesMode(false), 
    board(sudoku.getBoard(), sudoku.getNotes(), {614.4, 80}, 1.2),
    inputNumbers(), notesButton({840, 820}, 1),
    autoNotesButton({774, 1040}, .8), timer({1124, 30}, 1)  {

}
void GameScene::renderScreen() {

        BeginDrawing();
        ClearBackground(WHITE);
        board.draw(); 
        board.drawNumbers(collisions);
        
        for (int i = 0; i < 10; i++) {
            inputNumbers.at(i).draw(i+1);
        }
        
        notesButton.draw();
        autoNotesButton.draw();
        timer.draw();
        EndDrawing();


}
void GameScene::loadScene() {


    Vector2 inputNumbersPosition = {632, 900};


    for (int i = 0; i < 10; i++) {
        inputNumbers.at(i).setPosition(inputNumbersPosition.x + i%5*150, inputNumbersPosition.y + i/5*75);
    }

    sudoku.StartLoadedGame(1);
    notesMode = false;

}
void GameScene::unloadScene() {

}

SceneList GameScene::startScene() {
    

    loadScene();    
    std::pair<int, int> selectedSquare = {0, 0};
    int toSetNum = -1;

    while(!WindowShouldClose()) {


        //need to add some functionality to stop repeated input
//        toSetNum = -1;
//        if (IsKeyDown(KEY_ONE)) {
//            toSetNum = 1;
//        } else if (IsKeyDown(KEY_TWO)) { 
//            toSetNum = 2;
//        } else if (IsKeyDown(KEY_THREE)) {
//            toSetNum = 3;
//        } else if (IsKeyDown(KEY_FOUR)) {
//            toSetNum = 4;
//        } else if (IsKeyDown(KEY_FIVE)) {
//            toSetNum = 5;
//        } else if (IsKeyDown(KEY_SIX)) {
//            toSetNum = 6;
//        } else if (IsKeyDown(KEY_SEVEN)) {
//            toSetNum = 7;
//        } else if (IsKeyDown(KEY_EIGHT)) {
//            toSetNum = 8;
//        } else if (IsKeyDown(KEY_NINE)) {
//            toSetNum = 9;
//        } else if (IsKeyDown(KEY_ZERO)) {
//            toSetNum = 0;
//        } else {
//            toSetNum = -1;
//        }
//
//        if(IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT)) {
//            toSetNum = -1;
//
//            if (IsKeyDown(KEY_ONE)) {
//                selectedSquare.first = 0;
//            } else if (IsKeyDown(KEY_TWO)) { 
//                selectedSquare.first = 1;
//            } else if (IsKeyDown(KEY_THREE)) {
//                selectedSquare.first = 2;
//            } else if (IsKeyDown(KEY_FOUR)) {
//                selectedSquare.first = 3;
//            } else if (IsKeyDown(KEY_FIVE)) {
//                selectedSquare.first = 4;
//            } else if (IsKeyDown(KEY_SIX)) {
//                selectedSquare.first = 5;
//            } else if (IsKeyDown(KEY_SEVEN)) {
//                selectedSquare.first = 6;
//            } else if (IsKeyDown(KEY_EIGHT)) {
//                selectedSquare.first = 7;
//            } else if (IsKeyDown(KEY_NINE)) {
//                selectedSquare.first = 8;
//            }
//        }
//
//        if(IsKeyDown(KEY_LEFT_CONTROL) || IsKeyDown(KEY_RIGHT_CONTROL)) {
//            toSetNum = -1;
//            if (IsKeyDown(KEY_ONE)) {
//                selectedSquare.second = 0;
//            } else if (IsKeyDown(KEY_TWO)) { 
//                selectedSquare.second = 1;
//            } else if (IsKeyDown(KEY_THREE)) {
//                selectedSquare.second = 2;
//            } else if (IsKeyDown(KEY_FOUR)) {
//                selectedSquare.second = 3;
//            } else if (IsKeyDown(KEY_FIVE)) {
//                selectedSquare.second = 4;
//            } else if (IsKeyDown(KEY_SIX)) {
//                selectedSquare.second = 5;
//            } else if (IsKeyDown(KEY_SEVEN)) {
//                selectedSquare.second = 6;
//            } else if (IsKeyDown(KEY_EIGHT)) {
//                selectedSquare.second = 7;
//            } else if (IsKeyDown(KEY_NINE)) {
//                selectedSquare.second = 8;
//            }
//        }

        
        //set the tile clicked as the selected tile
        if (board.mouseHovered() && IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            selectedSquare.first = int(GetMousePosition().x-board.getPosition().x)/board.getSmallSquareSize();
            selectedSquare.second = int(GetMousePosition().y-board.getPosition().y)/board.getSmallSquareSize();
        }
       
       

        if (inputNumbers.at(0).mouseHovered() && IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
           toSetNum = 1;  
        }
        
        if (inputNumbers.at(1).mouseHovered() && IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
           toSetNum = 2;  
        }

        if (inputNumbers.at(2).mouseHovered() && IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
           toSetNum = 3;  
        }

        if (inputNumbers.at(3).mouseHovered() && IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
           toSetNum = 4;  
        }

        if (inputNumbers.at(4).mouseHovered() && IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
           toSetNum = 5;  
        }

        if (inputNumbers.at(5).mouseHovered() && IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
           toSetNum = 6;  
        }

        if (inputNumbers.at(6).mouseHovered() && IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
           toSetNum = 7;  
        }

        if (inputNumbers.at(7).mouseHovered() && IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
           toSetNum = 8;  
        }

        if (inputNumbers.at(8).mouseHovered() && IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
           toSetNum = 9;  
        }

        if (inputNumbers.at(9).mouseHovered() && IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
           toSetNum = 0;  
        }
        
        if (notesButton.mouseHovered() && IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            notesButton.invert();
            notesMode = notesButton.isOn(); 
        }

        if(notesMode) {
            sudoku.invertNote(selectedSquare.first, selectedSquare.second, toSetNum);
        } else {

            sudoku.setTile(selectedSquare.first, selectedSquare.second, toSetNum);
        }

        if (autoNotesButton.mouseHovered() && IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            sudoku.initAutoNotes();
        }

        board.setSelectedSquare(selectedSquare);
        
        if (toSetNum > -1) {
            collisions = sudoku.getCollisions();
            if (sudoku.gameWon()) {
                break;
            }
        }

        renderScreen(); 

    }
    unloadScene();    
    return MAINMENUSCENE;
}
GameScene::~GameScene() {

}
