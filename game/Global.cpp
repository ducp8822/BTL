#include "Global.h"

using namespace std;

//The renderer we'll be using
SDL_Renderer* gRenderer = NULL;

// The window we'll be rendering to
SDL_Window* gWindow = NULL;

LTexture background1;
LTexture background2;
LTexture gameover;


Uint32 tmp_time = 0;
LTexture cat;
Enermy dog1;
Enermy dog2;
bool GAME_OVER = false;
int x_mouse = 0;
int y_mouse = 0;

