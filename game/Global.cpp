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
LTexture music;
LTexture font1;
LTexture font2;
LTexture font3;
LTexture score;
LTexture on;
LTexture off;

 Mix_Chunk *gun_music=NULL;
 Mix_Chunk *gameover_music=NULL;
 Mix_Chunk *food_music=NULL;
 Mix_Chunk *ting;

Mix_Music *music_;
Mix_Music *m_music;

Enermy dog1;
Enermy dog2;
Enermy treasure;
Enermy food;


TTF_Font *gfont1;
TTF_Font *gfont2;


bool GAME_OVER = false;
int x_mouse = 0;
int y_mouse = 0;
int tmp_time=0;

