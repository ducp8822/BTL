#include "lib.h"
#include "defs.h"
#include "LTexture.h"
#include "Global.h"
#include "Lfile.h"

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
double degrees = 0;

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
                    }else if(e.type == SDL_MOUSEBUTTONDOWN)

                    {
                        degrees+=60;
                    }
                }

                //Clear screen
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                SDL_RenderClear(gRenderer);

                //Render background texture to screen
                background1.render(0, 0,NULL,degrees,NULL,SDL_FLIP_NONE);
                //Update screen
                SDL_RenderPresent(gRenderer);
            }
        }
    }

    //Free resources and close SDL
    close();

    return 0;
}
