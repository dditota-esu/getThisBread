#include "CardSTUB.h"

Suit suit;
int rank;

Card::Card(int rank, Suit suit) {
	s = suit;
	r = rank;
	selected = false;
	faceUp = false;
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