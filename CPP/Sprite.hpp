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
    static void addSprite(int type_id, const char *file_name);
    static std::vector<SDL_Texture*> getSprite(int type_id);
    static void drawSprite(int type_id, SDL_Rect* srcRect, SDL_Rect* desRect, int speedAnimation, bool reversed);
private:
};

#endif /* Sprite_hpp */
