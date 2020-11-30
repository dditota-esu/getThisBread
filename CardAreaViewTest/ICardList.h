#pragma once
#if !defined(ICARDLIST_H)
#define ICARDLIST_H

#include "ICardCollection.h"
#include "CardList.h"
class ICard;
// Any class that realizes interface ICardList, MUST override the pure virtual functions declared here.
// ICardList is meant to be a read only interface, shouldn't be used to alter the game
// ICardList must also implement methods declared from ICardCollection. (Currently not defined)

class ICardList : ICardCollection
{
public:
	virtual ICard* getFirst() = 0;
	virtual ICard* getNext() = 0;
	virtual ICard* getLast() = 0;
	virtual ICard* getAt(int) = 0;
	virtual bool isEmpty() = 0;
	virtual ~ICardList() {}
};

#endif