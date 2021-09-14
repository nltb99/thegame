//
//  Texture.cpp
//  CPP
//
//  Created by nltbao on 09/09/2021.
//

#include "Texture.hpp"
#include "Game.hpp"

SDL_Texture* Texture::LoadTexture(const char* file_name){
    SDL_Surface* tempSurface = IMG_Load(file_name);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    return texture;
}
