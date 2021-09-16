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
    virtual ~Component() = default;
    virtual void init() {}
    virtual void update() {}
    virtual void draw() {}

};
#endif /* Component_h */
