#ifndef CARD_H
#define CARD_H
#include "ICard.h"

class Card : public ICard {
private:
    Suit s;
    int r;
    bool faceUp;
    bool selected;
public:
    Card(int R, Suit S);
    ~Card();

	bool isFaceUp();
	bool isSelected();
    void select();
    void flip();

    //from ICard
	ICardView* getCardView();
    int getRank();
    Suit getSuit();
};

#endif