#include "pch.h"
#include "application.h"

namespace nightsquad {
    NIGHTSQUAD_API void run_application(const app_config& config) {
        if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
            std::cout << "sdl initialized!" << std::endl;
        }
        if(IMG_Init(IMG_INIT_PNG) > 0) {
            std::cout << "sdl image initialized!" << std::endl;
        }
        if(TTF_Init() == 0) {
            std::cout << "sdl ttf initialized!" << std::endl;
        }
        if(Mix_Init(MIX_INIT_MP3) > 0) {
            std::cout << "sdl mixer initialized!" << sstd::endl;
        }
        SDL_Quit();
        IMG_Quit();
        TTF_Quit();
        Mix_Quit();
    }
}