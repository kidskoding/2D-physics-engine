#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D {
public:
    float x, y = 0;

    Vector2D(float x = 0, float y = 0);

    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(this->x + other.x, this->y + other.y);
    }
    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(this->x - other.x, this->y - other.y);
    }
    Vector2D operator*(float scalar) const {
        return Vector2D(this->x * scalar, this->y * scalar);
    }
    Vector2D operator/(float scalar) const {
        return Vector2D(this->x / scalar, this->y / scalar);
    }

    float magnitude() const;

    Vector2D normalize() const;

    float dotProduct(const Vector2D& other) const;
    float crossProduct(const Vector2D& other) const;

    Vector2D perpendicular() const;
};

#endif //VECTOR2D_H
