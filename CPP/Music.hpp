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
#include <map>

class Music {
public:
    Music();
    ~Music();
    std::map<int, Mix_Music*> g_vMusic;
    std::map<int, Mix_Chunk*> g_vChunk;
    
    enum LIST_MUSIC {
        cShot
    } ;
            
    void loadChunk(const int music_id, const char* file_name);
    void loadMusic(const int music_id, const char* file_name);
    
    void playChunk(const int music_id, const int loop);
    void playMusic(const int music_id, const int loop);
};
#endif /* Music_hpp */
