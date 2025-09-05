#include "BoxCollider2D.h"
#include "CircleCollider2D.h"
#include <string>

BoxCollider2D::BoxCollider2D(int width, int height, const Vector2D& offset)
    : width(width), height(height) {
    this->offset = offset;
}

AABB BoxCollider2D::getBoundingBox() {
    return AABB(
        offset.x,
        offset.y,
        offset.x + width,
        offset.y + height
    );
}

bool BoxCollider2D::checkCollision(Collider2D& other) {
    if (!this->getBoundingBox().intersects(other.getBoundingBox())) {
        return false;
    }

    std::string otherType = other.getColliderType();
    if (otherType == "Circle") {
        CircleCollider2D* otherCircle = dynamic_cast<CircleCollider2D*>(&other);
        if (!otherCircle) return false;

        return otherCircle->checkCollision(*this);
    }
    if (otherType == "Box") {
        return true;
    }

    return false;
}

std::string BoxCollider2D::getColliderType() {
    return "Box";
}
