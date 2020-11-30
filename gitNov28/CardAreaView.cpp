#include"CardAreaView.h"

//Creates the Card Area View by getting the basic information 
CardAreaView::CardAreaView(int xP, int yP, int xExtent, int yExtent, ICardCollection* cardType, ICard * cardUno)
{
					//Get the position of the subwindow 
					xStart = xP;
					yStart = yP;

					//Inputting the size of the cardlist 
					arraySize = cardType->getCardListSize();

					//Still have to get a better idea of this but assuming it is the different in spacing
				    xOffset = (xExtent - CardWidth) / arraySize;
					yOffset = (yExtent - CardHeight) / arraySize;

					if (xOffset == yOffset)
					{
						xOffset = 0;
						yOffset = 0;
					}
					else if(xOffset == 0)
					{
						yOffset = 35;
					}
					else if (yOffset == 0)
					{
						xOffset = 35;
					}

					xExtentCard = xExtent;
					yExtentCard = yExtent;

					///Putting the ICardCollection into an object to use in the program
					cardObject = cardType;
}

void CardAreaView::cardViewDisplay(HDC* DeviceContext)
{
	int x_off = 0;
	int y_off = 0;
	if (dynamic_cast<ICardList*>(cardObject)) {//if the object is 1d
		CardList* list = (CardList*)cardObject;
		for (int i = 0; i < arraySize; i++)
		{
			if (i == 0)
			{
				CardView* crd = new CardView(list->getFirst());
				crd->display(xStart, yStart, DeviceContext);
			}
			else
			{
				CardView* crd = new CardView(list->getNext());
				crd->display(xStart + x_off, yStart + y_off, DeviceContext);

			}
			x_off = x_off + xOffset;
			y_off = y_off + yOffset;
		}
	}
	else {//if 2d
		RowOfStacks* temp = (RowOfStacks*)cardObject;
		for (int i = 0; i < temp->getCardListSize(); i++) {
			ICardList* cl = temp->getListAtIndex(i);
			for (int j = 0; j < cl->getCardListSize(); j++) {
				CardView* crd = new CardView(cl->getAt(j));
				crd->display(xStart + x_off, yStart + y_off, DeviceContext);
				y_off += yOffset;
			}
			x_off += CardWidth+10;
			y_off = 0;
		}
	}
}

//This function will return the card x-value position of the card in the list
//This requires the card position in the list
//int CardAreaView::getCardX_Potision(int cardListIndex)
//{
//		 Since our array starts from 0 we need to stubtract the array size by 1
//		 int cardIndex = cardListIndex - 1;
//
//		 return xPositionValues[cardIndex];
//}
//
//
//This function will return the card y-value position of the card in the list
//This requires the card position in the list
//int CardAreaView::getCardY_Position(int cardListIndex)
//{
//		 Since our array starts from 0 we need to stubtract the array size by 1
//		 int cardIndex = cardListIndex - 1;
//
//		 return yPositionValues[cardIndex];
//}


CardIdentity* CardAreaView::click(int in_x, int in_y)
{
	CardIdentity* identity = new CardIdentity();
	identity->cardCollection = cardObject;
	if (dynamic_cast<ICardList*>(cardObject)) { // 1d
		int tempIndex = -1;

		if (yExtentCard > xExtentCard) {//horizontally formatted
			int tempY = yOffset * (arraySize - 1);
			tempIndex = arraySize - 1;
			while (in_y < tempY) {
				tempY -= yOffset;
				tempIndex--;
			}
		}
		else {//virtically formatted
			int tempX = xOffset * (arraySize - 1);
			tempIndex = arraySize - 1;
			while (in_x < tempX) {
				tempX -= xOffset;
				tempIndex--;
			}
		}
		identity->cardIndex = tempIndex;
	}
	else { //2d
		//virtical printing first, y = card index, x=list index
		RowOfStacks* tempRows = (RowOfStacks*)cardObject;
		int listIndex = -1;
		int tempX = (CardWidth + 10) * (arraySize - 1);
		listIndex = arraySize - 1;
		while (in_x < tempX) {
			tempX -= xOffset;
			listIndex--;
		}
		//now find the card index
		ICardList* tempList = tempRows->getListAtIndex(listIndex);//get the list the Y coord gives us
		identity->cardList = tempList;//set identites cardlist for this list
		int cardI = -1;
		
		int tempY = yOffset * (tempList->getCardListSize() - 1);
		cardI = tempList->getCardListSize() - 1;
		while (in_y < tempY) {
			tempY -= yOffset;
			cardI--;
		}
		
		identity->cardIndex = cardI;
		std::cout << "cardList index: " << listIndex << "\nCard index: " << cardI << std::endl;
	}
	/*
	int xOffOne = xExtentCard;
	int xOffTwo = xOffset;

	int yOffOne = yExtentCard;
	int yOffTwo = yOffOne - yOffset;

	for (int i = (arraySize - 1); i >= 0; i--)
	{
		if (in_x >= xOffTwo && in_x <= xOffOne)
		{
			if (in_y >= yOffTwo && in_y <= yOffOne)
			{
				identity->cardIndex = i + 1;
			}
		}
	}
	*/
	//Determine the xoffset anf y offset values from the click input parameters.
	//then use a for loop to move through card collection list - backwards from front
	//have if - else statements in the loop to determine if a card lies within the parameters inputted
	//and if it does return i + 1 which is the card index.
	return identity;
}

