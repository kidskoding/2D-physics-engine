#include "PhysicsObject.h"
#include "CircleCollider2D.h"
#include "BoxCollider2D.h"
#include "SFML/System/Vector2.hpp"

PhysicsObject::PhysicsObject(Rigidbody2D rigidbody, Collider2D* collider, sf::Shape* shape)
    : rigidbody(rigidbody), collider(collider), shape(shape) {}

void PhysicsObject::update(float deltaTime) {
    rigidbody.update(deltaTime);
    Vector2D pos = rigidbody.getPosition();
    shape->setPosition(sf::Vector2f(pos.x, pos.y));

    if(auto* circleCol = dynamic_cast<CircleCollider2D*>(collider)) {
        circleCol->offset = pos;
    }
    else if(auto* boxCol = dynamic_cast<BoxCollider2D*>(collider)) {
        boxCol->offset = pos;
    }
}
