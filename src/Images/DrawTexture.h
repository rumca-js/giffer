
#include "DrawItem.h"

class DrawTexture : public DrawItem
{
	SDL_Texture * texture;

    public:
        DrawTexture(std::string path, SDL_Renderer * aRenderer);
        void update(Uint32 time);
        void draw(SDL_Rect * SrcR, SDL_Rect * DestR);
        void close();
        Uint16 getWidth();
        Uint16 getHeight();
};
