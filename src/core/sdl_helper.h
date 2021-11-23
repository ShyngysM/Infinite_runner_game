#ifndef SDL_HELPER_H
#define SDL_HELPER_H

#include <SDL.h>

// Kommentar entfernen wenn SDL_ttf verwendet wird
#include <SDL_ttf.h>


// SDL ist eine C-Bibliothek und unterstuetzt daher std::unique_ptr nicht
// Loesung: Ein eigener deleter, der weiss, wie SDL den Speicher freigibt
struct SdlDeleter {
    void operator()(SDL_Window* obj) {
        SDL_DestroyWindow(obj);
    }

    void operator()(SDL_Renderer* obj) {
        SDL_DestroyRenderer(obj);
    }

    void operator()(SDL_Texture* obj) {
        SDL_DestroyTexture(obj);
    }

    void operator()(SDL_Surface* obj) {
        SDL_FreeSurface(obj);
    }

    //Kommentar entfernen wenn SDL_ttf verwendet wird
    void operator()(TTF_Font* obj) {
        TTF_CloseFont(obj);
    }
    
};

#endif
