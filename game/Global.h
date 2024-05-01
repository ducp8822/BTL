#ifndef GLOBAL_H_
#define GLOBAL_H_
#include "LTexture.h"
#include "lib.h"
#include "Enermy.h"
using namespace std;
//The renderer we'll be using
extern SDL_Renderer* gRenderer;

// The window we'll be rendering to
extern SDL_Window* gWindow;

extern LTexture background1;
extern LTexture background2;
extern LTexture gameover;
extern LTexture cat;
extern LTexture gun;
extern LTexture dan;
extern LTexture gun_fire_effect;

extern Enermy dog1;
extern Enermy dog2;
extern Enermy treasure;

extern Uint32 tmp_time;

extern int x_mouse;
extern int y_mouse;

extern bool GAME_OVER;

#endif // GLOBAL_H_
