#if !defined CARDAREAVIEW_H
#define CARDAREAVIEW_h

#include"CardView.h"
#include"ICardList.h"
#include"IListOfLists.h"
#include"Card.h"

#include"typeinfo"
#include"Vector"


//Look into the inheritance issue regarding the CardView
class CardAreaView
{
		 private:
					//Positions of x and y subwindow given from program
					int xStart;
					int yStart;

					int xOffset;
					int yOffset;

					//Size of the card list
					int arraySize;
					HINSTANCE tv;

					//Array to hold the x and y coordinated of the card
					vector<int> xPositionValues;
					vector<int> yPositionValues;

					vector<CardView*> cardImage;

					//Use to pass the card rank and suit into CardView
					int cardRank;
					char cardSuit;



		 public:
					//This will construct the card area
					CardAreaView(int, int, int, int, ICardCollection*, HINSTANCE);

					//This will display the cards
					void cardViewDisplay();

					//Giving each card in the array a x and y value
					void cardPosition(int, ICardCollection*);

					//Returning the card x and y positions
					int getCardX_Potision(int);
					int getCardY_Position(int);

					void append(ICardCollection*);

};
#endif