#ifndef SCENEHANDLER_H
#define SCENEHANDLER_H

#include "memory"
#include "stack"
#include "scene.h"
#include "sceneList.h"


class SceneHandler {
    private:
    public:
        static std::stack<std::unique_ptr<Scene>> Scenes; //only top scene is currently active, but can handle multiple scenes
        
        
        static void InitializeFirstScene(std::unique_ptr<Scene>& firstScene) {
            Scenes.push(std::move(firstScene));
        }
        static SceneList playCurrentScene() {
            return Scenes.top()->startScene();
        } 
        static void swapCurrentScene(std::unique_ptr<Scene>& newScene) { 
            Scenes.top().swap(newScene);            
        }
        static void emptyScenesSetCurrent(std::unique_ptr<Scene>& scene) {
            
        }
        static void swapCurrentSceneAndTemporary() {

        }
        static void moveCurrentSceneToTemporary();
        static void moveTemporarySceneToCurrent();
        static void addNewSceneToTemporary(Scene* newScene);
        static void addNewSceneToTemporary(std::unique_ptr<Scene>& newScene); 
        static void deleteTemporaryScene();
    //purely static function, this makes it impossible to create an instance
    SceneHandler() = delete;        
};


#endif
