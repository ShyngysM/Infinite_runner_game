#include "image.h"

#include <SDL.h>
#include <stdexcept>

Image::Image(SDL_Renderer* renderer, std::string filename) {
    std::unique_ptr<SDL_Surface, SdlDeleter> bmp_surface(SDL_LoadBMP(filename.c_str()));

    if (!bmp_surface) {
        throw std::runtime_error(filename + " not found");
    }

    bmp_texture.reset(SDL_CreateTextureFromSurface(renderer, bmp_surface.get()));

    SDL_QueryTexture(bmp_texture.get(), nullptr, nullptr, &width, &height);
   
}

void Image::draw(SDL_Renderer* renderer) {
    SDL_Rect dst = {position.x, position.y, width, height};
    SDL_RenderCopy(renderer, bmp_texture.get(), nullptr, &dst);
}

int Image::getHeight() const {
    return height;
}

int Image::getWidth() const {
    return width;
}
