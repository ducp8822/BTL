#ifndef MENU_H_
#define MENU_H_
#include "LTexture.h"

class Menu
{
private:
    LTexture text1;
    LTexture text2;
    LTexture text3;
    LTexture anh;
    LTexture title1;
    LTexture title2;
    SDL_Event event_;
    bool kt;
    int x,y;
public:
    Menu()
    {
        kt=true;
    }
    void bat_tat()
    {
        kt=!kt;
    }
    void play()
    {
        Mix_PlayMusic(m_music,-1);

    }
    bool Show(SDL_Renderer* render_,const char* text1_,const char* text2_, const char* text3_,TTF_Font *font_,SDL_Color color_)
    {
        play();
        anh.loadFromFile("images/1.png");
        anh.render(0,0);
        on.render(SCREEN_WIDTH-on.getWidth(),0);

        title1.loadFromFile("images/title.png");
        title1.render(406,424);
        title1.render(406,603);

        title2.loadFromFile("images/title2.png");

        text1.renderText(text1_,font_,color_);

        text2.renderText(text2_,font_,color_);

        text3.renderText(text3_,font_,color_);
        text3.render(660,276);
        SDL_RenderPresent(render_);
        while (true) {
        SDL_PollEvent(&event_);
        SDL_GetMouseState(&x, &y);
        switch (event_.type) {
            case SDL_QUIT:
                 return 1;
                 break;
            case SDL_MOUSEMOTION:
                if(x>=405 && x<=866 && y>=400 && y<=538 )
                {

                    title2.render(406,424);
                    text1.render(485,455);
                    SDL_RenderPresent(render_);
                }else if(x>=405 && x<=866 && y>=593 && y<=715)
                {
                    title2.render(406,603);
                    text2.render(580,632);
                    SDL_RenderPresent(render_);
                }else
                {
                    title1.render(406,424);
                    text1.render(485,455);

                    title1.render(406,603);
                    text2.render(580,632);
                    SDL_RenderPresent(render_);

                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                if(x>=405 && x<=866 && y>=400 && y<=538)
                {
                    Mix_PlayChannelTimed(-1,ting,0,100);
                    //play game
                    return 0;
                }
                if(x>=405 && x<=866 && y>=593 && y<=715)
                {
                    Mix_PlayChannelTimed(-1,ting,0,100);
                    return 1;
                }
                if(y>=0 && y<=on.getHeight() && x<=SCREEN_WIDTH && x>=(SCREEN_WIDTH-on.getWidth()))
                {
                       bat_tat();
                       if(kt)
                       {
                           on.render(SCREEN_WIDTH-on.getWidth(),0);
                           Mix_PlayMusic(m_music,-1);
                       }
                       else
                       {
                           off.render(SCREEN_WIDTH-on.getWidth(),0);
                           Mix_HaltMusic();
                       }
                }

                break;
        }
    }

    }
};


#endif // MENU_H_
