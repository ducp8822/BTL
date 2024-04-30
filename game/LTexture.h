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

    //Renders texture at given point
    void render(int x, int y,SDL_Rect *clip=NULL);

    //Gets image dimensions
    int getWidth();
    int getHeight();

private:
    //The actual hardware texture
    SDL_Texture* mTexture;

    //Image dimensions
    int mWidth;
    int mHeight;
};

#endif // LTEXTURE_H_
