//
//  Transform.hpp
//  CPP
//
//  Created by nltbao on 19/09/2021.
//

#ifndef Transform_h
#define Transform_h

#include <stdio.h>
#include <iostream>
#include "GlobalHeader.h"
#include <vector>

class Transform {
public:
    
//    template<typename T>
    Transform()
    {
        std::cout << "HELLO " << std::endl;
    }
    
    virtual ~Transform()
    {
        
    }
    
    struct COLLISION {
        bool boolean = false;
        SDL_Rect colisionRect;
    };
    
    
    float velocityX = 0;
    float velocityY = 0;
    
    float jumpStep;
    int jump_status = 0;
    
    const int G_JUMP_HEIGHT = -20;
    const float G_JUMP_SPEED = 1;
    const float G_FALL_SPEED = 1.5;
    const int G_MOVE_SPEED = 5;
    const int G_SPEED_GRAVITY = G_MOVE_SPEED * G_MOVE_SPEED * 0.6;
    bool b_useJump = true;
    
    virtual void on_start_jump()
    {
        std::cout << "ok" << std::endl;
        if(jump_status == 0 && b_useJump){
            jump_status = 1;
            velocityY = 0;
            jumpStep = G_JUMP_HEIGHT;
        }
    }
    
    virtual void on_jump(SDL_Rect* rect)
    {
        if(jump_status == 1){
            // * Jumping
            velocityY += -abs(jumpStep);
            rect->y += velocityY;
            jumpStep += G_JUMP_SPEED;
            if(jumpStep > 0) {
                jump_status = 2;
            }
        }
    }
    
    virtual void on_fall(SDL_Rect* rect, const int objWidth, const int objHeight, const bool hold_up, const bool hold_down, const bool hold_left, const bool hold_right)
    {
        int adjustX = rect->x;
        int adjustY = rect->y;
        
        if(hold_right) {
            adjustX -= G_MOVE_SPEED;
        } else if(hold_left){
            adjustX += G_MOVE_SPEED;
        }
        
        if(hold_up) {
            adjustY += G_MOVE_SPEED;
        } else if(hold_down){
            adjustY -= G_MOVE_SPEED;
        }
        
        if(jump_status == 2){
            // * Falling
//            auto statusCollision = this->bCollision<Obstacle>(adjustX, adjustY + abs(jumpStep));
//            if(statusCollision.boolean){
//                rect->y += statusCollision.colisionRect.y - objHeight - (rect->y + velocityY);
//                jump_status = 0;
//            } else{
//                velocityY += abs(jumpStep);
//                rect->y += velocityY;
//                jumpStep += G_FALL_SPEED;
//            }
        } else if(jump_status == 0){
            // * Gravity
//            if(!this->bCollision<Obstacle>(adjustX, adjustY + G_SPEED_GRAVITY).boolean){
//                rect->y += G_SPEED_GRAVITY;
//            }
        }
    }
    
    template<typename T>
    struct COLLISION bCollision(const std::vector<T> vt, const int objectX, const int objectY, const int objectWidth, const int objectHeight)
    {
        COLLISION ret;
    //    for(size_t i = 0; i < vt.size(); ++i){
    //
    //        if(objectX >= vt[i].rect.x - objectWidth + 1 &&
    //            objectX <= vt[i].rect.x + vt[i].rect.w - 1 &&
    //            objectY >= vt[i].rect.y - objectHeight + 1 &&
    //            objectY <= vt[i].rect.y + vt[i].rect.h - 1
    //           ){
    //            ret.boolean = true;
    //            ret.colisionRect = vt[i].rect;
    //        }
    //    }
        return ret;
    }
private:
};

#endif /* Transform_h */
