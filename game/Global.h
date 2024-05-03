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
extern LTexture music;
extern LTexture font1;
extern LTexture font2;
extern LTexture font3;
extern LTexture score;

extern Enermy dog1;
extern Enermy dog2;
extern Enermy treasure;
extern Enermy food;

extern Mix_Chunk *gun_music;
extern Mix_Chunk *gameover_music;
extern Mix_Chunk *food_music;


extern Uint32 tmp_time;

extern int x_mouse;
extern int y_mouse;

extern TTF_Font *gfont1;
extern TTF_Font *gfont2;


extern bool GAME_OVER;

#endif // GLOBAL_H_
