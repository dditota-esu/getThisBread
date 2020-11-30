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

					///Putting the ICardCollection into an object to use in the program
					cardObject = cardType;
}

void CardAreaView::cardViewDisplay(HDC* DeviceContext)
{
	int x_off = 0;
	int y_off = 0;
	for (int i = 0; i < arraySize; i++)
	{
		if (i == 0)
		{
			CardView* crd = new CardView(cardObject->getFirst());
			crd->display(0, 0, DeviceContext);
		}
		else
		{
			CardView* crd = new CardView(cardObject->getNext());
			crd->display(x_off = x_off + xOffset, y_off = y_off + yOffset, DeviceContext);

		}
	}
}

//This function will return the card x-value position of the card in the list
//This requires the card position in the list
int CardAreaView::getCardX_Potision(int cardListIndex)
{
		 //Since our array starts from 0 we need to stubtract the array size by 1
		 int cardIndex = cardListIndex - 1;

		 return xPositionValues[cardIndex];
}


//This function will return the card y-value position of the card in the list
//This requires the card position in the list
int CardAreaView::getCardY_Position(int cardListIndex)
{
		 //Since our array starts from 0 we need to stubtract the array size by 1
		 int cardIndex = cardListIndex - 1;

		 return yPositionValues[cardIndex];
}


CardIdentity* CardAreaView::click(int in_x, int in_y)
{
	CardIdentity* identity = new CardIdentity();
	identity->cardCollection = cardObject;


	//Determine the xoffset anf y offset values from the click input parameters.
	//then use a for loop to move through card collection list - backwards from front
	//have if - else statements in the loop to determine if a card lies within the parameters inputted
	//and if it does return i + 1 which is the card index.


	return identity;
}

