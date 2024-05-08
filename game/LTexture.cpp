#include "LTexture.h"
#include "Global.h"
LTexture::LTexture()
{
	//Initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
	mPosX = 0;
	mPosY = 0;
	mVelX = 0;
	mVelY = 0;
}

LTexture::~LTexture()
{
	//Deallocate
	free();
}

bool LTexture::loadFromFile(std::string path)
{
	//Get rid of preexisting texture
	free();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
}

void LTexture::free()
{
	//Free texture if it exists
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void LTexture::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
	//Modulate texture rgb
	SDL_SetTextureColorMod(mTexture, red, green, blue);
}

void LTexture::setBlendMode(SDL_BlendMode blending)
{
	//Set blending function
	SDL_SetTextureBlendMode(mTexture, blending);
}

void LTexture::setAlpha(Uint8 alpha)
{
	//Modulate texture alpha
	SDL_SetTextureAlphaMod(mTexture, alpha);
}

SDL_Texture* LTexture::renderText(const char* text,TTF_Font* font, SDL_Color textColor)
{
    SDL_Surface* textSurface= TTF_RenderText_Solid(font,text,textColor);
    if(textSurface==NULL)
    {
        cout<<"Render text surface %s"<<TTF_GetError()<<endl;
        return nullptr;
    }
    SDL_Texture *texture=SDL_CreateTextureFromSurface(gRenderer,textSurface);
    {
        if(texture==NULL)
        {
            cout<< "Create texture from text %s"<<SDL_GetError()<<endl;
        }
        else
        {
            mWidth=textSurface->w;
            mHeight=textSurface->h;
        }
        SDL_FreeSurface(textSurface);
    }
    mTexture=texture;
    return mTexture;
}

void LTexture::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx(gRenderer, mTexture, clip, &renderQuad, angle, center, flip);
}

int LTexture::getWidth()
{
	return mWidth;
}

int LTexture::getHeight()
{
	return mHeight;
}
void LTexture::setVelocity(int vx, int vy) {
	mVelX = vx;
	mVelY = vy;
}

int LTexture::getX() {
	return mPosX;
}

int LTexture::getY() {
	return mPosY;
}

void LTexture::move() {

	mPosX += mVelX;
	mPosY += mVelY;

	if (mPosX <= 2) {
		mVelX = -mVelX;
	}
	else if (mPosX >= SCREEN_WIDTH - mWidth - 2) {
		mVelX = -mVelX;
	}
	else if (mPosY <= 2) {
		mVelY = -mVelY;
	}
	else if (mPosY >= SCREEN_HEIGHT - mHeight - 2) {
		mVelY = -mVelY;
	}
}

void LTexture::setPos(int x, int y) {
	mPosX = x;
	mPosY = y;
}

int LTexture::getXVelocity()
{
	return mVelX;
}

int LTexture::getYVelocity()
{
	return mVelY;
}

void LTexture::checkvelocity()
{
	if (mVelX > 10) mVelX = 10;
	if (mVelX < -10) mVelX = -10;
	if (mVelY > 10) mVelY = 10;
	if (mVelY < -10) mVelY = -10;
    if (int(SDL_GetTicks() - tmp_time)/ 1500 == 1)
	{
		tmp_time = SDL_GetTicks();
		if (mVelX > 1) mVelX--;
		if (mVelY > 1) mVelY--;
		if (mVelX < -1) mVelX++;
		if (mVelY < -1) mVelY++;
	}
}
