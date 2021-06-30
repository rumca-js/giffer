/*
 * DrawLetter.cpp
 *
 *  Created on: 6 mar 2018
 *      Author: hunter
 */

#include "config.h"
#include "DrawLetter.h"


DrawLetter::DrawLetter(SDL_Renderer *ren, TTF_Font* Sans, char _letter) {
    char text[4];

    renderer = ren;

    text[0] = _letter;
    text[1] = '\0';

    letter= _letter;

    if (Sans != NULL) {
           SDL_Color White = {255, 0, 0};
          surfaceMessage = TTF_RenderText_Solid(Sans, &text[0], White);
          Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
    }
    else {
        printf("Could not open font");
    }
}

DrawLetter::close() {

    if (surfaceMessage != NULL) {
        SDL_FreeSurface(surfaceMessage);
        SDL_DestroyTexture(Message);
        surfaceMessage = NULL;
        Message = NULL;
    }
}

void DrawLetter::display(SDL_Rect * srcRect, SDL_Rect * destRect) {
    SDL_RenderCopy(renderer, Message, srcRect, destRect);
}
