#ifndef RIGIDBODY2D_H
#define RIGIDBODY2D_H

#include "Vector2D.h"

class Rigidbody2D {
    Vector2D position;
    Vector2D velocity;
    float mass;
    Vector2D acceleration;
public:
    Rigidbody2D(float x, float y, float mass);

    Vector2D getPosition() const;
    Vector2D getVelocity() const;
    float getMass() const;

    void addForce(const Vector2D& force);
    void update(float deltatime);
};

#endif //RIGIDBODY2D_H
