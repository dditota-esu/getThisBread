#if !defined CARDAREAVIEW_H
#define CARDAREAVIEW_H
#include"ICardList.h"
#include"IListOfLists.h"
#include<windows.h>

#define CardWidth 72
#define CardHeight 100

class CardIdentity
{
public:
	ICardCollection* cardCollection;
	ICardList* cardList;
	int cardIndex;
};

class CardAreaView
{
private:
	int x_offset;
	int y_offset;
	CardList* list = new CardList();
	int numCards;
public:
	CardAreaView(int x, int y, int xExtent, int yExtent, IListOfLists* list2d, CardList* list1d);
	void displayArea(HDC* DeviceContext);
	//CardIdentity* click(int x, int y);
};
#endif

//This class creates CardView so --> CardView one = new CardAView();