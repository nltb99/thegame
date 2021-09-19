//
//  ECS.hpp
//  CPP
//
//  Created by nltbao on 18/09/2021.
//

#ifndef ECS_h
#define ECS_h

#include <bitset>
#include <array>
#include <iostream>

class Entity;
class Component;

using ComponentTypeID = std::size_t;

inline ComponentTypeID getUniqueComponentID()
{
    static ComponentTypeID lastID = 0;
    return lastID++;
}

template<typename T>
inline ComponentTypeID getComponentTypeID() noexcept
{
    static_assert(std::is_base_of<Component, T>::value, "HELLO");
    static const ComponentTypeID typeID = getUniqueComponentID();
    return typeID;
}

constexpr std::size_t MAX_ENTITIES = 5000;
constexpr std::size_t MAX_COMPONENTS = 32;

using ComponentBitset = std::bitset<MAX_COMPONENTS>;
using ComponentList = std::array<Component*, MAX_ENTITIES>;

#endif /* ECS_h */
