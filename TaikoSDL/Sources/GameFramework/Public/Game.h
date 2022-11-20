#pragma once
#include "SDL.h"
#include <iostream>
#include "Public\TJAParser.h"

class Game
{
    
public:
    Game();
    ~Game();

    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);


    void handleEvents();
    void update();
    void render();
    void clean();

    bool running();
    
private:
    int cnt = 0;
    
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
    
};
