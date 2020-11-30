#include"CardAreaView.h"
#include"CardView.h"
//Variables

CardAreaView::CardAreaView(int x, int y, int xExtent, int yExtent, IListOfLists* list2d, CardList* list1d)
{
	numCards = 7;
	list = list1d;
	x_offset = (xExtent - CardWidth) / numCards;
	y_offset = (yExtent - CardHeight) / numCards;
}

void CardAreaView::displayArea(HDC* DeviceContext) 
{
	int x_off = 0;
	int y_off = 0;
	for (int i = 0; i < numCards; i++)
	{
		if (i == 0)
		{
			CardView* crd = new CardView(list->getFirst());
			crd->display(0, 0, DeviceContext);
		}
		else
		{
			CardView* crd = new CardView(list->getNext());
			crd->display(x_off = x_off + x_offset, y_off = y_off + y_offset, DeviceContext);
		}
	}
}
/*
CardIdentity* CardAreaView::click(int in_x, int in_y)
{
	//CardIdentity* identity;
	//identity->cardCollection = ;
	//identity->cardList = ;
	//identity->cardIndex = ;

	//if (faceUp && selected) { // showing card face, selected
	//	isSelected = false;
	//}
	//else if (isFaceUp && !isSelected) { // showing card face, not selected
	//	isFaceUp = false;
	//}
	//else if (!isFaceUp && !isSelected) { // showing card back, not selected
	//	isSelected = true;
	//}
	//else { // not showing card
	//	isFaceUp = true;
	//}

	return identity;
}*/