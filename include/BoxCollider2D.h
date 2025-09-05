#ifndef BOXCOLLIDER2D_H
#define BOXCOLLIDER2D_H

#include "Collider2D.h"

class BoxCollider2D : public Collider2D {
public:
    BoxCollider2D(int width, int height, const Vector2D& offset = Vector2D(0, 0));
    bool checkCollision(Collider2D& other) override;
    std::string getColliderType() override;
    AABB getBoundingBox() override;

    int width;
    int height;
};

#endif //BOXCOLLIDER2D_H
