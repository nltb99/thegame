//
//  Player.cpp
//  Game
//
//  Created by nltbao on 08/09/2021.
//

#include "Player.hpp"
#include "Texture.hpp"
#include "Game.hpp"

SDL_Texture* Player::b_pPlayerTexture;

std::vector<Bullet> Player::bullet_bucket;

Player::Player()
: g_playerRect({ 200, 100, PLAYER_WIDTH, PLAYER_HEIGHT})
{
    b_pPlayerTexture = Texture::LoadTexture("d1.png");
}

Player::~Player()
{
    
}

void Player::init()
{
    
}

void Player::move_up(const bool bRevert)
{
    velocityY -= G_MOVE_SPEED;
}

void Player::move_down(const bool bRevert)
{
    velocityY += G_MOVE_SPEED;
}

void Player::move_left(const bool bRevert)
{
    velocityX -= G_MOVE_SPEED;
    if(!bRevert){
        g_lastDirection = DIRECTION.LEFT;
    }
}

void Player::move_right(const bool bRevert)
{
    velocityX += G_MOVE_SPEED;
    if(!bRevert){
        g_lastDirection = DIRECTION.RIGHT;
    }
}


void Player::update_move()
{
    g_playerRect.x += velocityX;
    
    // JUMP
    Player::on_jump();
    Player::on_fall();
    
    // BOUNDARIES
    if(
       (g_playerRect.x < 0) ||
       (g_playerRect.x + PLAYER_WIDTH > Game::SCREEN_WIDTH)||
       this->bCollisionObject(g_playerRect.x, g_playerRect.y)
       )
    {
       g_playerRect.x -= velocityX;
    }
    
    if(
       (g_playerRect.y < 0) ||
       (g_playerRect.y + PLAYER_HEIGHT > Game::SCREEN_HEIGHT) ||
       (g_playerRect.y > GROUND_HEIGHT))
    {
       g_playerRect.y -= velocityY;
    }
    
    velocityY = 0;
}

void Player::on_start_jump()
{
    if(jump_status == 0){
        jump_status = 1;
        velocityY = 0;
        jumpStep = G_JUMP_HEIGHT;
    }
}

void Player::on_jump()
{
    if(jump_status == 1){
        velocityY += -abs(jumpStep);
        g_playerRect.y += velocityY;
        jumpStep += G_JUMP_SPEED;
        if(jumpStep > 0) {
            jump_status = 2;
        }
    }
}

void Player::on_fall()
{
    if(jump_status == 2){
        if(this->bCollisionObject(g_playerRect.x, g_playerRect.y + abs(jumpStep))){
            g_playerRect.y += m_pPlayerCollision.y - PLAYER_HEIGHT - (g_playerRect.y + velocityY);
            jump_status = 0;
        } else{
            velocityY += abs(jumpStep);
            g_playerRect.y += velocityY;
            jumpStep += G_FALL_SPEED;
        }

        bool bTouchGround = g_playerRect.y + velocityY + jumpStep > GROUND_HEIGHT;
        if(bTouchGround){
            g_playerRect.y += GROUND_HEIGHT - g_playerRect.y;
            jump_status = 0;
        }

    } else if(jump_status == 0){
        if(!this->bCollisionObject(g_playerRect.x, g_playerRect.y + G_MOVE_SPEED)){
            g_playerRect.y += G_MOVE_SPEED * G_MOVE_SPEED * 0.8;
        }
    }
}

void Player::on_short()
{
    int posX, posY, speedX, speedY;
    
    if(g_lastDirection == DIRECTION.RIGHT) {
        posX = g_playerRect.x + PLAYER_WIDTH;
        posY = g_playerRect.y;
        speedX = Bullet::G_SPEED_BULLET;
        speedY = 0;
    } else if(g_lastDirection == DIRECTION.LEFT){
        posX = g_playerRect.x;
        posY = g_playerRect.y;
        speedX = -Bullet::G_SPEED_BULLET;
        speedY = 0;
    }
    
    std::unique_ptr<Bullet> bullet = std::make_unique<Bullet>
    (
     "d1.png", posX, posY, 20, 20, speedX, speedY
    );
    bullet_bucket.emplace_back(*bullet);
}

bool Player::bCollisionObject(const int playerX, const int playerY)
{
    for(size_t i = 0; i < Game::obstable_bucket.size(); ++i){
        float objectX = Game::obstable_bucket[i].obstacleRect.x;
        float objectY = Game::obstable_bucket[i].obstacleRect.y;
        float objectWidth = Game::obstable_bucket[i].obstacleRect.w;
        float objectHeight = Game::obstable_bucket[i].obstacleRect.h;
        
        if(
           (playerX >= objectX - PLAYER_WIDTH + 1 &&
            playerX <= objectX + objectWidth - 1 &&
            playerY >= objectY - PLAYER_HEIGHT + 1 &&
            playerY <= objectY + objectHeight - 1 ) ||
           (playerY > GROUND_HEIGHT)
           ){
            m_pPlayerCollision = Game::obstable_bucket[i].obstacleRect;
            return true;
        }
    }
    return false;
}
