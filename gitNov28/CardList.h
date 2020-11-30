#pragma once
#if !defined(CARDLIST_H)
#define CARDLIST_H
#include <string>
#include <vector>
#include "ICardList.h"
class ICard;
#include "Card.h"

class CardList : public ICardList 
{
private:
		 std::vector<Card*> theCards;
		 int currentCard;

public:

		//I do not think that these methods should have any virtual functions given that they are the base functions. The shoudl not get overwritten
		 CardList();
		 void readFile(std::string = "");
		 void writeFile(std::string = "");

		 // accessor methods
		 ICard* getFirst();
		 ICard* getNext();
		 ICard* getLast();
		 ICard* getAt(int);
		 bool isEmpty();

		 //Harris info--------------------
		 int getCardListSize();
		 //-------------------------------

		 // mutator methods
		 void addToEnd(Card*);
		 void addToBeginning(Card*);
		 void addAtIndex(Card*, int index);

		 Card* removeAtEnd();
		 Card* removeAtBeginning();
		 Card* removeAtIndex(int index);

		 // since CardList holds all the cards (no pun intended), you have to provide ALL the 
		 // methods that manipulate a CardList or any of its subclasses.
		 void shuffle();

		 void sortBySuit();
		 void sortByRank();

		 ~CardList();

		 //CardList();
		 //virtual void readFile(std::string = "");
		 //virtual void writeFile(std::string = "");

		 //// accessor methods
		 //virtual ICard* getFirst();
		 //virtual ICard* getNext();
		 //virtual ICard* getLast();
		 //virtual ICard* getAt(int);
		 //virtual bool isEmpty();

		 ////Harris info--------------------
		 //virtual int getCardListSize();
		 ////-------------------------------

		 //// mutator methods
		 //virtual void addToEnd(Card*);
		 //virtual void addToBeginning(Card*);
		 //virtual void addAtIndex(Card*, int index);

		 //virtual Card* removeAtEnd();
		 //virtual Card* removeAtBeginning();
		 //virtual Card* removeAtIndex(int index);

		 //// since CardList holds all the cards (no pun intended), you have to provide ALL the 
		 //// methods that manipulate a CardList or any of its subclasses.
		 //virtual void shuffle();

		 //virtual void sortBySuit();
		 //virtual void sortByRank();

		 //~CardList();
};

#endif

