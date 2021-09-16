//
//  Music.cpp
//  CPP
//
//  Created by nltbao on 15/09/2021.
//

#include "Music.hpp"

Music::Music()
{
    Mix_OpenAudio( MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096);
    Mix_VolumeMusic(100);
    
    this->loadMusic(cShot, "assets/sounds/shot.wav");
    this->loadChunk(cShot, "assets/sounds/shot.wav");
}

Music::~Music()
{
    for(int i = 0; i < g_vMusic.size(); i++) {
        Mix_FreeMusic(g_vMusic[i]);
    }
    
    for(int i = 0; i < g_vChunk.size(); i++) {
        Mix_FreeChunk(g_vChunk[i]);
    }
    
    g_vMusic.clear();
    g_vChunk.clear();
}

void Music::loadChunk(const int music_id, const char* file_name){
    g_vChunk.insert(std::make_pair(music_id, Mix_LoadWAV(file_name)));
}

void Music::loadMusic(const int music_id, const char* file_name){
    g_vMusic.insert(std::make_pair(music_id, Mix_LoadMUS(file_name)));
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

