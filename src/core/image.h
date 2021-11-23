#ifndef IMAGE_H
#define IMAGE_H

#include <memory>
#include <string>
#include "sdl_helper.h"
#include "sprite.h"

/**
 * Kinderklasse Image, erbt von der Klasse Image.
 * Die Funktionsnamen sowohl als auch Variablen sind selbsterklärend.
 */

class Image: public Sprite {
public:
    Image(SDL_Renderer* renderer, std::string filename);
    
    void draw(SDL_Renderer* renderer) override;

    int getHeight() const;
    int getWidth() const;

private:
    std::unique_ptr<SDL_Texture, SdlDeleter> bmp_texture;

    int height = 0;
    int width = 0;
};

#endif