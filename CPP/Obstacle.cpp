//
//  Obstacle.cpp
//  CPP
//
//  Created by nltbao on 12/09/2021.
//

#include "Obstacle.hpp"
#include "Game.hpp"


Obstacle::Obstacle(const int objectX, const int objectY, const int objectWidth, const int objectHeight)
    : objectX(objectX), objectY(objectY), objectWidth(objectWidth), objectHeight(objectHeight)
{
    
}

Obstacle::~Obstacle()
{
    
}

void Obstacle::draw_obstacle()
{
    rect = { objectX, objectY, objectWidth, objectHeight };
    SDL_SetRenderDrawColor(Game::renderer, 0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderFillRect(Game::renderer, &rect );
}

