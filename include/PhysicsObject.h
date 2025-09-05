#ifndef PHYSICSOBJECT_H
#define PHYSICSOBJECT_H

#include <SFML/Graphics.hpp>
#include "Rigidbody2D.h"

class PhysicsObject {
public:
    Rigidbody2D rigidbody;
    Collider2D* collider;
    sf::Shape* shape;

    PhysicsObject(Rigidbody2D rigidbody,
                  Collider2D* collider,
                  sf::Shape* shape);

    void update(float deltatime);

    ~PhysicsObject() {
        delete collider;
        delete shape;
    }
};

#endif //PHYSICSOBJECT_H
