// Group 1 - Stack Header File
// Latest push of this Skeleton Code
// November 4th, 2020
// Software Engineering Fall 2020
#if !defined STACK_H
#define STACK_H
#include "CardList.h"

class Stack;
class Stack : public CardList {
public:
	Stack();

// HEAD
	void push(ICard *card);
	void pop(ICard *card);
	void pushGroup(ICardList *cardList);
	void popGroup(ICardList *cardList);
	bool isEmpty(ICardList *cardList);
	bool isFull(ICardList *cardList);
//



	virtual ~Stack();
};

#endif
