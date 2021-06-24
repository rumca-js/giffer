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

    gif = GIF_LoadImage("./data/test.gif");

    config = &MainConfiguration::getConfig();
}

IntroScene::~IntroScene() {
    // TODO Auto-generated destructor stub
}

void IntroScene::init() {
    for(int frame=0;frame<gif->num_frames;frame++)
    {
        textures.push_back(SDL_CreateTextureFromSurface(renderer, gif->frames[frame]->surface));
    }
}

void IntroScene::close() {
    for(int frame=0;frame<gif->num_frames;frame++)
    {
        SDL_DestroyTexture(textures[frame]);
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
            texr.h = gif->height;
            texr.w = gif->width;

            static int frame = 0;

            frame++;
            if (frame >= gif->num_frames)
            {
                frame = 0;
                break;
            }

            SDL_Texture* texture = textures[frame];
            
            SDL_RenderCopy(renderer, texture, NULL, &texr);
            SDL_RenderPresent(renderer);
            
            
            SDL_Delay(gif->frames[frame]->delay);
        }
    }

    return status;
}


