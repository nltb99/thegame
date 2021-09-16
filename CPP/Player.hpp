//
//  Player.hpp
//  Game
//
//  Created by nltbao on 08/09/2021.
//
#pragma once

#ifndef Player_hpp
#define Player_hpp
#include "GlobalHeader.h"
#include "Bullet.hpp"
#include <vector>

class Player
{
public:
    Player(const char* file_name, const int PLAYER_X, const int PLAYER_Y, const int PLAYER_WIDTH, const int PLAYER_HEIGHT);
    ~Player();
    
    struct DIRECTION {
        const int UP = 0;
        const int DOWN = 1;
        const int LEFT = 2;
        const int RIGHT = 3;
    } DIRECTION;
    
    const int PLAYER_WIDTH, PLAYER_HEIGHT;
    SDL_Texture* b_pPlayerTexture;
    static std::vector<Bullet> g_vBullet_bucket;
    
    SDL_Rect g_playerRect, m_pPlayerCollision;
    int g_lastDirection = DIRECTION.RIGHT;
    
    const int G_JUMP_HEIGHT = -20;
    const float G_JUMP_SPEED = 1;
    const float G_FALL_SPEED = 1.5;
    const int G_MOVE_SPEED = 5;
    const float GROUND_HEIGHT = 500;
    
    void update();
    void draw();
    
    void move_left(const bool bRevert);
    void move_right(const bool bRevert);
    void move_up(const bool bRevert);
    void move_down(const bool bRevert);
    void on_start_jump();
    void on_jump();
    void on_fall();
    void on_short();
    bool bCollision(const int playerX, const int playerY);
    void update_bullet();
    void draw_bullet();
    
private:
    float velocityX = 0;
    float velocityY = 0;
    
    float jumpStep;
    int jump_status = 0;

};

#endif /* Player_hpp */
