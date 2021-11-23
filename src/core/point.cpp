#include "point.h"

Point::Point() {
    // no-op
}

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

void Point::moveBy(int dx, int dy) {
    x += dx;
    y += dy;
}

void Point::moveTo(int xn, int yn) {
    x = xn;
    y = yn;
}
