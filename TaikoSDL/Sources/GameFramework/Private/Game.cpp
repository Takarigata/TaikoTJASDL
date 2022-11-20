#include "../Public/Game.h"

#include <algorithm>

Game::Game()
{}

Game::~Game()
{}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "Subsystems Init..." << std::endl;
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(window)
        {
            std::cout << "Window Created" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255,0,255,255);
            std::cout << "Renderer Created" << std::endl;
        }

        isRunning = true;
    }
    else
    {
        isRunning = false;
    }

    TJAPARSER::TJAParserLib* ParserLib = new TJAPARSER::TJAParserLib();
    ParserLib->ParseTJAFile("C:\\DEV\\Bluebird.tja");
}

void Game::update()
{
    cnt++;
    //std::cout << cnt << std::endl;
    //TJAPARSER::PrintTJA(cnt);
}

void Game::render()
{
    SDL_RenderClear(renderer);
    //AddStuffToRender
    SDL_RenderPresent(renderer);
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
        case SDL_QUIT:
            isRunning = false;
            break;
        
        default:
            break;
    }
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleaned" << std::endl;
}

bool Game::running()
{
    return isRunning;
}








