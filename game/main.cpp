#include "lib.h"
#include "defs.h"
#include "LTexture.h"
#include "Global.h"
#include "Lfile.h"
#include "Enermy.h"
using namespace std;

int treasure_armor = 0;
int bullet_count =3;
bool press_mouse=false;
double angle_arrow;
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

    treasure_armor = 3;

    cat.setPos((SCREEN_WIDTH - cat.getWidth()) / 2, (SCREEN_HEIGHT - cat.getHeight()) / 2);
	cat.setVelocity(1, 1);
	cat.loadFromFile("images/cat.png");

	dog1.setVelocity(0, 1);
	dog2.setVelocity(0, 1);
	dog1.setPos(rand() % (SCREEN_WIDTH - dog1.getWidth()), -dog1.getHeight());
	dog2.setPos(rand() % (SCREEN_WIDTH - dog2.getWidth()), -dog2.getHeight());

	gun.setPos((SCREEN_WIDTH - gun.getWidth()) / 2, (SCREEN_HEIGHT - gun.getHeight()) / 2);
	dan.setPos((SCREEN_WIDTH - dan.getWidth()) / 2 - 15, dan.getHeight() + 20);
	treasure.setVelocity(0, 1);
	treasure.setPos(rand() % (SCREEN_WIDTH - treasure.getWidth()), -treasure.getHeight() - 20);
}

void game()
{
    SDL_GetMouseState(&x_mouse, &y_mouse);

	cat.checkvelocity();

	if (checkCollision(cat, treasure))
	{
		if (treasure_armor == 0)
		{
			bullet_count += 5;
			treasure.setPos(rand() % (SCREEN_WIDTH - treasure.getWidth()), -200);
			treasure_armor = 3;
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
		//GAME_OVER = true;
	}
	if (GAME_OVER == true)
    {
        if (cat.loadFromFile("images/cat_cry.png") == false)
			cout << "Failed to load cat_cry image" << endl;
    }
}

void render()
{
    background2.render(0, 0, NULL, 0, NULL, SDL_FLIP_NONE);

	dog1.render(dog1.getX(), dog1.getY(), NULL, 0, NULL, SDL_FLIP_NONE);
	dog2.render(dog2.getX(), dog2.getY(), NULL, 0, NULL, SDL_FLIP_NONE);

	gun.render(gun.getX(), gun.getY(), NULL, angle_arrow, NULL, SDL_FLIP_NONE);
	if (press_mouse)
	{
		gun_fire_effect.setPos(gun.getX() - (gun_fire_effect.getWidth() - gun.getWidth()) / 2, gun.getY() - (gun_fire_effect.getHeight() - gun.getHeight()) / 2);
		gun_fire_effect.render(gun_fire_effect.getX(), gun_fire_effect.getY(), NULL, angle_arrow, NULL, SDL_FLIP_NONE);
		press_mouse = false;
	}

	treasure.render(treasure.getX(), treasure.getY());

	cat.render(cat.getX(), cat.getY(), NULL, 0, NULL, SDL_FLIP_NONE);
    dan.render(dan.getX(), dan.getY());
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
        //Load media
        if (!loadMedia())
        {
            cout << "Failed to load media!" << endl;
        }
        else
        {
            //Main loop flag
            bool quit = false;

            initialize();

            //Event handler
            SDL_Event e;
            //While application is running
            while (!quit && !GAME_OVER)
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
									tmp_time = SDL_GetTicks();
									int push_x = -(x_mouse - cat.getX()) / 45 + cat.getXVelocity();
									int push_y = -(y_mouse - cat.getY()) / 45 + cat.getYVelocity();
									cat.setVelocity(push_x, push_y);
									bullet_count--;
                            }
						}
					}
					SDL_RenderClear(gRenderer);
					game();
					render();
					SDL_RenderPresent(gRenderer);
            }
            SDL_Delay(1000);
        }
    }

    SDL_Delay(500);
    //Free resources and close SDL
    close();

    return 0;
}
