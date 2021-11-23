#include "line.h"
#include "point.h"

Line::Line() {
    // no-op
}

Line::Line(Point begin, Point end) {
    this->position = begin;
    this->end_position = end;
}

void Line::draw(SDL_Renderer* renderer) {
    // Zeichenfarbe setzen
    SDL_SetRenderDrawColor(renderer, red, green, blue, 0x0);
    // line zeichnen
    SDL_RenderDrawLine(renderer, position.x,position.y , end_position.x, end_position.y);
}















    // das bleibt hier einfach so
    // SDL_RenderDrawLine(renderer, 128, 0, 1024/2-25, 768/2-25);
    // SDL_RenderDrawLine(renderer, 1024-128, 0, 1024/2-25+50, 768/2-25);
    // SDL_RenderDrawLine(renderer, 128, 768, 1024/2-25, 768/2-25+50);
    // SDL_RenderDrawLine(renderer, 1024-128, 768, 1024/2-25+50, 768/2-25+50);
