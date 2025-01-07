#include "Rigidbody2D.h"
#include "Vector2D.h"
#include <SFML/Graphics.hpp>

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({500u, 500u}), "CMake SFML Project");
    window.setFramerateLimit(60);

    sf::CircleShape shape(50.0f);
    shape.setFillColor(sf::Color::Green);

    Rigidbody2D ball(100.0f, 100.0f, 1.0f);
    ball.addForce(Vector2D(0, 10.0f));

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        ball.update(1.0f / 144.0f);

        Vector2D position = ball.getPosition();
        shape.setPosition(sf::Vector2f(position.x, position.y));

        window.clear();
        window.draw(shape);
        window.display();
    }
}
