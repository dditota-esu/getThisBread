#pragma once
#if !defined(CARDLIST_H)
#define CARDLIST_H

#include <string>
#include <vector>
#include "ICardList.h"
//#include "ICard.h";
class ICard;
//class Card;
#include "Card.h"

class CardList : public ICardList {
private:
		 std::vector<Card*> theCards;
		 int currentCard;
public:
		 CardList();
		 virtual void readFile(std::string = "");
		 virtual void writeFile(std::string = "");

		 // accessor methods
		 virtual ICard* getFirst();
		 virtual ICard* getNext();
		 virtual ICard* getLast();
		 virtual ICard* getAt(int);
		 virtual bool isEmpty();

		 //Harris info--------------------
		 virtual int getCardListSize();
		 //-------------------------------

		 // mutator methods
		 virtual void addToEnd(Card*);
		 virtual void addToBeginning(Card*);
		 virtual void addAtIndex(Card*, int index);

		 virtual Card* removeAtEnd();
		 virtual Card* removeAtBeginning();
		 virtual Card* removeAtIndex(int index);

		 // since CardList holds all the cards (no pun intended), you have to provide ALL the 
		 // methods that manipulate a CardList or any of its subclasses.
		 virtual void shuffle();

		 virtual void sortBySuit();
		 virtual void sortByRank();

		 ~CardList();
};

#endif
