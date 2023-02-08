/*===========*\
| MAIN HEADER |
\*===========*/

#ifndef _MAIN_H_
#define _MAIN_H_

//Headers
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <cstring>
#include <stdarg.h>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sys/stat.h>
#include <limits>
#include <sys/stat.h>
#include <bitset>
#include <chrono>
#include <thread>

//If running on Windows, use Windows
//working directory functions.
#ifdef _WIN32
	#include "external/wdirent.h"
	#include <direct.h>
	#define getCD _getcwd

#else
	#include <dirent.h>
	#include <unistd.h>
	#define getCD getcwd
#endif // _WIN32

void __stack_chk_fail(void);

#include "external/cJSON.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_net.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#ifndef __EMSCRIPTEN__
#include <squirrel3/squirrel.h>
#include <squirrel3/sqstdio.h>
#include <squirrel3/sqstdaux.h>
#include <squirrel3/sqstdmath.h>
#include <squirrel3/sqstdstring.h>
#include <squirrel3/sqstdsystem.h>
#else
#include <emscripten/emscripten.h>
#include <squirrel.h>
#include <sqstdio.h>
#include <sqstdaux.h>
#include <sqstdmath.h>
#include <sqstdstring.h>
#include <sqstdsystem.h>
#endif

using namespace std;

//Defines
#ifdef SQUNICODE
	#define scvprintf vwprintf
	#else
	#define scvprintf vprintf
#endif

//Prototypes
int xyInit();
void xyStart();
void xyEnd();
void xyPrint(HSQUIRRELVM v, const SQChar *s, ...);
int xyGetOS();
void xyUpdate();


#endif
