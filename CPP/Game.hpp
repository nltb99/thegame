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
#include "Obstacle.hpp"

class Game
{
public:
    Game();
    ~Game();
    
    static const int SCREEN_WIDTH = 900;
    static const int SCREEN_HEIGHT = 650;
    static const int GRID_WIDTH = 25;
    static const int TOTAL_CELL = SCREEN_WIDTH / GRID_WIDTH;
    static std::pair<int, int> globalMap[TOTAL_CELL][TOTAL_CELL];
    
    static SDL_Renderer* renderer;
    static std::vector<Obstacle> obstable_bucket;

    
    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();
    void drawMapVisual();
    bool running(){ return g_bRunning; };
    
private:
    bool g_bRunning;
    SDL_Window *window;
};


#endif /* Game_hpp */
