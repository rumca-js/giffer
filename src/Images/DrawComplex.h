
class DrawComplex : public DrawItem
{
	std::map<Uint32, DrawItem*> items;

	public:
		void setState(Uint32 aNewState);
		Uint32 getState();
};
