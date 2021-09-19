//
//  Assets.cpp
//  CPP
//
//  Created by nltbao on 18/09/2021.
//

#include "Assets.hpp"
#include "Sprite.hpp"
#include "Music.hpp"
#include "Obstacle.hpp"
#include "Game.hpp"

Assets::Assets()
{
    
}

Assets::~Assets()
{
    
}

void Assets::PreLoadImage()
{
    Sprite::addSprite(IMAGE_PLAYER, "assets/imgs/player/Dead__000.png");
    Sprite::addSprite(IMAGE_PLAYER, "assets/imgs/player/Dead__001.png");
    Sprite::addSprite(IMAGE_PLAYER, "assets/imgs/player/Dead__002.png");
    Sprite::addSprite(IMAGE_PLAYER, "assets/imgs/player/Dead__003.png");
    Sprite::addSprite(IMAGE_PLAYER, "assets/imgs/player/Dead__004.png");
    Sprite::addSprite(IMAGE_PLAYER, "assets/imgs/player/Dead__005.png");
    Sprite::addSprite(IMAGE_PLAYER, "assets/imgs/player/Dead__006.png");
    Sprite::addSprite(IMAGE_PLAYER, "assets/imgs/player/Dead__007.png");
    Sprite::addSprite(IMAGE_PLAYER, "assets/imgs/player/Dead__008.png");
    Sprite::addSprite(IMAGE_PLAYER, "assets/imgs/player/Dead__009.png");
}

void Assets::PreLoadMusic()
{
    Music::loadMusic(SOUND_SHOT, "assets/sounds/shot.wav");
    Music::loadChunk(SOUND_SHOT, "assets/sounds/shot.wav");
}

void Assets::LoadObstacle()
{
    Game::g_vObstacle_bucket.push_back(*std::make_unique<Obstacle>(400, 450, 150, 300));
    Game::g_vObstacle_bucket.push_back(*std::make_unique<Obstacle>(0, 650 - 150, 900, 150));
    Game::g_vObstacle_bucket.push_back(*std::make_unique<Obstacle>(650, 350, 150, 1000));
}
