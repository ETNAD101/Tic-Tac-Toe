#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <cmath>
#include <Vector2f.h>
#include <entity.h>

Entity::Entity(Vector2f p_pos, int p_w, int p_h, SDL_Texture* p_tex)
    :pos(p_pos), tex(p_tex)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = p_w;
    currentFrame.h = p_h;
}

Vector2f& Entity::getPos()
{
    return pos;
}

SDL_Texture* Entity::getTex()
{
    return tex;
}

void Entity::setTex(SDL_Texture* p_tex)
{
    tex = p_tex;
}

SDL_Rect Entity::getCurrentFrame()
{
    return currentFrame;
}

void Entity::setCurrentFrame(SDL_Rect p_rect)
{
    currentFrame = p_rect;
}

void Entity::setX(float p_x)
{
    pos.x = p_x;
}

void Entity::setY(float p_y)
{
    pos.y = p_y;
}

void Entity::setPos(Vector2f p_pos)
{
    pos = p_pos;
}