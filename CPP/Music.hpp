//
//  Music.hpp
//  CPP
//
//  Created by nltbao on 15/09/2021.
//

#ifndef Music_hpp
#define Music_hpp

#include <stdio.h>
#include "GlobalHeader.h"
#include <vector>
#include <unordered_map>

class Music {
public:
    static std::unordered_map<int, Mix_Music*> g_vMusic;
    static std::unordered_map<int, Mix_Chunk*> g_vChunk;
    
    enum LIST_MUSIC {
        chunkShot
    } ;
            
    static void loadChunk(const int music_id, const char* file_name);
    static void loadMusic(const int music_id, const char* file_name);
    
    static void playChunk(const int music_id, const int loop);
    static void playMusic(const int music_id, const int loop);
};
#endif /* Music_hpp */
