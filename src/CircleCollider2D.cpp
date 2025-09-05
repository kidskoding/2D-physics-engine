#include "CircleCollider2D.h"
#include "BoxCollider2D.h"
#include <string>

CircleCollider2D::CircleCollider2D(float radius, const Vector2D& offset)
    : radius(radius) {
    this->offset = offset;
}

AABB CircleCollider2D::getBoundingBox() {
    return AABB(
        offset.x - radius,
        offset.y - radius,
        offset.x + radius,
        offset.y + radius
    );
}

bool CircleCollider2D::checkCollision(Collider2D& other) {
    if(!this->getBoundingBox().intersects(other.getBoundingBox())) {
        return false;
    }

    std::string otherType = other.getColliderType();
    if(otherType == "Circle") {
        CircleCollider2D* otherCircle = dynamic_cast<CircleCollider2D*>(&other);
        if (!otherCircle) return false;

        Vector2D diff = this->offset - otherCircle->offset;
        float distance = diff.magnitude();
        float combinedRadius = this->radius + otherCircle->radius;
        return distance <= combinedRadius;
    }
    if(otherType == "Box") {
        BoxCollider2D* otherBox = dynamic_cast<BoxCollider2D*>(&other);
        if (!otherBox) return false;

        float closestX = std::clamp(this->offset.x,
            otherBox->offset.x,
            otherBox->offset.x + otherBox->width);
        float closestY = std::clamp(this->offset.y,
            otherBox->offset.y,
            otherBox->offset.y + otherBox->height);

        float distanceX = this->offset.x - closestX;
        float distanceY = this->offset.y - closestY;
        float distanceSquared = (distanceX * distanceX) + (distanceY * distanceY);

        return distanceSquared <= (this->radius * this->radius);
    }

    return false;
}

std::string CircleCollider2D::getColliderType() {
    return "Circle";
}
