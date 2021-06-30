/*
 * InitScene.cpp
 *
 *  Created on: 11 mar 2018
 *      Author: hunter
 */

#include <iostream>
#include "IntroScene.h"

#include "../config.h"


IntroScene::IntroScene(SDL_Renderer *ren, SDL_Window * window) {

    win = window;
    renderer = ren;

    my_timer_id = -1;

    item = new DrawGif( std::string("./data/test.gif"), renderer);

    config = &MainConfiguration::getConfig();
}

IntroScene::~IntroScene() {
    close();
}

void IntroScene::init() {
}

void IntroScene::close() {

    if (item != NULL) {
        delete item;
        item = NULL;
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
            texr.x = 0;
            texr.y = 0;
            texr.h= config->getHeight();
            texr.w = config->getWidth();
            texr.h = item->getHeight();
            texr.w = item->getWidth();

            item->update(33.3);
            item->draw(NULL, &texr);

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


