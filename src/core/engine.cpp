#include "engine.h"
#include "rectangle.h"
#include "sdl_helper.h"

#include <SDL_ttf.h>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>

Engine::Engine(int width, int height, std::string title) {
    auto throw_error = [](std::string which) {
        throw std::runtime_error(which + " " + SDL_GetError());
    };

    SDL_SetHint(SDL_HINT_VIDEO_X11_NET_WM_BYPASS_COMPOSITOR, "0");

    // Alle Komponenten von SDL initialisieren
    // siehe https://wiki.libsdl.org/SDL_Init
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        throw_error("SDL_Init fehlgeschlagen");
    }

    this->height = height;
    this->width = width;

    // Fenster erstellen, siehe https://wiki.libsdl.org/SDL_CreateWindow
    window.reset(SDL_CreateWindow(
        title.c_str(),
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        width, height,
        SDL_WINDOW_RESIZABLE));

    if (!window) {
        throw_error("SDL_CreateWindow fehlgeschlagen");
    }

    // Renderer erstellen, siehe https://wiki.libsdl.org/SDL_CreateRenderer
    renderer.reset(SDL_CreateRenderer(window.get(), -1, 0));

    if (!renderer) {
        throw_error("SDL_CreateRenderer fehlgeschlagen");
    }

    // Automatisch skalieren wenn sich Fenstergroesse aendert
	SDL_RenderSetLogicalSize(renderer.get(), width, height);

    // Fenster schwarz ausmalen
	SDL_RenderClear(renderer.get());

    // Aenderung sichtbar machen
	SDL_RenderPresent(renderer.get());
}

Engine::~Engine() {
    // Beim beenden SDL_Quit aufrufen (Resourcen freigeben)
    SDL_Quit();
    TTF_Quit();
}

Point Engine::getWindowSize() {
    return Point(width, height);
}

bool Engine::processEvents() {
    // Nutzereingaben verarbeiten
    SDL_Event evt;

    // Events einlesen
    while (SDL_PollEvent(&evt)) {
        if (evt.type == SDL_QUIT) {
            // Benutzer hat Programmende angefordert (Fenster geschlossen)
            return 0;
        }

        if (!processEvent(evt)) {
            // Programmende durch abgeleitete Engine angefordert
            return 0;
        }
    }

    return true;
}
