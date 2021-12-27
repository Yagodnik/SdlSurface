#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"

int main() {
    SDL_Rect **modes;
    int i;


    modes=SDL_ListModes(NULL, SDL_FULLSCREEN|SDL_HWSURFACE);

    if(modes == (SDL_Rect **)0){
        printf("No modes available!\n");
        exit(-1);
    }

    if(modes == (SDL_Rect **)-1){
        printf("All resolutions available.\n");
    } else {
        printf("Available Modes\n");
        for(i=0;modes[i];++i)
            printf("  %d x %d\n", modes[i]->w, modes[i]->h);
    }
}
