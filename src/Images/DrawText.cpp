/*
 * DrawLetter.cpp
 *
 *  Created on: 6 mar 2018
 *      Author: hunter
 */

#include "config.h"
#include "DrawText.h"


DrawText::DrawText(SDL_Renderer *ren, TTF_Font* Sans, std::string input_text) {

	renderer = ren;

	letter= _letter;

	text = input_text;

    if (Sans != NULL) {
   	    SDL_Color White = {255, 0, 0};
  	    surfaceMessage = TTF_RenderText_Solid(Sans, &text.c_str(), White);
  	    Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
    }
    else {
    	printf("Could not open font");
    }
}

DrawText::close() {

	if (surfaceMessage == NULL) {
		SDL_FreeSurface(surfaceMessage);
		SDL_DestroyTexture(Message);
        surfaceMessage = NULL;
        Message = NULL;
	}
}

void DrawText::display(SDL_Rect * srcRect, SDL_Rect * destRect) {
	SDL_RenderCopy(renderer, Message, srcRect, destRect);
}
