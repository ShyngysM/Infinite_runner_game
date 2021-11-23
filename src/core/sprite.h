#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>
#include "point.h"

/**
 * Diese Klasse beschŕeibt alles was "drawable" ist.
    Die Funktionsnamen sowohl als auch Variablen sind selbsterklärend.
 */

class Sprite {
public:
    virtual void draw(SDL_Renderer*) = 0 ;
    virtual void update();
    void setColor(int red, int green, int blue);

    Point position;
    Point velocity;
    Point end_position;
    
protected:
    int red = 0;
    int green = 0;
    int blue = 0;
};

#endif
