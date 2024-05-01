#include "Lfile.h"
bool init()
{
	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		cout << "SDL couldn't ! SDL error: " << SDL_GetError() << endl;
		return false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			cout << "Window coundn't not be created! SDL error: " << SDL_GetError() << endl;
            return false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << endl;
                return false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
                    return false;
				}
			}
		}
	}

	return true;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load background1
	if( !background1.loadFromFile( "images/background1.png" ) )
	{
		cout << "Failed to load background1 image" << endl;
		success = false;
	}

	//Load background2
	if( !background2.loadFromFile( "images/background2.png" ) )
	{
		cout << "Failed to load background2 image" << endl;
		success = false;
	}
    //Load cat
	if( !cat.loadFromFile( "images/cat.png" ) )
	{
		cout << "Failed to load cat image" << endl;
		success = false;
	}
	//Load dog1
	if( !dog1.loadFromFile( "images/dog1.png" ) )
	{
		cout << "Failed to load dog1 image" << endl;
		success = false;
	}
	//Load dog2
	if( !dog2.loadFromFile( "images/dog2.png" ) )
	{
		cout << "Failed to load dog2 image" << endl;
		success = false;
	}
	//Load gameover
	if( !gameover.loadFromFile( "images/gameover.png" ) )
	{
		cout << "Failed to load gameover image" << endl;
		success = false;
	}
	//Load dan
	if( !dan.loadFromFile( "images/dan.png" ) )
	{
		cout << "Failed to load dan image" << endl;
		success = false;
	}
	//Load treasure
	if( !treasure.loadFromFile( "images/treasure.png" ) )
	{
		cout << "Failed to load treasure image" << endl;
		success = false;
	}
	//Load gun_fire_effect
	if( !gun_fire_effect.loadFromFile( "images/gun_fire_effect.png" ) )
	{
		cout << "Failed to load gun_fire_effect image" << endl;
		success = false;
	}
	//Load gun
	if( !gun.loadFromFile( "images/gun.png" ) )
	{
		cout << "Failed to load gun image" << endl;
		success = false;
	}

	return success;
}

void close()
{
	//Free loaded images
	background1.free();
	cat.free();

	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

