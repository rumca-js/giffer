
#include <iostream>
#include "DrawGif.h"


DrawGif::DrawGif(std::string path, SDL_Renderer * aRenderer)
{
    gif = GIF_LoadImage(path.c_str() );
    current_frame = 0;

    renderer = aRenderer;

    for(int frame=0;frame<gif->num_frames;frame++)
    {
        textures.push_back(SDL_CreateTextureFromSurface(renderer, gif->frames[frame]->surface));
    }
}

DrawGif::~DrawGif()
{
    close();
}

void DrawGif::update(Uint32 msec)
{
    ////gif->frames[i]->delay
    current_frame++;
    if (current_frame >= gif->num_frames)
        current_frame = 0;
}

void DrawGif::draw(SDL_Rect * SrcR, SDL_Rect * DestR)
{
    SDL_Texture* texture = textures[current_frame];
    SDL_RenderCopy(renderer, texture, SrcR, DestR);
}

void DrawGif::close()
{
    if (gif != NULL)
    {
        std::cout<< "Closing"<<std::endl;
        for(int frame=0;frame<gif->num_frames;frame++)
        {
            SDL_DestroyTexture(textures[frame]);
        }
        GIF_FreeImage(gif);

        gif = NULL;
    }
}

Uint16 DrawGif::getWidth()
{
    //return 3;
    return gif->width;
}

Uint16 DrawGif::getHeight()
{
    //return 3;
    return gif->height;
}
