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
        PLAYER,
        BULLET
    };
    
    void PreLoadImage();
    void PreLoadMusic();
private:
};

#endif /* Assets_hpp */
