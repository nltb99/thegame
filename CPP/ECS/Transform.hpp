//
//  Transform.hpp
//  CPP
//
//  Created by nltbao on 19/09/2021.
//

#ifndef Transform_h
#define Transform_h

#include "Component.hpp"
#include "Vector2D.hpp"

class Transform : public Component
{
public:
    Transform() {
        position.initValue(0, 0);
        scale.initValue(1, 1);
        Rotation = 0.0f;
    }
    
    Transform(float x, float y) {
        position.initValue(x, y );
        scale.initValue(1, 1);
        Rotation = 0.0f;
    }
    
    Transform(float x, float y, float scaleX, float scaleY, float rotation) {
        position.initValue(x, y );
        scale.initValue(scaleX, scaleY);
        Rotation = rotation;
    }
    
    virtual ~Transform() {}
    
    bool init() override final
    {
       
        
        return true;
    }
    
    Vector2F position;
    Vector2F scale;
    float Rotation;
    
};

#endif /* Transform_h */
