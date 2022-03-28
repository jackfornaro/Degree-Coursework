#ifndef ENTITY_H_
#define ENTITY_H_

#include <string>

// Entity is the base class for any simulation object
class Entity {
public:
    // Destructor
    ~Entity() {}
    // Returns the name of the entity
    const std::string& GetName();
    // Returns the position of the entity in space
    virtual double* GetPosition() = 0;
};

// An entity that can move and be updated
class MovableEntity : public Entity {
public:
    // Updates the movable entity
    void Update(double dt) {}
};

#endif