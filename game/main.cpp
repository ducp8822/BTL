#include "lib.h"
#include "defs.h"
#include "LTexture.h"
#include "Global.h"
#include "Lfile.h"
#include "Enermy.h"
using namespace std;

void waitUntilMousePressed()
{
    SDL_Event e;
    while (true) {
        if (SDL_PollEvent(&e) != 0 &&
            (e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_QUIT))
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


void initialize()
{
    srand(time(0));
    cat.setPos((SCREEN_WIDTH - cat.getWidth()) / 2, (SCREEN_HEIGHT - cat.getHeight()) / 2);
	cat.setVelocity(1, 1);
	cat.loadFromFile("images/cat.png");
	dog1.setVelocity(0, 1);
	dog2.setVelocity(0, 1);
	dog1.setPos(rand() % (SCREEN_WIDTH - dog1.getWidth()), -dog1.getHeight());
	dog2.setPos(rand() % (SCREEN_WIDTH - dog2.getWidth()), -dog2.getHeight());
}

void game()
{
    SDL_GetMouseState(&x_mouse, &y_mouse);

	cat.checkvelocity();
	cat.move();
	dog1.move();
	dog2.move();

	if (checkCollision(cat, dog1) || checkCollision(cat, dog2))
	{
		GAME_OVER = true;
	}
}

void render()
{
    background2.render(0, 0, NULL, 0, NULL, SDL_FLIP_NONE);

	dog1.render(dog1.getX(), dog1.getY(), NULL, 0, NULL, SDL_FLIP_NONE);
	dog2.render(dog2.getX(), dog2.getY(), NULL, 0, NULL, SDL_FLIP_NONE);
	cat.render(cat.getX(), cat.getY(), NULL, 0, NULL, SDL_FLIP_NONE);
	if (GAME_OVER) {
		gameover.render((SCREEN_WIDTH - gameover.getWidth()) / 2, (SCREEN_HEIGHT - gameover.getHeight()) / 2, NULL, 0, NULL, SDL_FLIP_NONE);
	}
}

int bullet_count =3;
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
									//tmp_time = SDL_GetTicks();
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
