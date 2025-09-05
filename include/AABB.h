#ifndef AABB_H
#define AABB_H

class AABB {
public:
    float left, bottom, right, top;

    AABB(float left, float bottom, float right, float top)
        : left(left), bottom(bottom), right(right), top(top) {}

    bool intersects(const AABB& other) const {
        return right >= other.left && left <= other.right && top >= other.bottom && bottom <= other.top;
    }
};

#endif //AABB_H
