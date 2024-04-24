#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "graphics.h"
#include "defs.h"

using namespace std;

void waitUntilMousePressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_PollEvent(&e) != 0 &&
             (e.type == SDL_MOUSEBUTTONDOWN|| e.type == SDL_QUIT) )
            return;
        SDL_Delay(10);
    }
}
int main(int argc, char *argv[])
{
    Graphics graphics;
    graphics.init();

    waitUntilMousePressed();
    graphics.quit();
    return 0;
}
