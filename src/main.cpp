#include "BoxCollider2D.h"
#include "CircleCollider2D.h"
#include "PhysicsObject.h"
#include "Rigidbody2D.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "2D Physics Engine Demo");
    window.setFramerateLimit(60);

    auto* ballShape = new sf::CircleShape(25.0f);
    ballShape->setFillColor(sf::Color::Green);
    ballShape->setOrigin(25.0f, 25.0f);

    Rigidbody2D ballRb(100.0f, 100.0f, 1.0f);
    auto* ballCollider = new CircleCollider2D(25.0f, Vector2D(100.0f, 100.0f));
    PhysicsObject ball(ballRb, ballCollider, ballShape);
    ball.rigidbody.addForce(Vector2D(100.0f, 50.0f));

    auto* boxShape = new sf::RectangleShape(sf::Vector2f(100.0f, 100.0f));
    boxShape->setFillColor(sf::Color::Blue);
    boxShape->setOrigin(50.0f, 50.0f);

    Rigidbody2D boxRb(400.0f, 300.0f, 0.0f);
    auto* boxCollider = new BoxCollider2D(100.0f, 100.0f, Vector2D(400.0f, 300.0f));
    PhysicsObject box(boxRb, boxCollider, boxShape);

    sf::Clock clock;

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = std::min(clock.restart().asSeconds(), 0.1f);

        ball.update(deltaTime);
        box.update(deltaTime);

        if(ball.collider->checkCollision(*box.collider)) {
            ballShape->setFillColor(sf::Color::Red);
            boxShape->setFillColor(sf::Color::Red);

            Vector2D normal = (ball.rigidbody.getPosition() - box.rigidbody.getPosition()).normalize();
            ball.rigidbody.setPosition(ball.rigidbody.getPosition() + normal * 2.0f);
            ball.rigidbody.setVelocity(normal * -0.8f * ball.rigidbody.getVelocity().magnitude());
        } else {
            ballShape->setFillColor(sf::Color::Green);
            boxShape->setFillColor(sf::Color::Blue);
        }

        ball.rigidbody.addForce(Vector2D(0, 98.1f));

        Vector2D ballPos = ball.rigidbody.getPosition();
        if(ballPos.x < 0 || ballPos.x > 800) {
            Vector2D vel = ball.rigidbody.getVelocity();
            ball.rigidbody.setVelocity(Vector2D(-vel.x * 0.8f, vel.y));
            ball.rigidbody.setPosition(Vector2D(ballPos.x < 0 ? 5 : 795, ballPos.y));
        }
        if(ballPos.y < 0 || ballPos.y > 600) {
            Vector2D vel = ball.rigidbody.getVelocity();
            ball.rigidbody.setVelocity(Vector2D(vel.x, -vel.y * 0.8f));
            ball.rigidbody.setPosition(Vector2D(ballPos.x, ballPos.y < 0 ? 5 : 595));
        }

        window.clear(sf::Color::Black);
        window.draw(*ball.shape);
        window.draw(*box.shape);
        window.display();
    }

    delete ballShape;
    delete ballCollider;
    delete boxShape;
    delete boxCollider;

    return 0;
}
