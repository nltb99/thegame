//
//  main.cpp
//  Game
//
//  Created by nltbao on 08/09/2021.
//

#include <iostream>
#include "GlobalHeader.h"
#include "Game.hpp"

Game *game = nullptr;

int main()
{
    const int WINDOW_WIDTH = 900;
    const int WINDOW_HEIGHT = 650;
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;
    std::srand(time(NULL));
    
    game = new Game();
    
    game->init("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, false);
    
    while(game->running()){
        
        frameStart = SDL_GetTicks();
        
        game->handleEvents();
        game->render();
        game->update();
        
        frameTime = SDL_GetTicks() - frameStart;
        if(frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
    }
    
    game->clean();
}
