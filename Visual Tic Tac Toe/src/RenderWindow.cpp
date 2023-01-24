#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>
#include "renderWindow.h"

/**Constructor creates SDL window and Renderer objects**/
RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
    :window(NULL), renderer(NULL)
{
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);

    if (window == NULL)
        std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

    if (renderer == NULL)
        std::cout << "Renderer failed to init. Error: " << SDL_GetError() << std::endl;

    if (TTF_Init() != 0)
        std::cout << "TTF_init has failed, ERROR: " << SDL_GetError() << std::endl;
}

/**Creates SDL texture from an image**/
SDL_Texture* RenderWindow::loadTexture(const char* p_filePath)
{
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, p_filePath);

    if (texture == NULL)
        std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;

    return texture;
}

TTF_Font* RenderWindow::loadFont(const char* p_fontPath, int p_size) {
    TTF_Font* font = NULL;
    font = TTF_OpenFont(p_fontPath, p_size);

    if (font == NULL) {
        std::cout << "Failed to load font. Error: " << SDL_GetError() << std::endl;
    }
    return font;
}

/**Creates a texture from the given text and font**/
SDL_Texture* RenderWindow::createText(std::string p_text, TTF_Font* p_font) {
    SDL_Surface* surfaceText = TTF_RenderText_Solid(p_font, p_text.c_str(), { 0, 0, 0 });
    SDL_Texture* texture;
    texture = SDL_CreateTextureFromSurface(renderer, surfaceText);
    SDL_FreeSurface(surfaceText);
    return texture;
}

void RenderWindow::cleanUp()
{
    SDL_DestroyWindow(window);
}

/**Clears the screen/renderer and draws the background**/
void RenderWindow::clear()
{
    SDL_SetRenderDrawColor(renderer, 245, 245, 220, 255);
    SDL_RenderClear(renderer);
}

/**Draws an entity to the screen**/
void RenderWindow::render(Entity& p_e)
{
    SDL_Rect src;
    src.x = p_e.getCurrentFrame().x;
    src.y = p_e.getCurrentFrame().y;
    src.w = p_e.getCurrentFrame().w;
    src.h = p_e.getCurrentFrame().h;

    SDL_Rect dst;
    dst.x = p_e.getPos().x;
    dst.y = p_e.getPos().y;
    dst.w = p_e.getCurrentFrame().w;
    dst.h = p_e.getCurrentFrame().h;

    SDL_RenderCopy(renderer, p_e.getTex(), &src, &dst);
}

/**Renders the renderer**/
void RenderWindow::display()
{
    SDL_RenderPresent(renderer);
}