//
//  Entity.hpp
//  CPP
//
//  Created by nltbao on 18/09/2021.
//

#pragma once
#ifndef Entity_h
#define Entity_h

#include "ECS.hpp"
#include <vector>
#include "Component.hpp"

class Entity {
public:
    Entity() {}
    virtual ~Entity() {}
    
    template<typename T, typename... TArgs>
    inline T& addComponent(TArgs&&... args)
    {
        T* comp(new T(std::forward<TArgs>(args)...));
        
        comp->entity = this;

        std::unique_ptr<Component> uptr { comp };
        components.emplace_back(std::move(uptr));

        if(comp->init()){
            compList[getComponentTypeID<T>()] = comp;
            compBitset[getComponentTypeID<T>()] = true;
            comp->entity = this;
            return *comp;
        }
        
        return *static_cast<T*>(nullptr);
    }
    
    template<typename T>
    inline T& getComponent() const
    {
        auto ptr(compList[getComponentTypeID<T>()]);
        return *static_cast<T*>(ptr);
    }
    
//    template<typename T>
    
private:
    ComponentList compList;
    ComponentBitset compBitset;
    std::vector<std::unique_ptr<Component>> components;
};

#endif /* Entity_h */
