//
//  Bullet.cpp
//  CPP
//
//  Created by nltbao on 11/09/2021.
//

#include "Bullet.hpp"
#include "Texture.hpp"
#include "Game.hpp"
#include "Player.hpp"

SDL_Texture* Bullet::b_pBulletTexture;

Bullet::Bullet(const char* file_name, const int bulletX, const int bulletY, const int bulletWidth, const int bulletHeight, const int m_speedX, const int m_speedY)
: bulletWidth(bulletWidth), bulletHeight(bulletHeight), m_speedX(m_speedX), m_speedY(m_speedY)
{
    b_pBulletTexture = Texture::LoadTexture(file_name);
    rect = { bulletX, bulletY, bulletWidth, bulletHeight };
}

Bullet::~Bullet()
{
}

void Bullet::update(size_t index)
{
    if(
       rect.x > Game::SCREEN_WIDTH ||
       rect.y > Game::SCREEN_HEIGHT ||
       this->bCollision(rect.x, rect.y)
       ){
        Player::g_vBullet_bucket.erase(Player::g_vBullet_bucket.begin() + index);
    }
    rect.x += m_speedX;
    rect.y += m_speedY;
}


bool Bullet::bCollision(const int bulletX, const int bulletY)
{
    for(size_t i = 0; i < Game::g_vObstacle_bucket.size(); ++i){
        float objectX = Game::g_vObstacle_bucket[i].rect.x;
        float objectY = Game::g_vObstacle_bucket[i].rect.y;
        float objectWidth = Game::g_vObstacle_bucket[i].rect.w;
        float objectHeight = Game::g_vObstacle_bucket[i].rect.h;
        
        if(
           bulletX >= objectX - bulletWidth + 1 &&
           bulletX <= objectX + objectWidth - 1 &&
           bulletY >= objectY - bulletHeight + 1 &&
           bulletY <= objectY + objectHeight - 1
           ){
            return true;
        }
    }
    return false;
}
