//
//  Player.cpp
//  Game
//
//  Created by nltbao on 08/09/2021.
//

#include "Player.hpp"
#include "Texture.hpp"
#include "Game.hpp"
#include "Sprite.hpp"
#include "Assets.hpp"

std::vector<Bullet> Player::g_vBullet_bucket;

Player::Player(const int PLAYER_X, const int PLAYER_Y, const int PLAYER_WIDTH, const int PLAYER_HEIGHT)
: PLAYER_WIDTH(PLAYER_WIDTH), PLAYER_HEIGHT(PLAYER_HEIGHT)
{
    g_playerRect = { PLAYER_X, PLAYER_Y, PLAYER_WIDTH, PLAYER_HEIGHT };
}

Player::~Player()
{
    g_vBullet_bucket.clear();
}

void Player::draw()
{
    Sprite::drawSprite(Assets::IMAGE_PLAYER, NULL, &g_playerRect, 2, true);
}

void Player::draw_bullet()
{
    for(size_t i = 0; i < g_vBullet_bucket.size(); ++i){
        Texture::DrawTexture(Bullet::b_pBulletTexture, NULL, &g_vBullet_bucket[i].rect);
    }
}

void Player::update()
{
    g_playerRect.x += velocityX;
    
    if(!b_useJump){
        // * Fly Mode
        g_playerRect.y += velocityY;
    } else {
        // * Jump Mode
        this->on_jump();
        this->on_fall();
        velocityY = 0;
    }

    // * Boundaries X
    if((g_playerRect.x < 0) ||
       (g_playerRect.x + PLAYER_WIDTH > Game::SCREEN_WIDTH))
    {
       g_playerRect.x -= velocityX;
    }

    // * Boundaries Y
    if((g_playerRect.y < 0) ||
       (g_playerRect.y + PLAYER_HEIGHT > Game::SCREEN_HEIGHT))
    {
       g_playerRect.y -= velocityY;
    }
    
    if(this->bCollision(g_playerRect.x, g_playerRect.y).boolean) {
        g_playerRect.x -= velocityX;
        g_playerRect.y -= velocityY;
    }

}

void Player::update_bullet()
{
    for(int i = 0; i < g_vBullet_bucket.size(); ++i){
        g_vBullet_bucket[i].update(i);
    }
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

void Player::on_start_jump()
{
    if(jump_status == 0 && b_useJump){
        jump_status = 1;
        velocityY = 0;
        jumpStep = G_JUMP_HEIGHT;
    }
}

void Player::on_jump()
{
    if(jump_status == 1){
        // * Jumping
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
    int adjustX = g_playerRect.x;
    int adjustY = g_playerRect.y;

    if(hold_right) {
        adjustX -= G_MOVE_SPEED;
    } else if(hold_left){
        adjustX += G_MOVE_SPEED;
    }

    if(hold_up) {
        adjustY += G_MOVE_SPEED;
    } else if(hold_down){
        adjustY -= G_MOVE_SPEED;
    }

    if(jump_status == 2){
        // * Falling
        auto statusCollision = this->bCollision(adjustX, adjustY + abs(jumpStep));
        if(statusCollision.boolean){
            g_playerRect.y += statusCollision.colisionRect.y - PLAYER_HEIGHT - (g_playerRect.y + velocityY);
            jump_status = 0;
        } else{
            velocityY += abs(jumpStep);
            g_playerRect.y += velocityY;
            jumpStep += G_FALL_SPEED;
        }
    } else if(jump_status == 0){
        // * Gravity
        if(!this->bCollision(adjustX, adjustY + G_SPEED_GRAVITY).boolean){
            g_playerRect.y += G_SPEED_GRAVITY;
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
    } else {
        throw std::runtime_error("ERROR empty stack");
    }
    
    // * Adjust bullet position
    posY += PLAYER_HEIGHT / 2;
    
    std::unique_ptr<Bullet> bullet = std::make_unique<Bullet>
    (
     "assets/imgs/d1.png", posX, posY, 20, 20, speedX, speedY
    );
    g_vBullet_bucket.emplace_back(*bullet);
}

Player::COLLISION Player::bCollision(const int playerX, const int playerY)
{
    COLLISION ret;
    for(size_t i = 0; i < Game::g_vObstacle_bucket.size(); ++i){
        float objectX = Game::g_vObstacle_bucket[i].rect.x;
        float objectY = Game::g_vObstacle_bucket[i].rect.y;
        float objectWidth = Game::g_vObstacle_bucket[i].rect.w;
        float objectHeight = Game::g_vObstacle_bucket[i].rect.h;

        if(playerX >= objectX - PLAYER_WIDTH + 1 &&
            playerX <= objectX + objectWidth - 1 &&
            playerY >= objectY - PLAYER_HEIGHT + 1 &&
            playerY <= objectY + objectHeight - 1
           ){
            ret.boolean = true;
            ret.colisionRect = Game::g_vObstacle_bucket[i].rect;
        }
    }
    return ret;
}




