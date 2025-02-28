#ifndef SCENE_H
#define SCENE_H
#include "vector"
#include "memory"
#include "element.h"
#include "raylib.h"
#include "sceneList.h"

class Scene {
   
    Color backgroundColor;
    std::vector<std::unique_ptr<Element>> elements;
    
    public:
    virtual void renderScreen() = 0;
    virtual void loadScene() = 0;
    virtual void unloadScene() = 0;
    virtual SceneList startScene() = 0;
    virtual ~Scene() {}; 
};



#endif
