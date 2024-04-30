#ifndef Lfile_H_
#define Lfile_H_
#include "lib.h"
#include "defs.h"
#include "Global.h"

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

#endif // Lfile_H_
