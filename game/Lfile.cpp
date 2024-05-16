#include "Lfile.h"
bool init()
{
	//Initialize SDL
	if( SDL_Init( SDL_INIT_EVERYTHING) < 0 )
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
				if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048)<0)
                {
                    cout<<"SDL_mixer could not initialize! SDL_mixer Error: "<< Mix_GetError()<< endl;
                    return false;
                }
                if(TTF_Init() == -1)
                {
                    cout<<"SDL_ttf could not initialize! SDL_ttf Error: "<<TTF_GetError()<< endl;
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

	//load anh

	//Load background2
	if( !background2.loadFromFile( "images/background2.png" ) )
	{
		cout << "Failed to load background2 image" << IMG_GetError()<<endl;
		success = false;
	}
    //Load cat
	if( !cat.loadFromFile( "images/cat.png" ) )
	{
		cout << "Failed to load cat image" <<IMG_GetError()<< endl;
		success = false;
	}
	//Load dog1
	if( !dog1.loadFromFile( "images/dog1.png" ) )
	{
		cout << "Failed to load dog1 image" <<IMG_GetError()<< endl;
		success = false;
	}
	//Load dog2
	if( !dog2.loadFromFile( "images/dog2.png" ) )
	{
		cout << "Failed to load dog2 image" << IMG_GetError()<<endl;
		success = false;
	}
	//Load gameover
	if( !gameover.loadFromFile( "images/gameover.png" ) )
	{
		cout << "Failed to load gameover image" << IMG_GetError()<<endl;
		success = false;
	}
	//Load dan
	if( !dan.loadFromFile( "images/dan.png" ) )
	{
		cout << "Failed to load dan image" << IMG_GetError()<<endl;
		success = false;
	}
	//Load treasure
	if( !treasure.loadFromFile( "images/treasure.png" ) )
	{
		cout << "Failed to load treasure image" <<IMG_GetError()<< endl;
		success = false;
	}
	//Load gun_fire_effect
	if( !gun_fire_effect.loadFromFile( "images/gun_fire_effect.png" ) )
	{
		cout << "Failed to load gun_fire_effect image" <<IMG_GetError()<< endl;
		success = false;
	}
	//Load gun
	if( !gun.loadFromFile( "images/gun.png" ) )
	{
		cout << "Failed to load gun image" << IMG_GetError()<<endl;
		success = false;
	}
	//Load food
	if( !food.loadFromFile( "images/food.png" ) )
	{
		cout << "Failed to load food image" << IMG_GetError()<<endl;
		success = false;
	}
	//Load score
	if( !score.loadFromFile( "images/score.png" ) )
	{
		cout << "Failed to load score image" <<IMG_GetError()<< endl;
		success = false;
	}
	//Load on
	if( !on.loadFromFile( "images/on.png" ) )
	{
		cout << "Failed to load on image" <<IMG_GetError()<< endl;
		success = false;
	}
	//Load off
	if( !off.loadFromFile( "images/off.png" ) )
	{
		cout << "Failed to load off image" <<IMG_GetError()<< endl;
		success = false;
	}
	 if (cat.loadFromFile("images/cat_cry.png") == false)
     {
         cout << "Failed to load off image" <<IMG_GetError()<< endl;
		success = false;
     }
	//load musicc

	//Load food_music
	food_music=Mix_LoadWAV("musics/food_music.wav");
	if(food_music == NULL)
    {
        cout<< "Failed to load food_music"<<Mix_GetError() <<endl;
        success=false;
    }
    //Load gun_music
	gun_music=Mix_LoadWAV("musics/gun_music.wav");
	if(gun_music == NULL)
    {
        cout<< "Failed to load gun_music" <<Mix_GetError()<<endl;
        success=false;
    }
    //Load gameover_music
	gameover_music=Mix_LoadWAV("musics/gameover_music.wav");
	if(gameover_music == NULL)
    {
        cout<< "Failed to load gameover_music" <<Mix_GetError()<<endl;
        success=false;
    }

    music_=Mix_LoadMUS("musics/music_.mp3");
    if(music_==NULL)
    {
        cout<< "Failed to load music_" <<Mix_GetError()<<endl;
        success=false;
    }
    m_music=Mix_LoadMUS("musics/m_music.mp3");
    if(m_music==NULL)
    {
        cout<< "Failed to load  m_music" <<Mix_GetError()<<endl;
        success=false;
    }
    ting=Mix_LoadWAV("musics/ting.wav");
    if(ting==NULL)
    {
        cout<< "Failed to load  ting" <<Mix_GetError()<<endl;
        success=false;
    }


    //load font

    gfont1=TTF_OpenFont("fonts/font1.ttf",57);
        if(gfont1 == nullptr)
        {
            cout<<"Load font %s"<<TTF_GetError()<<endl;
            success=false;
        }
     gfont2=TTF_OpenFont("fonts/font2.ttf",25);
        if(gfont1 == nullptr)
        {
            cout<<"Load font %s"<<TTF_GetError()<<endl;
            success=false;
        }


	return success;
}

void close()
{
	//Free loaded images
	background1.free();
	background2.free();
	gameover.free();
	cat.free();
	gun.free();
	dan.free();
	gun_fire_effect.free();
	music.free();
	font1.free();
	font2.free();
	font3.free();
	score.free();
	on.free();
	off.free();
	dog1.free();
	dog2.free();
	treasure.free();
	food.free();

	gWindow = NULL;
	gRenderer = NULL;


    gameover_music=NULL;
    gun_music= NULL;
    food_music = NULL;


	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );

	//Quit SDL subsystems
	IMG_Quit();
	Mix_Quit();
    TTF_Quit();
	SDL_Quit();
}

