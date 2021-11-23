#include "rectangle.h"

Rectangle::Rectangle() {
    // no-op
}

Rectangle::Rectangle(Point topleft, int h, int w) {
    this->position = topleft;
    this->width = w;
    this->height = h;
}


int Rectangle::calcArea() const {
    return width * height;
}

int Rectangle::calcCircumference() const {
    return 2 * width + 2 * height;
}

void Rectangle::draw(SDL_Renderer* renderer) {
    SDL_Rect rect = {position.x, position.y, width, height};

    // Zeichenfarbe setzen
    SDL_SetRenderDrawColor(renderer, red, green, blue, 0x0);

    // Rechteck zeichnen
    SDL_RenderFillRect(renderer, &rect);
}

void Rectangle::draw_area(SDL_Renderer* renderer){
    SDL_Rect rect0 = {position.x, position.y, width, height};
    SDL_SetRenderDrawColor(renderer, red, green, blue, 0x0);
    SDL_RenderDrawRect(renderer, &rect0);
}

void Rectangle::grow(){
    width = width+2;
    height = height +2;
}

void Rectangle::grow(int a, int b){
    width = width+a;
    height = height +b;
}


