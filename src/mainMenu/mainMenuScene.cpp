#include "mainMenuScene.h"

MainMenuScene::MainMenuScene() {
    
}

void MainMenuScene::renderScreen() {
    
}

void MainMenuScene::loadScene() {

}

void MainMenuScene::unloadScene() {

}

SceneList MainMenuScene::startScene() {
    


ClearBackground(RED);
Vector2 ballPosition = { (float)1920/2, (float)1080/2 };
    while(!WindowShouldClose()) {
        
    if (IsKeyDown(KEY_RIGHT)) ballPosition.x += 10.0f;
        if (IsKeyDown(KEY_LEFT)) ballPosition.x -= 10.0f;
        if (IsKeyDown(KEY_UP)) ballPosition.y -= 10.0f;
        if (IsKeyDown(KEY_DOWN)) ballPosition.y += 10.0f;

 BeginDrawing();

            ClearBackground(RED);

            DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);

            DrawCircleV(ballPosition, 50, GREEN);

        EndDrawing();
        
        if(ballPosition.x > 1200) {
  
            return GAMESCENE;    
            break;
        }
    }

    return MAINMENUSCENE;


}

MainMenuScene::~MainMenuScene() {
     
}
