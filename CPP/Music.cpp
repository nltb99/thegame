//
//  Music.cpp
//  CPP
//
//  Created by nltbao on 15/09/2021.
//

#include "Music.hpp"

std::unordered_map<int, Mix_Music*> Music::g_vMusic;
std::unordered_map<int, Mix_Chunk*> Music::g_vChunk;

void Music::loadChunk(const int music_id, const char* file_name){
    g_vChunk[music_id] = Mix_LoadWAV(file_name);
}

void Music::loadMusic(const int music_id, const char* file_name){
    g_vMusic[music_id] = Mix_LoadMUS(file_name);
}

void Music::playMusic(const int music_id, const int loop){
    if(Mix_PlayMusic(g_vMusic[music_id], loop) == -1){
        std::cout << SDL_GetError() << std::endl;
    }
}

void Music::playChunk(const int music_id, const int loop){
    if(Mix_PlayChannel(-1, g_vChunk[music_id], loop) == -1){
        std::cout << SDL_GetError() << std::endl;
    }
}

