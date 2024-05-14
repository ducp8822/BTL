#include "Menu.h"
#include "Global.h"

Menu::Menu()
{
    kt=false;
}
void Menu::bat_tat()
{
    kt=!kt;
}
void  Menu::play()
{
     Mix_PlayMusic(m_music,-1);
}
void Menu::showHowToPlay(SDL_Renderer* render_)
{
    // Mảng chứa các tên tệp hình ảnh hướng dẫn
    const char* howToPlayImages[] = {
        "images/how_to_play1.png",
        "images/how_to_play2.png"
    };
    int totalImages = 2;  // Tổng số hình ảnh
    int currentImageIndex = 0;  // Chỉ mục của hình ảnh hiện tại

    LTexture return_;
    return_.loadFromFile("images/return.png");

    LTexture right;
    right.loadFromFile("images/right.png");

    LTexture left;
    left.loadFromFile("images/left.png");

    LTexture howToPlayImage;
    howToPlayImage.loadFromFile(howToPlayImages[currentImageIndex]);
    howToPlayImage.render(0, 0);
    return_.render(25,10);
    right.render(SCREEN_WIDTH-right.getWidth()-50,SCREEN_HEIGHT/2);

    SDL_RenderPresent(render_);

    while (true) {
        SDL_PollEvent(&event_);
        if (event_.type == SDL_QUIT) {
            return;
        }
        int x = event_.button.x;
        int y = event_.button.y;
        if(x!=0 && y!=0)
            cerr<<x<<" "<<y<<endl;
        if (event_.type == SDL_MOUSEBUTTONDOWN) {
            // Kiểm tra nhấn vào vùng "right"
            if (x >= SCREEN_WIDTH - right.getWidth() - 50 && x <= SCREEN_WIDTH - right.getWidth() && y >= SCREEN_HEIGHT / 2 && y <= SCREEN_HEIGHT / 2 + right.getHeight()) {
                currentImageIndex = 1;  // Chuyển sang ảnh 2
            }

            // Kiểm tra nhấn vào vùng "left"
            if (x >= 50 && x <= 50 + left.getWidth() && y >= SCREEN_HEIGHT / 2 && y <= SCREEN_HEIGHT / 2 + left.getHeight()) {
                currentImageIndex = 0;  // Chuyển sang ảnh 1
            }

            // Cập nhật và hiển thị ảnh mới
            SDL_RenderClear(render_);
            howToPlayImage.loadFromFile(howToPlayImages[currentImageIndex]);
            howToPlayImage.render(0, 0);
            return_.render(25, 10);

            if (currentImageIndex == 0) {
                right.render(SCREEN_WIDTH - right.getWidth() - 50, SCREEN_HEIGHT / 2);
            } else if (currentImageIndex == 1) {
                left.render(50, SCREEN_HEIGHT / 2);
            }

            SDL_RenderPresent(render_);
            if(x>=25 && x<=60 && y>=10 && y<=40)
            {
                return;
            }
        }
    }

    // Xóa hình ảnh hướng dẫn khi thoát
    SDL_RenderClear(render_);
    SDL_RenderPresent(render_);
}


bool Menu:: Show(SDL_Renderer* render_,const char* text1_,const char* text2_, const char* text3_,const char* text4_,TTF_Font *font_,SDL_Color color_)
{
        play();
        anh.loadFromFile("images/2.png");
        anh.render(0,0);
        on.render(1295,10);

        title1.loadFromFile("images/title.png");
        title1.render(406,330);
        title1.render(406,480);
        title1.render(406,630);

        title2.loadFromFile("images/title2.png");

        text1.renderText(text1_,font_,color_);

        text2.renderText(text2_,font_,color_);

        //text3.renderText(text3_,font_,color_);
        //text3.render(660,276);

        text4.renderText(text4_,font_,color_);
        //text4.render(660,660);
        SDL_RenderPresent(render_);
        while (true) {
        SDL_PollEvent(&event_);
        SDL_GetMouseState(&x, &y);
        switch (event_.type) {
            case SDL_QUIT:
                 return 1;
                 break;
            case SDL_MOUSEMOTION:
                cerr<<x<<" "<<y<<endl;
                if(x>=400 && x<=860 && y>=475 && y<=575 )
                {

                    title2.render(406,480);
                    text4.render(455,510);
                    SDL_RenderPresent(render_);
                }else if(x>=400 && x<=860 && y>=620 && y<=725)
                {
                    title2.render(406,630);
                    text2.render(580,660);
                    SDL_RenderPresent(render_);
                }else if(x>=400 && x<=860 && y>=325 && y<=425)
                {
                    title2.render(406,330);
                    text1.render(485,360);
                    SDL_RenderPresent(render_);
                }
                else
                {
                    title1.render(406,330);
                    text1.render(485,360);

                    title1.render(406,480);
                    text4.render(455,510);

                    title1.render(406,630);
                    text2.render(580,660);

                    SDL_RenderPresent(render_);

                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                if(x>=400 && x<=860 && y>=325 && y<=425)
                {
                    Mix_PlayChannelTimed(-1,ting,0,100);
                    //play game
                    return 0;
                }
                if(x>=400 && x<=860 && y>=620 && y<=725)
                {
                    //exit
                    Mix_PlayChannelTimed(-1,ting,0,100);
                    return 1;
                }
                if(x>=400 && x<=860 && y>=475 && y<=575)
                {
                    //how to play
                    Mix_PlayChannelTimed(-1,ting,0,100);
                    showHowToPlay(render_);
                    anh.loadFromFile("images/2.png");
                    anh.render(0, 0);
                    on.render(1295, 10);
                    title1.loadFromFile("images/title.png");
                    title1.render(406, 330);
                    title1.render(406, 480);
                    title1.render(406, 630);

                    title2.loadFromFile("images/title2.png");

                    text1.renderText(text1_, font_, color_);
                    text2.renderText(text2_, font_, color_);
                    text4.renderText(text4_, font_, color_);

                    SDL_RenderPresent(render_);
                }
                if(y>=10 && y<=50 && x<=1335 && x>=1295)
                {
                       bat_tat();
                       if(kt)
                       {
                           on.render(1295,10);
                           Mix_PlayMusic(m_music,-1);
                       }
                       else
                       {
                           off.render(1295,10);
                           Mix_HaltMusic();
                       }
                }

                break;
        }
    }


}
