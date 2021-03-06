//
//  Game.hpp
//  Game
//
//  Created by nltbao on 08/09/2021.
//
#pragma once

#ifndef Game_hpp
#define Game_hpp
#include "GlobalHeader.h"
#include <time.h>
#include <vector>
#include <unordered_map>
#include "Obstacle.hpp"

class Game
{
public:
    Game();
    ~Game();
    
    static const int SCREEN_WIDTH = 900;
    static const int SCREEN_HEIGHT = 650;
    
    static SDL_Renderer* renderer;
    static std::vector<Obstacle> g_vObstacle_bucket;
    
    typedef struct SPRITE_ELEMENT {
        std::vector<SDL_Texture*> vt;
        int currentFrame = 0;
        int currentIndex = 0;
        bool bAscending = true;
        int delta = 1;
    } SPRITE_ELEMENT;
        
    static std::unordered_map<int, SPRITE_ELEMENT> g_mSprite_bucket;


    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();
    bool running(){ return g_bRunning; };
    
private:
    bool g_bRunning;
    SDL_Window *window;
};


#endif /* Game_hpp */
