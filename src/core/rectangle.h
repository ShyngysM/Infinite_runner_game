#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "sprite.h"
#include "point.h"
/**
 * Kinderklasse Recktangle, erbt von Sprite. 
 * Ein Rechteck im zweidimensionalen.
 * Beschrieben durch einen Punkt mit x und y Koordinaten, und mit Höhe und Breite.
 * Es gibt ein Paar neuen Funktionen und zwar grow() und draw_area().
 * Die Funktionsnamen sowohl als auch Variablen sind selbsterklärend.
 */
class Rectangle: public Sprite {
public:
    Rectangle();
    Rectangle(Point topleft, int h, int w);

    int height = 0;
    int width = 0;

    int calcArea() const;
    int calcCircumference() const;
    void draw(SDL_Renderer* renderer) override;
    void draw_area(SDL_Renderer* renderer);
    void grow();
    void grow(int a, int b);

};

#endif
