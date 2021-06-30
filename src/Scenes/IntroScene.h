/*
 * IntroScene.h
 *
 *  Created on: 11 mar 2018
 *      Author: hunter
 */

#ifndef INTROSCENE_H_
#define INTROSCENE_H_

#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <vector>

#include "../SceneInterface.h"
#include "../MainConfiguration.h"

#include "../Images/DrawItem.h"

#define TEXT_LOGO "SLAVE STUDIO 1"

class IntroScene : public SceneInterface {
	/*!
	 * \brief SDL Renderer pointer.
	 */
	SDL_Renderer* renderer;
	/*!
	 * \brief SDL window pointer.
	 */
	SDL_Window* win;
	/*!
	 * \brief Configuration instance pointer.
	 */
	MainConfiguration * config;
	/*!
	 * Timer for displaying logo.
	 */
	SDL_TimerID my_timer_id;
    /*!
     * Item to draw
     */
	std::vector<DrawItem *> items;

	TTF_Font* Sans = NULL;

public:
	/*!
	 * \brief Constructor.
	 */
	IntroScene(SDL_Renderer *ren, SDL_Window * window);
	/*!
	 * \brief Destructor.
	 */
	virtual ~IntroScene();
	/*!
	 * \brief Scene init function.
	 */
	void init();
	/*!
	 * \brief Scene write function.
	 */
	int write();
	/*!
	 * \brief Scene close function.
	 */
	void close();

};

#endif /* INTROSCENE_H_ */
