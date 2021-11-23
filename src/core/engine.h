#ifndef ENGINE_H
#define ENGINE_H

#include <memory>
#include <vector>
#include <SDL.h>

#include "point.h"
#include "rectangle.h"
#include "line.h"
#include "image.h"
#include "sdl_helper.h"

/**
 * Eine Elternklasse, die sich um korrekten Einstellungen der Fensterserzeugung kümmert.
 *     Die Funktionsnamen sowohl als auch Variablen sind selbsterklärend.
 */

class Engine {
public:
    Engine(int width, int height, std::string title);

    virtual ~Engine();

    bool processEvents();

    virtual bool processEvent(SDL_Event& evt) = 0;

    virtual void update() = 0;

    virtual void render() = 0;

    Point getWindowSize();

protected:
    std::unique_ptr<SDL_Window, SdlDeleter> window;
    std::unique_ptr<SDL_Renderer, SdlDeleter> renderer;

private:
    int width = 0;
    int height = 0;
};

#endif
