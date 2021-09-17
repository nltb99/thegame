//
//  Texture.cpp
//  CPP
//
//  Created by nltbao on 09/09/2021.
//

#include "Texture.hpp"
#include "Game.hpp"

SDL_Texture* Texture::LoadTexture(const char* file_name)
{
    SDL_Surface* tempSurface = IMG_Load(file_name);
    if(!tempSurface){
        std::cout << SDL_GetError() << std::endl;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    return texture;
}

void Texture::DrawTexture(SDL_Texture* texture, SDL_Rect* srcRect, SDL_Rect* desRect)
{
    SDL_RenderCopy(Game::renderer, texture, srcRect, desRect);
}
