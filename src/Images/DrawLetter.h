/*
 * DrawLetter.h
 *
 *  Created on: 6 mar 2018
 *      Author: hunter
 */

#ifndef DRAWLETTER_H_
#define DRAWLETTER_H_

#include <SDL2/SDL_ttf.h>

class DrawLetter : public DrawItem
{
	/*!
	 * \brief SDL texture for letter.
	 */
	SDL_Texture* Message = NULL;
	SDL_Surface* surfaceMessage;
	/*!
	 * \brief The actual letter that will be displayed.
	 */
	char letter;
};

#endif /* DRAWLETTER_H_ */
