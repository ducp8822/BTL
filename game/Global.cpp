#include "Global.h"

using namespace std;

//The renderer we'll be using
SDL_Renderer* gRenderer = NULL;

// The window we'll be rendering to
SDL_Window* gWindow = NULL;

LTexture background1;
LTexture background2;
LTexture gameover;
LTexture cat;
LTexture gun;
LTexture dan;
LTexture gun_fire_effect;


Uint32 tmp_time = 0;

Enermy dog1;
Enermy dog2;
Enermy treasure;

bool GAME_OVER = false;
int x_mouse = 0;
int y_mouse = 0;

