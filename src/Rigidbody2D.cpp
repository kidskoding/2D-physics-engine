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
    acceleration = force / mass;
}

void Rigidbody2D::update(float deltatime)
{
    const Vector2D gravity(0.0, 9.8);
    acceleration = acceleration + gravity;

    const float frictionCoefficient = 0.01f;
    if (velocity.magnitude() > 0.0f) {
        Vector2D friction = velocity.normalize() * -frictionCoefficient;
        acceleration = acceleration + friction;
    }

    velocity = velocity + acceleration * deltatime;
    position = position + velocity * deltatime;

    acceleration = Vector2D(0, 0);
}
