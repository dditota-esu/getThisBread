#ifndef ICARD_H
#define ICARD_H

class ICardView;

enum Suit {
	Spades,
	Hearts,
	Clubs,
	Diamonds
};

class ICard
{
public:
	~ICard() {};

	virtual Suit getSuit() = 0;
	virtual int getRank() = 0;
	virtual bool isFaceUp() = 0;
	virtual bool isSelected() = 0;
	virtual ICardView* getCardView() = 0;
};
#endif