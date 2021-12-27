#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"

void draw_rectangle(SDL_Surface* surface, int x, int y, int width, int height)
{
    SDL_LockSurface(surface);
    uint8_t *pixels = (uint8_t*) malloc(surface->pitch * surface->h);

    int dy, dx;
    int maxwidth = width * 3;
    for (dy = y; dy < height; dy++) {
        for (dx = x; dx < maxwidth; dx += 3) {
            pixels[dx + (dy * surface->pitch)] = 0;
            pixels[dx + (dy * surface->pitch) + 1] = 255;
            pixels[dx + (dy * surface->pitch) + 2] = 0;
        }
    }
    memcpy(surface->pixels, pixels, surface->pitch * surface->h);

    SDL_UnlockSurface(surface);
}

int main(int argc, const char *argv) {
    SDL_Surface *surface = SDL_SetVideoMode(200, 200, 24, SDL_HWSURFACE);

    draw_rectangle(surface, 0, 0, 50, 50);
    SDL_Flip(surface);

    SDL_Delay(6000);

    SDL_Quit();
    return 0;
}
