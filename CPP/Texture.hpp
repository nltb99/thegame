//
//  Texture.hpp
//  CPP
//
//  Created by nltbao on 09/09/2021.
//
#pragma once

#ifndef Texture_hpp
#define Texture_hpp
#include "GlobalHeader.h"
#include <stdio.h>

class Texture {
public:
    static SDL_Texture* LoadTexture(const char* file_name);
    static void DrawTexture(SDL_Texture* texture, SDL_Rect* srcRect, SDL_Rect* desRect);
private:
};

#endif /* Texture_hpp */
