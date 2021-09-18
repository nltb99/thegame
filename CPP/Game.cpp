//
//  Game.cpp
//  Game
//
//  Created by nltbao on 08/09/2021.
//

#include "Game.hpp"
#include "Bullet.hpp"
#include "Player.hpp"
#include "Texture.hpp"
#include "Obstacle.hpp"
#include "Music.hpp"
#include "Sprite.hpp"
#include "Assets.hpp"

SDL_Renderer* Game::renderer = nullptr;

std::unique_ptr<Player> player = nullptr;
std::unique_ptr<Music> music = nullptr;
std::unique_ptr<Assets> assets = nullptr;

std::vector<Obstacle> Game::g_vObstacle_bucket;
std::map<int, Game::SPRITE_ELEMENT> Game::g_mSprite_bucket;

Game::Game()
{
}

Game::~Game()
{
    g_vObstacle_bucket.clear();
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if (fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        renderer = SDL_CreateRenderer(window, -1, 0);
        
        music = std::make_unique<Music>();
        assets = std::make_unique<Assets>();
        player = std::make_unique<Player>("assets/imgs/player/Idle__000.png", 50, 100, 50, 100);
        g_vObstacle_bucket.push_back(*std::make_unique<Obstacle>(400, 450, 150, 300));
        g_vObstacle_bucket.push_back(*std::make_unique<Obstacle>(650, 350, 150, 1000));
        
        assets->PreLoadImage();
        

        g_bRunning = true;
    } else{
        g_bRunning = false;
        std::cout << SDL_GetError() << std::endl;
    }
}

void Game::handleEvents()
{
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        if(event.type == SDL_KEYDOWN && event.key.repeat == 0){
            switch(event.key.keysym.sym) {
                case SDLK_LEFT:
                    player->move_left(false);
                    player->hold_left = true;
                    break;
                case SDLK_RIGHT:
                    player->move_right(false);
                    player->hold_right = true;
                    break;
                case SDLK_DOWN:
                    player->move_down(false);
                    break;
                case SDLK_UP:
                    player->move_up(false);
                    break;
                case SDLK_SPACE:
                    player->on_start_jump();
                    break;
                case SDLK_c:
                    music->playMusic(Music::chunkShot, 1);
                    player->on_short();
                    break;
            }
        } else if(event.type == SDL_KEYUP && event.key.repeat == 0) {
            switch(event.key.keysym.sym) {
                case SDLK_LEFT:
                    player->move_right(true);
                    player->hold_left = false;
                    break;
                case SDLK_RIGHT:
                    player->move_left(true);
                    player->hold_right = false;
                    break;
                case SDLK_DOWN:
                    player->move_up(true);
                    break;
                case SDLK_UP:
                    player->move_down(true);
                    break;
            }
        } else if(event.type == SDL_QUIT){
            g_bRunning = false;
        }
    }
 };

void Game::update()
{
    player->update();
    player->update_bullet();
};

void Game::render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    
    player->draw_bullet();
    
    for(size_t i = 0; i < g_vObstacle_bucket.size(); ++i){
        g_vObstacle_bucket[i].draw_obstacle();
    }
    player->draw();
    
    SDL_RenderPresent(renderer);
};

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    Mix_CloseAudio();
    SDL_Quit();
};

