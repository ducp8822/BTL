#ifndef MENU_H_
#define MENU_H_
#include "LTexture.h"
#include "Global.h"

class Menu
{
private:
    LTexture text1;
    LTexture text2;
    LTexture anh;
public:
    Menu()
    {

    }
    int Show(SDL_Renderer* render_,const char* text1_,const char* text2_, const char* text3_,TTF_Font *font_,SDL_Color color_)
    {
        anh.loadFromFile("images/background1.png");
        anh.render(0,0);
        text1.renderText(text1_,font_,color_);
        text1.render(400,300);
        text2.renderText(text2_,font_,color_);
        text2.render(500,700);
        SDL_RenderPresent(render_);
        SDL_Delay(5000);
        return 1;
    }
};

#endif // MENU_H_
