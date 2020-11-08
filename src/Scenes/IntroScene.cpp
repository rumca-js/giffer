/*
 * InitScene.cpp
 *
 *  Created on: 11 mar 2018
 *      Author: hunter
 */

#include "IntroScene.h"

#include "../config.h"



Uint32 my_callbackfunc1(Uint32 interval, void *param) {
	static int counter = 0;

	counter ++;

    SDL_Event event;
    SDL_UserEvent userevent;

    /* In this example, our callback pushes an SDL_USEREVENT event
    into the queue, and causes our callback to be called again at the
    same interval: */

    userevent.type = SDL_USEREVENT;
    userevent.code = counter;
    userevent.data1 = NULL;
    userevent.data2 = NULL;

    event.type = SDL_USEREVENT;
    event.user = userevent;

    SDL_PushEvent(&event);
    return(interval);
}

IntroScene::IntroScene(SDL_Renderer *ren, SDL_Window * window) {

	win = window;
	renderer = ren;

	logo    = NULL;

	my_timer_id = -1;

	gif = GIF_LoadImage("./data/test.gif");

	config = &MainConfiguration::getConfig();
}

IntroScene::~IntroScene() {
	// TODO Auto-generated destructor stub
}

void IntroScene::init() {


    logo = IMG_LoadTexture(renderer, IMAGE_INTRO);
}

void IntroScene::close() {
	SDL_DestroyTexture(logo);
}

int IntroScene::write() {
	int status = SCENE_EXIT;

    my_timer_id = SDL_AddTimer(1000, my_callbackfunc1, 0);
    bool display = false;

	while (1) {

		SDL_Event e;
		if ( SDL_PollEvent(&e) ) {
			if (e.type == SDL_QUIT) {
				status = SCENE_EXIT;
				break;
			}
			else if (e.type == SDL_USEREVENT) {
				if (e.user.code == 2) {
					display = true;
				}
				else if (e.user.code == 7) {
					status = SceneInterface::SCENE_FINISHED;
					break;
				}
			}
		}

		//SDL_RenderClear(renderer);

		/* We display after some considerable amount of time */
		if (display) {

			//int w, h;
			//SDL_QueryTexture(logo, NULL, NULL, &w, &h);

			//float ratio = config->getHeight()/(float)h;
			//float margin = config->getWidth()/10;

			//SDL_Rect texr; texr.x = margin; texr.y = margin; texr.w = (int)(w*ratio-margin*2.0); texr.h = (int)(h*ratio-margin*2.0);

			static int frame = 0;

			frame++;
			if (frame > gif->num_frames)
				frame = 0;

{
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, gif->frames[frame]->surface);
    
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
    
    SDL_DestroyTexture(texture);
    SDL_Delay(gif->frames[frame]->delay);
}

			//SDL_RenderCopy(renderer, logo, NULL, &texr);
		}

		//SDL_RenderPresent(renderer);
	}

	SDL_RemoveTimer(my_timer_id);

	return status;
}


