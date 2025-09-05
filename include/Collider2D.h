#ifndef COLLIDER2D_H
#define COLLIDER2D_H

#include "AABB.h"
#include "Vector2D.h"
#include <string>

class Collider2D {
public:
    Vector2D offset;

    Collider2D() = default;
    virtual ~Collider2D() = default;

    virtual bool checkCollision(Collider2D& other) = 0;
    virtual std::string getColliderType() = 0;
    virtual AABB getBoundingBox() = 0;
};

#endif //COLLIDER2D_H
