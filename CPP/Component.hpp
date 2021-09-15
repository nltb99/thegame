//
//  Component.hpp
//  CPP
//
//  Created by nltbao on 15/09/2021.
//

#ifndef Component_h
#define Component_h


class Component {
public:
    
    virtual void init();
    virtual void update();
    virtual void draw();
    virtual ~Component();
    
};
#endif /* Component_h */
