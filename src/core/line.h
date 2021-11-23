#ifndef Line_H
#define Line_H

#include "sprite.h"
#include "point.h"

/**
 * Kinderklasse Line, erbt von Sprite.
 * Eine Linie im Zweidimesionalen.
 * Beschrieben durch Punkt begin und Punkt end.
 * Die Funktionsnamen sowohl als auch Variablen sind selbsterklärend.
 */

class Line: public Sprite {
public:
    Line();
    Line(Point begin, Point end);

    void draw(SDL_Renderer*);
    void drawlines(SDL_Renderer* renderer);
    
};

#endif
