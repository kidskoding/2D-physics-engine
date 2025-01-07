#include "Rigidbody2D.h"

Rigidbody2D::Rigidbody2D(float x, float y, float mass)
   : position(x, y), velocity(0, 0), mass(mass), acceleration(0, 0) {}

Vector2D Rigidbody2D::getPosition() const {
    return position;
}
Vector2D Rigidbody2D::getVelocity() const {
    return velocity;
}
float Rigidbody2D::getMass() const
{
    return mass;
}

void Rigidbody2D::addForce(const Vector2D& force)
{
    acceleration = acceleration + force / mass;
}

void Rigidbody2D::update(float deltatime)
{
    const Vector2D gravity(0.0, 9.8 * 100);
    addForce(gravity * mass);

    if(velocity.magnitude() > 0.0f) {
        const float frictionCoefficient = 0.01f;
        const Vector2D friction = velocity.normalize() * -frictionCoefficient;
        addForce(friction);
    }

    velocity = velocity + acceleration * deltatime;
    position = position + velocity * deltatime;

    acceleration = Vector2D(0, 0);
}
