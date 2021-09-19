//
//  Component.hpp
//  CPP
//
//  Created by nltbao on 15/09/2021.
//

#ifndef Component_h
#define Component_h

class Entity;
class Component {
public:
    Component() = default;
    virtual ~Component() = default;
    
    Entity* entity;
    
    virtual bool init() { return true;}
    virtual void draw() {}
    virtual void update() {}
    

};
#endif /* Component_h */
