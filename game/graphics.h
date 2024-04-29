#ifndef _GRAPHICS__H
#define _GRAPHICS__H

#include <SDL.h>
#include <SDL_image.h>
#include "defs.h"
#include "lib.h"


class Graphics
{
public:
	void logErrorAndExit(const char* msg, const char* error);
	void init();
    void prepareScene();
	void prepareScene(SDL_Texture * background);
    void presentScene();
    SDL_Texture *loadTexture(const char *filename);
    void renderTexture(SDL_Texture *texture, int x, int y);
    void blitRect(SDL_Texture *texture, SDL_Rect *src, int x, int y);
    void quit();
private:

	SDL_Renderer *renderer;
	SDL_Window *window;
};

#endif // _GRAPHICS__H
