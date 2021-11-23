#ifndef inf_run_H
#define inf_run_H

#include <string>
#include "engine.h"

/**
 * Initialisation, Spiellogik mit Events und Erzeugung von Objekten (Drawing).
    Kinderklasse von der Klasse Engine, also erbt alle Methoden von der Klasse Engine.
    int barrier_left und barrier right nur dafür da,  die Anzahl von "magic numbers" zu minimieren.

 */

class inf_run: public Engine {
public:
    inf_run();

    bool processEvent(SDL_Event& evt) override;
    void update() override;
    void render() override;

    int dice_roll;
    int dice_roll1;
    bool detected;
    bool goodness;
    int area;
    int iclock = 0;
    int barrier_left = 178;
    int barrier_right = 1024-128-100;

private:
    std::unique_ptr<Rectangle> rect;    
    std::unique_ptr<Rectangle> rect0;    
    std::unique_ptr<Rectangle> rect1;    
    std::unique_ptr<Rectangle> rect2;    
    std::unique_ptr<Rectangle> rect3;      
    std::unique_ptr<Line> line1;   
    std::unique_ptr<Line> line2;   
    std::unique_ptr<Line> line3;   
    std::unique_ptr<Line> line4;   
    std::unique_ptr<Image> gameover_img;
    std::unique_ptr<Image> good;
    std::unique_ptr<Image> nice;
    std::unique_ptr<Image> great;
    std::unique_ptr<Image> perfect;
    std::unique_ptr<Image> awensome;
    std::unique_ptr<Image> ggwp;

};

#endif