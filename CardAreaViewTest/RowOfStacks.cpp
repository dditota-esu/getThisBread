#include "RowOfStacks.h"
#include "Stack.h"
#include "Card.h"

RowOfStacks::RowOfStacks() {
	// constructor
}

RowOfStacks::~RowOfStacks() {
	//destructor
}

ICardList* RowOfStacks::getFirstList() {
	//first
	if (stackList.size() < 1) return 0;
	currentList = 0;
	return stackList[0];
}
ICardList* RowOfStacks::getNextList() {
	//next
	currentList++;
	if (currentList > stackList.size() - 1) return 0;
	return stackList[currentList];
}
ICardList* RowOfStacks::getLastList() {
	//last
	if (stackList.size() == 0) return 0;
	return stackList[stackList.size() - 1];
}
ICardList* RowOfStacks::getListAtIndex(int index) {
	//index
	if (index < 0 || index > stackList.size() - 1 || stackList.size() == 0) return 0;
	return stackList[index];
}

int RowOfStacks::getListIndex(ICardList* cardList) {
	//list index
	return 0;
}
int RowOfStacks::getCardIndex(int listIndex, ICard* card) {
	//card index
	return 0;
}

void RowOfStacks::addToEnd(Stack* stack) {
	//end
	stackList.push_back(stack);
}
void RowOfStacks::addToBeginning(Stack* stack) {
	//beginning
	stackList.insert(stackList.begin(), stack);
}
void RowOfStacks::addAtIndex(Stack* stack, int index) {
	//index
	stackList.insert(stackList.begin() + index, stack);
}

Stack* RowOfStacks::removeAtEnd() {
	if (stackList.size() == 0) return 0;
	Stack* stack = stackList[stackList.size() - 1];
	stackList.erase(stackList.begin() + stackList.size() - 1);
	return stack;
}
Stack* RowOfStacks::removeAtBeginning() {
	if (stackList.size() == 0) return 0;
	Stack* stack = stackList[0];
	stackList.erase(stackList.begin());
	return stack;
}
Stack* RowOfStacks::removeAtIndex(int index) {
	if (stackList.size() == 0) return 0;
	Stack* stack = stackList[index];
	stackList.erase(stackList.begin() + index);
	return stack;
}

void RowOfStacks::readFromFile() {
	//read
}
void RowOfStacks::writeToFile() {
	//write
}
