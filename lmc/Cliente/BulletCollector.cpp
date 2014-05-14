#include "BulletCollector.h"

int BulletCollector::push(Point<float> pos, const float speed, const float angle) {
    if (index < MAX_COLLECTOR_SIZE) {
        Bullet tmp(pos, speed, angle);
        container[index] = tmp;
        index++;
        return index;
    }
    return -1;
}

int BulletCollector::push(const float x, const float y, const float speed, const float angle) {
    Point<float> tmp(x, y);
    return push(tmp, speed, angle);
}

void BulletCollector::next() {
    for (int i = 0; i < index; i++) {
        container[i].next();
        if (container[i].getLife() == 0) {
            erase(i);
        }
    }
}

void BulletCollector::erase(const int idx) {
    if (idx < index && idx >= 0) {
        for (int i = idx + 1; i < index; i++) {
            container[i-1] = container[i];
        }
        index--;
    }
}
