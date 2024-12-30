#include "Vector2D.h"
#include <cmath>

Vector2D::Vector2D(float x, float y) : x(x), y(y) {}

float Vector2D::magnitude() const {
    return sqrt((x * x) + (y * y));
}

Vector2D Vector2D::normalize() const {
    const float mag = magnitude();
    if(mag > 0) {
        return *this / mag;
    }
    return Vector2D(0, 0);
}

float Vector2D::dotProduct(const Vector2D& other) const {
    return (x * other.x) + (y * other.y);
}
float Vector2D::crossProduct(const Vector2D& other) const {
    return (x * other.y) - (y * other.x);
}

Vector2D Vector2D::perpendicular() const {
    return Vector2D(-y, x);
}
