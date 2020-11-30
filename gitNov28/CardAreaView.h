#if !defined CARDAREAVIEW_H
#define CARDAREAVIEW_h

#include"CardView.h"
#include"ICardList.h"
#include"IListOfLists.h"
#include"Card.h"
#include "RowOfStacks.h"
#include"typeinfo"
#include"Vector"

#define CardWidth 72
#define CardHeight 100

class CardIdentity
{
public:
	ICardCollection* cardCollection;
	ICardList* cardList;
	int cardIndex;
};


//Look into the inheritance issue regarding the CardView
class CardAreaView
{
		 private:
					//Positions of x and y subwindow given from program
					int xStart;
					int yStart;

					//Size of the card list
					int arraySize;

					//Use to pass the card rank and suit into CardView
					int cardRank;
					char cardSuit;


		 public:
					//This will construct the card area
					CardAreaView(int, int, int, int, ICardCollection*, ICard*);

					//This will display the cards
					void cardViewDisplay(HDC*);

					//Giving each card in the array a x and y value
					void cardPosition(int, ICardCollection*);

					//Returning the card x and y positions
					int getCardX_Potision(int);
					int getCardY_Position(int);

					CardIdentity* click(int x, int y);

		protected:				//This allows for the subclass to interact with the parent class attributes
					//ICardCollection object
					ICardCollection* cardObject;
					int xExtentCard;
					int yExtentCard;

					int xOffset;
					int yOffset;


};
#endif