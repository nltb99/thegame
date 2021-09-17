//
//  Sprite.hpp
//  CPP
//
//  Created by nltbao on 17/09/2021.
//

#ifndef Sprite_hpp
#define Sprite_hpp

#include <stdio.h>
#include <map>
#include <vector>
#include <tuple>
#include "GlobalHeader.h"

class Sprite {
public:
    
    enum : int {
        PLAYER,
        BULLET
    };
    
    // 1 : vector sprite
    // 2 : current indice of vector
    // 3 : speed based on SDL_GetTicks()
    static std::map<int, std::tuple<std::vector<SDL_Texture*>, int, int>> b_mSprite_bucket;
    
    static void addSprite(int type_id, const char *file_name);
    static std::vector<SDL_Texture*> getSprite(int type_id);
    static SDL_Texture* drawSprite(int type_id, SDL_Texture* texture, SDL_Rect* srcRect, SDL_Rect* desRect, int speedAnimation);
    
    
    
private:
};

#endif /* Sprite_hpp */
