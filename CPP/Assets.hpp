//
//  Assets.hpp
//  CPP
//
//  Created by nltbao on 18/09/2021.
//

#ifndef Assets_hpp
#define Assets_hpp

#include <stdio.h>

class Assets {
public:
    Assets();
    ~Assets();
    
    enum : int {
        IMAGE_PLAYER,
        IM_BULLET
    };
    
    enum : int {
        SOUND_SHOT,
    };
    
    void PreLoadImage();
    void PreLoadMusic();
    void LoadObstacle();

private:
};

#endif /* Assets_hpp */
