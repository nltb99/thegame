//
//  Bullet.hpp
//  CPP
//
//  Created by nltbao on 11/09/2021.
//
#pragma once

#ifndef Bullet_hpp
#define Bullet_hpp

#include <stdio.h>
#include "GlobalHeader.h"

class Bullet
{
public:
    Bullet(const char* file_name, const int bulletX, const int bulletY, const int bulletWidth, const int bulletHeight, const int m_speedX, const int m_speedY);
    ~Bullet();
    
    static SDL_Texture* b_pBulletTexture;
    static const int G_SPEED_BULLET = 15;
    SDL_Rect rect;
    
    void update(size_t index);
    bool bCollision(const int bulletX, const int bulletY);
    
private:
    int m_speedX, m_speedY;
    int bulletWidth, bulletHeight;
};

#endif /* Bullet_hpp */
