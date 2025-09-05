#ifndef CIRCLE_COLLIDER_2D_H
#define CIRCLE_COLLIDER_2D_H

#include "Collider2D.h"
#include "AABB.h"
#include "Vector2D.h"
#include <string>

class CircleCollider2D : public Collider2D {
public:
    float radius;
    Vector2D offset;

    CircleCollider2D(float radius, const Vector2D& offset);
    bool checkCollision(Collider2D& other) override;
    std::string getColliderType() override;
    AABB getBoundingBox() override;
};

#endif // CIRCLECOLLIDER2D_H
