
//
// vector<Items> items;
// items.push_back(new GifItem("../data/test.gif"));
// items.push_back(new JpegItem("../data/test.jpeg"));
//
// draw()
// {
//    for(int i=0;i<items.size();i++)
//    	items[i]->update(time());
//    	items[i]->draw();
// }
//

#include <string>
#include <SDL2/SDL.h>

class DrawItem
{
	//DrawItem(std::string path, SDL_Renderer * aRenderer);
protected:
	bool initialized;
	SDL_Renderer * renderer;
	Uint16 width, height;
public:
    DrawItem();
    virtual ~DrawItem();
	virtual void update(Uint32 time) = 0;
	virtual void draw(SDL_Rect * SrcR=NULL, SDL_Rect * DestR=NULL) = 0;
	virtual void close();
	virtual Uint16 getWidth() = 0;
	virtual Uint16 getHeight() = 0;
};
