#ifndef ENTITY_H_
#define ENTITY_H_

#include <string>
#include "vector3.h"

// Entity is the base class for any simulation object
class Entity {
public:
    int dim;
    bool isMovable;
public:
    // Destructor
    virtual ~Entity() {}
    // Returns the name of the entity
    virtual const std::string& GetName();
    // Returns the position of the entity in space
    virtual Vector3 GetPosition() = 0;
};

// An entity that can move and be updated
class MovableEntity : public Entity {
public:
    // Updates the movable entity
    virtual void Update(double dt) {}
};

#endif
