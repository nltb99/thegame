//
//  Obstacle.hpp
//  CPP
//
//  Created by nltbao on 12/09/2021.
//
#pragma once

#ifndef Obstacle_hpp
#define Obstacle_hpp

#include <stdio.h>
#include "GlobalHeader.h"

class Obstacle
{
public:
    Obstacle(const int objectX, const int objectY, const int objectWidth, const int objectHeight);
    ~Obstacle();
    
    SDL_Rect rect;
    void draw_obstacle();
    
private:
    int objectX, objectY, objectWidth, objectHeight;
};
#endif /* Obstacle_hpp */
