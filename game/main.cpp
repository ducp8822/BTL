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


int main(int argc, char *argv[])
{

    if (!init())
    {
        cout << "Failed to initialize!" << endl;
    }
    else
    {
        //Load media
        if (!loadMedia())
        {
            cout << "Failed to load media!" << endl;
        }
        else
        {
            //Main loop flag
            bool quit = false;

            //Event handler
            SDL_Event e;

            //While application is running
            while (!quit)
            {
                //Handle events on queue
                while (SDL_PollEvent(&e) != 0)
                {
                    //User requests quit
                    if (e.type == SDL_QUIT)
                    {
                        quit = true;
                    }
                }
                // khoi tao tro chuot
                SDL_Surface* icon = IMG_Load("images/popcat2_mini.png");
                SDL_Cursor* cursor = SDL_CreateColorCursor(icon, 0, 0);
                SDL_SetCursor(cursor);

                //Clear screen
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                SDL_RenderClear(gRenderer);

                //Render background texture to screen

                background2.render(0,0);
                cat.setPos((SCREEN_WIDTH - cat.getWidth()) / 2, (SCREEN_HEIGHT - cat.getHeight()) / 2);
                cat.setVelocity(0, 1);
                cat.loadFromFile("images/cat.png");
                cat.render(cat.getX(), cat.getY(), NULL, 0, NULL, SDL_FLIP_NONE);
                SDL_Delay(2000);
                cat.loadFromFile("images/cat_cry.png");
                cat.render(cat.getX(), cat.getY(), NULL, 0, NULL, SDL_FLIP_NONE);
                //Update screen
                SDL_RenderPresent(gRenderer);
            }
        }
    }

    //Free resources and close SDL
    close();

    return 0;
}
