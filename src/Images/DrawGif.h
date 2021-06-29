#include <vector>
#include "SDL_gifwrap.h"
#include "DrawItem.h"

class DrawGif : public DrawItem
{
	Uint32 current_frame;
	GIF_Image* gif;
    std::vector<SDL_Texture*> textures;

    public:
        DrawGif(std::string path, SDL_Renderer * aRenderer);
        virtual ~DrawGif();
        void close();
        void draw(SDL_Rect*, SDL_Rect*);
        Uint16 getWidth();
        Uint16 getHeight();
        void update(Uint32);
};
