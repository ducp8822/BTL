#ifndef MENU_H_
#define MENU_H_
#include "LTexture.h"

class Menu
{
private:
    LTexture text1;
    LTexture text2;
    LTexture text3;
    LTexture text4;
    LTexture anh;
    LTexture title1;
    LTexture title2;
    SDL_Event event_;
    bool kt;
    int x,y;
public:
    Menu();
    void bat_tat();
    void play();

    void showHowToPlay(SDL_Renderer* render_);
    bool Show(SDL_Renderer* render_,const char* text1_,const char* text2_, const char* text3_,const char* text4_,TTF_Font *font_,SDL_Color color_);

};


#endif // MENU_H_
