#ifndef RIGIDBODY2D_H
#define RIGIDBODY2D_H

#include "Vector2D.h"
#include "Collider2D.h"

class Rigidbody2D {
    float mass;
    Vector2D position;
    Vector2D velocity;
    Vector2D acceleration;
    Collider2D* collider;
public:
    Rigidbody2D(float x, float y, float mass);

    Vector2D getPosition() const;
    Vector2D getVelocity() const;

    void setVelocity(Vector2D velocity);
    void setPosition(const Vector2D& position);

    float getMass() const;

    void addForce(const Vector2D& force);
    void update(float deltatime);

    void addCollider(Collider2D* collider);
};

#endif //RIGIDBODY2D_H
