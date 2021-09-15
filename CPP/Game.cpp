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

SDL_Renderer* Game::renderer = nullptr;
std::pair<int, int> Game::globalMap[TOTAL_CELL][TOTAL_CELL];

std::unique_ptr<Player> player = nullptr;
std::vector<Obstacle> Game::obstable_bucket;

Game::Game(){
}
Game::~Game(){}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if (fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        renderer = SDL_CreateRenderer(window, -1, 0);
        
        player = std::make_unique<Player>();
        
        obstable_bucket.push_back(*std::make_unique<Obstacle>(400, 450, 150, 300));
        obstable_bucket.push_back(*std::make_unique<Obstacle>(650, 350, 150, 400));
        
        g_bRunning = true;
    } else{
        g_bRunning = false;
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
                    break;
                case SDLK_RIGHT:
                    player->move_right(false);
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
                    player->on_short();
                    break;
            }
        } else if(event.type == SDL_KEYUP && event.key.repeat == 0) {
            switch(event.key.keysym.sym) {
                case SDLK_LEFT:
                    player->move_right(true);
                    break;
                case SDLK_RIGHT:
                    player->move_left(true);
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
    player->update_move();
    player->update_bullet();
};

void Game::render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    
    player->draw_bullet();
    
    for(size_t i = 0; i < obstable_bucket.size(); ++i){
        obstable_bucket[i].draw_obstacle();
    }

    SDL_RenderCopy(renderer, Player::b_pPlayerTexture, NULL, &player->g_playerRect);
    
    SDL_RenderPresent(renderer);
};

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
};

void Game::drawMapVisual()
{
    for(int i=0; i < Game::SCREEN_HEIGHT + Game::GRID_WIDTH; i += Game::GRID_WIDTH){
        for(int j=0; j < Game::SCREEN_WIDTH + Game::GRID_WIDTH; j += Game::GRID_WIDTH){
            SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
            SDL_RenderDrawLine(Game::renderer, j, 0, j, Game::SCREEN_WIDTH);
        }
        SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
        SDL_RenderDrawLine(Game::renderer, 0, i, Game::SCREEN_WIDTH, i);
    }
}


