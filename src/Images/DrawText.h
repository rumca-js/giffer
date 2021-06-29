/*
 * DrawLetter.h
 *
 *  Created on: 6 mar 2018
 *      Author: hunter
 */

#ifndef DRAWTEXT_H_
#define DRAWTEXT_H_

#include <SDL2/SDL_ttf.h>

class DrawText : public DrawItem
{
	/*!
	 * \brief SDL texture for letter.
	 */
	SDL_Texture* Message = NULL;
	SDL_Surface* surfaceMessage;
	/*!
	 * \brief The actual letter that will be displayed.
	 */
	std::string text;
};

#endif /* DRAWTEXT_H_ */
