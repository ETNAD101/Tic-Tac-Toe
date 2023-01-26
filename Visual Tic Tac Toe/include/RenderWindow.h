#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>
#include "entity.h"


class RenderWindow
{
public:
    RenderWindow(const char* p_title, int p_w, int p_h);
    SDL_Texture* loadTexture(const char* p_filePath);
    TTF_Font* loadFont(const char* p_fontPath, int p_size);
    void cleanUp();
    void clear();
    void render(Entity& p_e);
    void display();
    SDL_Renderer* getRenderer();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};
