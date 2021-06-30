/*!
This class allows to connect state with a draw item.

For example
STATE_STANDING : gif1.gif
STATE_MOVING_RIGHT : gif2.gif
...
*/

class DrawComplex : public DrawItem
{
	std::map<Uint32, DrawItem*> items;

	public:
		void setState(Uint32 aNewState);
		Uint32 getState();
};
