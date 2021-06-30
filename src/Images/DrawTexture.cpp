#include "DrawTexture.h"


DrawTexture::DrawTexture(std::string path, SDL_Renderer * aRenderer) {

	SDL_Surface * Loading_Surf = SDL_LoadBMP(path.c_str());
  	texture = SDL_CreateTextureFromSurface(renderer, Loading_Surf);
  	SDL_FreeSurface(Loading_Surf);

	renderer = aRenderer;
}

void DrawTexture::update(Uint32 time) {
}

void DrawTexture::draw(SDL_Rect * SrcR, SDL_Rect * DestR) {
	SDL_RenderCopy(renderer, texture, SrcR, DestR);
}

void DrawTexture::close() {
    if (texture == NULL)
    {
        SDL_DestroyTexture(texture);
        texture = NULL;
    }
}

Uint16 DrawTexture::getWidth() {
	return 100;
}

Uint16 DrawTexture::getHeight() {
	return 100;
}

