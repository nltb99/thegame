//
//  Sprite.cpp
//  CPP
//
//  Created by nltbao on 17/09/2021.
//

#include "Sprite.hpp"
#include "Texture.hpp"
#include "Game.hpp"

void Sprite::addSprite(int type_id, const char *file_name)
{
    Game::g_mSprite_bucket[type_id].vt.emplace_back(Texture::LoadTexture(file_name));
}

std::vector<SDL_Texture*> Sprite::getSprite(int type_id)
{
    return Game::g_mSprite_bucket[type_id].vt;
}

void Sprite::drawSprite(int type_id, SDL_Rect* srcRect, SDL_Rect* desRect, int speedAnimation, bool reversed)
{
    auto* vectorSprite = &Game::g_mSprite_bucket[type_id].vt;
    int* currentIndex = &Game::g_mSprite_bucket[type_id].currentIndex;
    int* currentTick = &Game::g_mSprite_bucket[type_id].currentFrame;
    bool* bAscending = &Game::g_mSprite_bucket[type_id].bAscending;
    int* delta = &Game::g_mSprite_bucket[type_id].delta;
    int sizeVector = static_cast<int>((*vectorSprite).size());
    
    if (sizeVector == 0) {
        return;
    }
    
    SDL_Texture* texture = (*vectorSprite)[(*currentIndex)];
    
    if((*currentTick) == speedAnimation && sizeVector > 1){
    
        if(reversed){
            if(((*currentIndex) >= sizeVector - 1) && *bAscending){
                *delta = -1;
                *bAscending = false;
            } else if((*currentIndex) <= 0 && !(*bAscending)){
                *delta = 1;
                *bAscending = true;
            }
        }
        
        if(!reversed){
            if(*currentIndex >= sizeVector){
                *currentIndex = 0;
            }
        }
               
        texture = (*vectorSprite)[(*currentIndex)];
        
        (*currentTick) = 0;
        (*currentIndex) += *delta;
    }
    
    (*currentTick)++;
    
    Texture::DrawTexture(texture, srcRect, desRect);
}
