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

Vector2D Vector2D::perpendicular() const {
    return Vector2D(-y, x);
}
