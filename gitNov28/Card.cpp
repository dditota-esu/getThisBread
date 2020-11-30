#include "Card.h"

Suit suit;
int rank;

Card::Card(int rank, Suit suit) {
		 s = suit;
		 r = rank;
		 selected = false;

		 //Harris change to see the affect on the game
		 faceUp = true;
}

void Card::select() { selected = !selected; }
void Card::flip() { faceUp = !faceUp; }
Suit Card::getSuit() { return s; }
int Card::getRank() { return r; }
bool Card::isFaceUp() { return faceUp; }
bool Card::isSelected() { return selected; }
ICardView* Card::getCardView() {
		 ICardView* temp = 0;
		 return temp;
}
Card::~Card() {}

//Harris info--------------------
int Card::getCardListSize()
{
		 return 1;
}

//Issue faceUp should be passed into the constructor that way when it is displayed it is easier instead of using the flip function 