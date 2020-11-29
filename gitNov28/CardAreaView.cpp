#include"CardAreaView.h"

//Creates the Card Area View by getting the basic information 
CardAreaView::CardAreaView(int xP, int yP, int xExtent, int yExtent, ICardCollection* cardType, HINSTANCE hInst)
{
					//Get the position of the subwindow 
					xStart = xP;
					yStart = yP;

					//Inputting the size of the cardlist 
					arraySize = cardType->getCardListSize();

					//Still have to get a better idea of this but assuming it is the different in spacing
					xOffset = (xExtent - 72) / arraySize;
					yOffset = (yExtent - 100) / arraySize;

					//Inputting the hinstance into a better followed variable TV!
					tv = hInst;

					cardPosition(arraySize, cardType);

					//Call CardView to set up the cards image
}

//This function will determine the position of the cards in the list
void CardAreaView::cardPosition(int size, ICardCollection* cardType)
{
		 if (xStart > yStart)
		 {
					//Horizontal
					for (int i = 0; i < arraySize; i++)
					{
							 if (i == 0)
							 {
										xPositionValues[0] = xStart;
										yPositionValues[0] = yStart;
							 }
							 xPositionValues[i] = xOffset + 1;
							 yPositionValues[i] = yOffset;
					}

		 }
		 else if (yStart > xStart)
		 {
					//Verical
					for (int i = 0; i < arraySize; i++)
					{
							 if (i == 0)
							 {
										xPositionValues[0] = xStart;
										yPositionValues[0] = yStart;
							 }
							 yPositionValues[i] = yOffset + 1;
							 xPositionValues[i] = xOffset;
					}
		 }
		 else
		 {
					//Must find a solution in case you have both x and y the same values
					//ex. 100 x 100
					cout << "ERROR" << endl;
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


//void CardAreaView::append(ICardCollection* card)
//{
//		 for (int i = 0; i < arraySize; i++)
//		 {
//					cardImage[i] = new CardView(card->getSuit(), card->getRank());
//		 }
//}

