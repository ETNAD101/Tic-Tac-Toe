#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "Entity.h"
class Message : 
	public Entity
{
public:
	Message(Vector2f p_pos, std::string p_text, TTF_Font* p_font, SDL_Renderer* p_renderer);
	void setMessage(std::string p_text);
private:
	std::string text;
	TTF_Font* font;
	SDL_Renderer* renderer;
};

