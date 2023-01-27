#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "Button.h"
#include "Vector2f.h"

Button::Button(Vector2f p_pos, std::string p_text, TTF_Font* p_font, SDL_Renderer* p_renderer, bool* p_mouseDown)
	:Message(p_pos, p_text, p_font, p_renderer)
{
	mouseDown = p_mouseDown;
}

Button::Button(Vector2f p_pos, int p_w, int p_h, SDL_Texture* p_tex, SDL_Renderer* p_renderer, bool* p_mouseDown)
	:Message(p_pos, NULL, NULL, p_renderer)
{
	mouseDown = p_mouseDown;
	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;
	rect.w = p_w;
	rect.h = p_h;

	this->setCurrentFrame(rect);
	this->setTex(p_tex);
	
}

bool Button::pressed(int& p_mouseX, int& p_mouseY)
{
	if (mouseDown)
	{
		if ((p_mouseX > this->getPos().x) &&
			(p_mouseX < this->getPos().x + this->getCurrentFrame().w) &&
			(p_mouseY > this->getPos().y) &&
			(p_mouseY < this->getPos().y + this->getCurrentFrame().h)) 
		{
			return true;
		}
		return false;
	}
}