#include "sprite.h"

void Sprite::setColor(int red, int green, int blue) {
    this->red = red;
    this->green = green;
    this->blue = blue;
}

void Sprite::update() {
    position.moveBy(velocity.x, velocity.y);
}
