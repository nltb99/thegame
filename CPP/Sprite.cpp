//
//  Sprite.cpp
//  CPP
//
//  Created by nltbao on 17/09/2021.
//

#include "Sprite.hpp"
#include "Texture.hpp"

std::map<int, std::tuple<std::vector<SDL_Texture*>, int, int>> Sprite::b_mSprite_bucket;

void Sprite::addSprite(int type_id, const char *file_name)
{
    std::get<0>(b_mSprite_bucket[type_id]).emplace_back(Texture::LoadTexture(file_name));

}

std::vector<SDL_Texture*> Sprite::getSprite(int type_id)
{
    return std::get<0>(b_mSprite_bucket[type_id]);
}

SDL_Texture* Sprite::drawSprite(int type_id, SDL_Texture* texture, SDL_Rect* srcRect, SDL_Rect* desRect, int speedAnimation)
{
    std::get<2>(b_mSprite_bucket[type_id])++;
    
    if(std::get<2>(b_mSprite_bucket[type_id]) == speedAnimation){
        
        std::get<1>(b_mSprite_bucket[type_id])++;
        texture = std::get<0>(b_mSprite_bucket[type_id])[std::get<1>(b_mSprite_bucket[type_id])];
        
        if(std::get<1>(b_mSprite_bucket[type_id]) >= std::get<0>(b_mSprite_bucket[type_id]).size() - 1){
            std::get<1>(b_mSprite_bucket[type_id])= 0;
        }
        
        std::get<2>(b_mSprite_bucket[type_id]) = 0;
    }
    
    std::cout << std::get<1>(b_mSprite_bucket[type_id]) << " " << std::get<2>(b_mSprite_bucket[type_id]) << std::endl;
//    Texture::DrawTexture(texture, srcRect, desRect);
    return texture;
    

        
}
