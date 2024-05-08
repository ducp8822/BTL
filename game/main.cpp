#include "lib.h"
#include "defs.h"
#include "LTexture.h"
#include "Global.h"
#include "Lfile.h"
#include "Enermy.h"
#include "Menu.h"
using namespace std;

int treasure_armor = 0;
int bullet_count;
bool press_mouse=false;
double angle_arrow;
int point=0;
int highScore=0;
Menu menu;
SDL_Color color={205,100,0,255};


void waitUntilMouseKeyPressed()
{
    SDL_Event e;
    while (true) {
        if (SDL_PollEvent(&e) != 0 &&
            (e.type == SDL_KEYDOWN || e.type == SDL_QUIT))
            return;
        SDL_Delay(10);
    }
}
bool checkCollision(LTexture& a, Enermy& b)
{
	int leftA = a.getX();
	int rightA = a.getX() + a.getWidth();
	int topA = a.getY();
	int bottomA = a.getY() + a.getHeight();

	int leftB = b.getX();
	int rightB = b.getX() + b.getWidth();
	int topB = b.getY();
	int bottomB = b.getY() + b.getHeight();

	if (bottomA <= topB || topA >= bottomB || rightA <= leftB || leftA >= rightB)
	{
		return false;
	}
	return true;
}
double getAngle(double x, double y, double x0, double y0) {
	x -= x0;
	y -= y0;
	return atan2(y, x) * 180 / M_PI;
}


void initialize()
{
    srand(time(0));
    point=0;
    treasure_armor = 3;
    bullet_count=3;

    cat.setPos((SCREEN_WIDTH - cat.getWidth()) / 2, (SCREEN_HEIGHT - cat.getHeight()) / 2);
	cat.setVelocity(0, 0);
	cat.loadFromFile("images/cat.png");
	dog1.setVelocity(0, 1);
	dog2.setVelocity(0, 1);
	dog1.setPos(rand() % (SCREEN_WIDTH - dog1.getWidth()), -dog1.getHeight());
	dog2.setPos(rand() % (SCREEN_WIDTH - dog2.getWidth()), -dog2.getHeight());

    food.renew();

	gun.setPos((SCREEN_WIDTH - gun.getWidth()) / 2, (SCREEN_HEIGHT - gun.getHeight()) / 2);
	dan.setPos((SCREEN_WIDTH - dan.getWidth())/2 +20 , dan.getHeight()-30);
	score.setPos((SCREEN_WIDTH - dan.getWidth())/2 +100 , dan.getHeight()-20);
	treasure.setVelocity(0, 1);
	treasure.setPos(rand() % (SCREEN_WIDTH - treasure.getWidth()), -treasure.getHeight() - 20);
}
Uint32 time_reload;
void reload_bullet()
{
    if((SDL_GetTicks()-time_reload)>=2000)
    {
        bullet_count++;
        time_reload=SDL_GetTicks();
    }
}

void game()
{
    reload_bullet();
    SDL_GetMouseState(&x_mouse, &y_mouse);

	cat.checkvelocity();

	if (checkCollision(cat, treasure))
	{
	    Mix_PlayChannel(-1,food_music,0);
		if (treasure_armor == 0)
		{
			bullet_count += 5;
			treasure.setPos(rand() % (SCREEN_WIDTH - treasure.getWidth()), -200);
			treasure_armor = 3;
			point+=5;
		}
		else
		{
			cat.setVelocity(-cat.getXVelocity(), -cat.getYVelocity());
			treasure_armor--;
		}
	}

	cat.move();
	dog1.move();
	dog2.move();
	treasure.move();

	gun.setPos(cat.getX() - (gun.getWidth() - cat.getWidth()) / 2, cat.getY() - (gun.getHeight() - cat.getHeight()) / 2);
	angle_arrow = getAngle(x_mouse, y_mouse, gun.getX() + gun.getWidth() / 2, gun.getY() + gun.getHeight() / 2);

	if (checkCollision(cat, dog1) || checkCollision(cat, dog2))
	{
		GAME_OVER = false;
	}

	while(checkCollision(cat,food))
	{
	    Mix_PlayChannel(-1,food_music,0);
	    bullet_count+=2;
	    food.renew();
	    point+=1;
	}


}

void render()
{

    string s=to_string(bullet_count);
    const char* bullet=s.c_str();

    string s1=to_string(treasure_armor);
    const char* treasure_armor=s1.c_str();

    background2.render(0, 0, NULL, 0, NULL, SDL_FLIP_NONE);

    score.render(score.getX()-20,score.getY());

    font1.renderText(bullet,gfont1,color);
	font1.render(SCREEN_WIDTH/2-70,27);

	font2.renderText(treasure_armor,gfont2,color);
	font2.render(treasure.getX()+treasure.getWidth(), treasure.getY()+treasure.getHeight()-20);

	dog1.render(dog1.getX(), dog1.getY(), NULL, 0, NULL, SDL_FLIP_NONE);
	dog2.render(dog2.getX(), dog2.getY(), NULL, 0, NULL, SDL_FLIP_NONE);
	food.render(food.getX(),food.getY());

	gun.render(gun.getX(), gun.getY(), NULL, angle_arrow, NULL, SDL_FLIP_NONE);
	if (press_mouse)
	{
	    Mix_PlayChannel(-1,gun_music,0);
		gun_fire_effect.setPos(gun.getX() - (gun_fire_effect.getWidth() - gun.getWidth()) / 2, gun.getY() - (gun_fire_effect.getHeight() - gun.getHeight()) / 2);
		gun_fire_effect.render(gun_fire_effect.getX(), gun_fire_effect.getY(), NULL, angle_arrow, NULL, SDL_FLIP_NONE);
		press_mouse = false;
	}

	treasure.render(treasure.getX(), treasure.getY());

	cat.render(cat.getX(), cat.getY(), NULL, 0, NULL, SDL_FLIP_NONE);
    dan.render(dan.getX(), dan.getY());
    on.render(SCREEN_WIDTH-on.getWidth(),0);

	if (GAME_OVER) {
		gameover.render((SCREEN_WIDTH - gameover.getWidth()) / 2, (SCREEN_HEIGHT - gameover.getHeight()) / 2, NULL, 0, NULL, SDL_FLIP_NONE);
	}
}


int main(int argc, char *argv[])
{
    if (!init())
    {
        cout << "Failed to initialize!" << endl;
    }
    else
    {
        // khoi tao tro chuot
        SDL_Surface* icon = IMG_Load("images/popcat2_mini.png");
        SDL_Cursor* cursor = SDL_CreateColorCursor(icon, 0, 0);
        SDL_SetCursor(cursor);

        //icon game
        SDL_Surface* icon1=IMG_Load("images/logo.png");
        SDL_SetWindowIcon(gWindow,icon1);

        //Load media
        if (!loadMedia())
        {
            cout << "Failed to load media!" << endl;
        }
        else
        {
            string s3=to_string(highScore);
            const char* highScore_=s3.c_str();

            //Main loop flag
            bool quit = false;
             quit=menu.Show(gRenderer,"play game","Exit",highScore_,gfont1,color);
            Mix_PlayMusic(music_,-1);
            initialize();
            while(!quit){

            //Event handler
            SDL_Event e;
            //While application is running
            while (!quit)
            {

                while (SDL_PollEvent(&e) != 0)
					{
						if (e.type == SDL_QUIT)
						{
							quit = true;
							GAME_OVER = true;
						}
						if (e.type == SDL_MOUSEBUTTONDOWN)
						{
							SDL_GetMouseState(&x_mouse, &y_mouse);
                            if (bullet_count > 0)
                            {

									int push_x = -(x_mouse - cat.getX()) / 45 + cat.getXVelocity();
									int push_y = -(y_mouse - cat.getY()) / 45 + cat.getYVelocity();
									cat.setVelocity(push_x, push_y);
									bullet_count--;
									press_mouse=true;

                            }
						}
					}
					game();
					render();
					string s2=to_string(point);
                    const char* point_=s2.c_str();

                    font3.renderText(point_,gfont1,color);
                    font3.render(SCREEN_WIDTH/2+100,27);
                    highScore=max(highScore,point);
                    SDL_RenderPresent(gRenderer);
					SDL_Delay(5);
					if (GAME_OVER == true )
                    {
                        cat.loadFromFile("images/cat_cry.png");
                        SDL_RenderPresent(gRenderer);
                        Mix_PauseMusic();
                        Mix_PlayChannel(-1,gameover_music,0);
                        SDL_Delay(2500);
                        quit=menu.Show(gRenderer,"play again","Exit",highScore_,gfont1,color);
                        Mix_PlayMusic(music_,-1);
                        initialize();
                        GAME_OVER=false;
                        break;
                    }
            }
        }
        }
    }
    //Free resources and close SDL
    close();
    return 0;
}
