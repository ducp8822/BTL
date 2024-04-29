#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "graphics.h"
#include "defs.h"

using namespace std;

void waitUntilMousePressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_PollEvent(&e) != 0 &&
             (e.type == SDL_MOUSEBUTTONDOWN|| e.type == SDL_QUIT) )
            return;
        SDL_Delay(10);
    }
}
int main(int argc, char *argv[])
{
    Graphics graphics;
    graphics.init();

    // load background1
    SDL_Texture *background1= graphics.loadTexture("images/background1.png");
    graphics.prepareScene(background1);
    graphics.presentScene();
    SDL_DestroyTexture(background1);
    waitUntilMousePressed();


    // load background2
    SDL_Texture *background2= graphics.loadTexture("images/background2.png");
    graphics.prepareScene(background2);
    graphics.presentScene();
    SDL_DestroyTexture(background2);
    waitUntilMousePressed();

    //load cat
    SDL_Texture *cat= graphics.loadTexture("images/cat.png");
    graphics.renderTexture(cat,100,200);
    graphics.presentScene();
    SDL_DestroyTexture(cat);
    waitUntilMousePressed();
    graphics.prepareScene();

    // load dog
    SDL_Texture *dog= graphics.loadTexture("images/dog.png");
    graphics.renderTexture(dog,400,200);
    graphics.presentScene();
    SDL_DestroyTexture(dog);
    waitUntilMousePressed();

    //load dog2
    SDL_Texture *dog2= graphics.loadTexture("images/dog2.png");
    graphics.renderTexture(dog2,300,200);
    graphics.presentScene();
    SDL_DestroyTexture(dog2);
    waitUntilMousePressed();
    graphics.prepareScene();

    //load gameover
    SDL_Texture *gameover= graphics.loadTexture("images/gameover.png");
    graphics.renderTexture(gameover,300,400);
    graphics.presentScene();
    SDL_DestroyTexture(gameover);
    waitUntilMousePressed();
    graphics.prepareScene();

    //load Gun
    SDL_Texture *Gun= graphics.loadTexture("images/Gun.png");
    graphics.renderTexture(Gun,300,400);
    graphics.presentScene();
    SDL_DestroyTexture(Gun);
    waitUntilMousePressed();
    graphics.prepareScene();

    //load gun_fire_effect
    SDL_Texture *gun_fire_effect= graphics.loadTexture("images/gun_fire_effect.png");
    graphics.renderTexture(gun_fire_effect,300,400);
    graphics.presentScene();
    SDL_DestroyTexture(gun_fire_effect);
    waitUntilMousePressed();
    graphics.prepareScene();

    //load pate
    SDL_Texture *pate= graphics.loadTexture("images/pate.png");
    graphics.renderTexture(pate,300,400);
    graphics.presentScene();
    SDL_DestroyTexture(pate);
    waitUntilMousePressed();
    graphics.prepareScene();

    //load music-on
    SDL_Texture *music_on= graphics.loadTexture("images/music-on.png");
    graphics.renderTexture(music_on,300,400);
    graphics.presentScene();
    SDL_DestroyTexture(music_on);
    waitUntilMousePressed();
    graphics.prepareScene();

    //load score
    SDL_Texture *score= graphics.loadTexture("images/score.png");
    graphics.renderTexture(score,300,400);
    graphics.presentScene();
    SDL_DestroyTexture(score);
    waitUntilMousePressed();
    graphics.prepareScene();

    //load right_arrow
    SDL_Texture *right_arrow= graphics.loadTexture("images/right_arrow.png");
    graphics.renderTexture(right_arrow,300,400);
    graphics.presentScene();
    SDL_DestroyTexture(right_arrow);
    waitUntilMousePressed();
    graphics.prepareScene();

    //load music-off
    SDL_Texture *music_off= graphics.loadTexture("images/music-off.png");
    graphics.renderTexture(music_off,300,400);
    graphics.presentScene();
    SDL_DestroyTexture(music_off);
    waitUntilMousePressed();
    graphics.prepareScene();



    return 0;
    graphics.quit();
}
