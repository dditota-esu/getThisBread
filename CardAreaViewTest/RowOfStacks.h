//RowOfStacks header file
#if !defined ROWOFSTACKS_H
#define ROWOFSTACKS_H
#include "IListOfLists.h"
#include <vector>

class Stack;

class RowOfStacks : public IListOfLists
{
private:
	std::vector<Stack*> stackList;
	int currentList;
public:
	RowOfStacks();
	~RowOfStacks();

	// must implement all the methods in IListOfLists
	virtual ICardList* getFirstList();
	virtual ICardList* getNextList();
	virtual ICardList* getLastList();
	virtual ICardList* getListAtIndex(int index);
	// Hof: I'm not sure what the following two methods are supposed to do.
	virtual int getListIndex(ICardList*);
	virtual int getCardIndex(int listIndex, ICard*);

	// mutator methods
	virtual void addToEnd(Stack*);
	virtual void addToBeginning(Stack*);
	virtual void addAtIndex(Stack*, int index);

	virtual Stack* removeAtEnd();
	virtual Stack* removeAtBeginning();
	virtual Stack* removeAtIndex(int index);

	void readFromFile(); // writes internal data to file
	void writeToFile(); // readss from file into internal data (attribs)
};

#endif