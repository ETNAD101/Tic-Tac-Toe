#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <cmath>
#include <Vector2f.h>


class Entity
{
public:
    Entity(Vector2f p_pos, int p_w, int p_h, SDL_Texture* p_tex);
    Vector2f& getPos();
    SDL_Texture* getTex();
    void setTex(SDL_Texture* p_tex);
    SDL_Rect getCurrentFrame();
    void setCurrentFrame(SDL_Rect p_rect);
    void setX(float p_x);
    void setY(float p_y);
    void setPos(Vector2f p_pos);
private:
    Vector2f pos;
    SDL_Rect currentFrame;
    SDL_Texture* tex;
};