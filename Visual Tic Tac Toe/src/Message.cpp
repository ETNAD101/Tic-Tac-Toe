#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "Message.h"
#include "Entity.h"

Message::Message(Vector2f p_pos, std::string p_text, TTF_Font* p_font, SDL_Renderer* p_renderer)
	:Entity(p_pos, 0, 0, NULL), text(p_text), font(p_font), renderer(p_renderer)
{
	setMessage(text);
}

void Message::setMessage(std::string p_text)
{
	text = p_text;
	SDL_Surface* surfaceText = TTF_RenderUTF8_Solid(font, text.c_str(), { 0, 0, 0 });
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surfaceText);

	SDL_Rect message;
	message.x = 0;
	message.y = 0;
	message.w = surfaceText->w;
	message.h = surfaceText->h;

	this->setCurrentFrame(message);
	this->setTex(texture);
	SDL_FreeSurface(surfaceText);
}