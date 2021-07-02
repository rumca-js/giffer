/*
 * InitScene.cpp
 *
 *  Created on: 11 mar 2018
 *      Author: hunter
 */

#include <iostream>
#include "IntroScene.h"
#include "../Images/DrawGif.h"
#include "../Images/DrawTexture.h"
#include "../Images/DrawLetter.h"
#include "../Images/DrawText.h"

#include "../config.h"

#define FONT_SIZE 50
#define FONT_NAME  "./data/fonts/freefont/FreeSans.ttf"


IntroScene::IntroScene(SDL_Renderer *ren, SDL_Window * window) {

    win = window;
    renderer = ren;

    my_timer_id = -1;

	Sans = TTF_OpenFont(FONT_NAME, FONT_SIZE);

    items.push_back(new DrawGif( std::string("./data/test.gif"), renderer));
    items.push_back(new DrawTexture( std::string("./data/meeting.bmp"), renderer));
    items.push_back(new DrawTexture( std::string("./data/meeting.jpg"), renderer));
	SDL_Color color = {255, 0, 0, 255};
    items.push_back(new DrawLetter( 'c', renderer, Sans, color));
    items.push_back(new DrawText( "test", renderer, Sans, color));

    config = &MainConfiguration::getConfig();
}

IntroScene::~IntroScene() {
    close();
}

void IntroScene::init() {
}

void IntroScene::close() {

    if (items.size() != 0) {
		for(unsigned int i=0; i<items.size(); i++)
		{
			delete items[i];
		}
        items.clear();
    }
}

int IntroScene::write() {
    int status = SCENE_EXIT;

    bool display = false;

    display = true;
    
    while (true) {
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

        SDL_RenderClear(renderer);

        /* We display after some considerable amount of time */
        if (display) {

            SDL_Rect texr;

			for(unsigned int i=0; i<items.size(); i++)
			{
				texr.x = i*100;
				texr.y = i*100;

				texr.h= config->getHeight();
				texr.w = config->getWidth();

				texr.h = items[i]->getHeight();
				texr.w = items[i]->getWidth();

				items[i]->update(33.3);
				items[i]->draw(NULL, &texr);
			}

            SDL_RenderPresent(renderer);

            // for 30 frames/s
            // 1 second = 1000msec
            //
            // 30 frames      = 1000
            // 1 frame diplay = x
            //
            // x = 1000/30 = 33.3333333(3)
            SDL_Delay(33.3);
        }
    }

    return status;
}


