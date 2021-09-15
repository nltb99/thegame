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
: bulletRect({bulletX, bulletY, bulletWidth, bulletHeight}), bulletWidth(bulletWidth), bulletHeight(bulletHeight), m_speedX(m_speedX), m_speedY(m_speedY)
{
    b_pBulletTexture = Texture::LoadTexture(file_name);
}

Bullet::~Bullet()
{
}

void Bullet::update(size_t index)
{
    if(
       bulletRect.x > Game::SCREEN_WIDTH ||
       bulletRect.y > Game::SCREEN_HEIGHT ||
       this->bCollision(bulletRect.x, bulletRect.y)
       ){
        Player::bullet_bucket.erase(Player::bullet_bucket.begin() + index);
    }
    bulletRect.x += m_speedX;
    bulletRect.y += m_speedY;
}


bool Bullet::bCollision(const int bulletX, const int bulletY)
{
    for(size_t i = 0; i < Game::obstable_bucket.size(); ++i){
        float objectX = Game::obstable_bucket[i].obstacleRect.x;
        float objectY = Game::obstable_bucket[i].obstacleRect.y;
        float objectWidth = Game::obstable_bucket[i].obstacleRect.w;
        float objectHeight = Game::obstable_bucket[i].obstacleRect.h;
        
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
