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
        TTF_Init();
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
            TTF_Font * font = TTF_OpenFont("arial.ttf", 25);
            SDL_Color color = { 255, 255, 255 };
            SDL_Surface * surface = TTF_RenderText_Solid(font, "Welcome to Prout Labs アニメ", color);
            SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);
            TexToRender.push_back(texture);
            
            std::cout << "Renderer Created" << std::endl;
        }

        isRunning = true;
    }
    else
    {
        isRunning = false;
    }

    TJAPARSER::TJAParserLib* ParserLib = new TJAPARSER::TJAParserLib();
    ParserLib->ParseTJAFile("C:\\DEV\\PARADOX.tja");
}

void Game::update()
{
    cnt++;
}

void Game::render()
{
    SDL_RenderClear(renderer);
    //AddStuffToRender
    for(auto& InTex : TexToRender)
    {
        int texW = 500;
        int texH = 500;
        std::cout << "here" << std::endl;
        SDL_QueryTexture(InTex, NULL, NULL, &texW, &texH);
        SDL_Rect dstrect = { 0, 0, texW, texH };
        SDL_RenderCopy(renderer, InTex, NULL, &dstrect);
    }
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
    
    TTF_Quit();
    SDL_Quit();
    std::cout << "Game Cleaned" << std::endl;
}

bool Game::running()
{
    return isRunning;
}








