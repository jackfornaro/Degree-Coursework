#ifndef TREE_H_
#define TREE_H_

#include "entity.h"
#include "vector3.h"

// Represents a Tree in a physical system
class Tree : public Entity {
public:
    // Trees are on the ground, so do not have a z component
    Tree(const std::string& name, double x, double y) : name(name) {
        pos.x = x;
        pos.y = y;
        dim = 2;
        isMovable = false;
    }
    // Gets the tree name
    const std::string& GetName() { return name; }
    // Gets the tree position
    Vector3 GetPosition() { return pos; }

private:
    Vector3 pos;
    std::string name;
};



#endif
