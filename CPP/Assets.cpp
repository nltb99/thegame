//
//  Assets.cpp
//  CPP
//
//  Created by nltbao on 18/09/2021.
//

#include "Assets.hpp"
#include "Sprite.hpp"
#include "Music.hpp"

Assets::Assets()
{
    
}

Assets::~Assets()
{
    
}

void Assets::PreLoadImage()
{
    Sprite::addSprite(PLAYER, "assets/imgs/player/Dead__000.png");
    Sprite::addSprite(PLAYER, "assets/imgs/player/Dead__001.png");
    Sprite::addSprite(PLAYER, "assets/imgs/player/Dead__002.png");
    Sprite::addSprite(PLAYER, "assets/imgs/player/Dead__003.png");
    Sprite::addSprite(PLAYER, "assets/imgs/player/Dead__004.png");
    Sprite::addSprite(PLAYER, "assets/imgs/player/Dead__005.png");
    Sprite::addSprite(PLAYER, "assets/imgs/player/Dead__006.png");
    Sprite::addSprite(PLAYER, "assets/imgs/player/Dead__007.png");
    Sprite::addSprite(PLAYER, "assets/imgs/player/Dead__008.png");
    Sprite::addSprite(PLAYER, "assets/imgs/player/Dead__009.png");
}

void Assets::PreLoadMusic()
{
}
