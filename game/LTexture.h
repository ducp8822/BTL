#ifndef LTEXTURE_H_
#define LTEXTURE_H_

#include "lib.h"
#include "defs.h"


//Texture wrapper class
using namespace std;
class LTexture
{
public:
    //Initializes variables
    LTexture();

    //Deallocates memory
    ~LTexture();

    //Loads image at specified path
    bool loadFromFile(std::string path);

    //Deallocates texture
    void free();

    //Set color modulation
    void setColor( Uint8 red, Uint8 green, Uint8 blue );

    //Set blending
    void setBlendMode( SDL_BlendMode blending );

    //Set alpha modulation
    void setAlpha( Uint8 alpha );

    //Renders texture at given point
    void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

    //Gets image dimensions
    int getWidth();
    int getHeight();
    // Set velocity
	void setVelocity(int vx, int vy);

	// Get velocity in x and y direction
	int getXVelocity();
	int getYVelocity();
	void checkvelocity();

	// Get position
	int getX();
	int getY();

	void move();

	void setPos(int x, int y);

private:
    //The actual hardware texture
    SDL_Texture* mTexture;

    //Image dimensions
    int mWidth;
    int mHeight;

    int mPosX, mPosY;
	int mVelX, mVelY;
};

#endif // LTEXTURE_H_
