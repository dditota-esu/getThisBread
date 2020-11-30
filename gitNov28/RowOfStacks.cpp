/*
* made by Sean Crowley: team A
* discord username: mr_crowley#8084
*/
#include "RowOfStacks.h"
int RowOfStacks::getCardListSize() { return row.size(); }

ICardList* RowOfStacks::getFirstList() {
    //add a check if row is empty
        //if it is throw an error? handle it above?
    currIndex = 0;
    ICardList* temp = (ICardList*)((CardList*)row.front());
    //row.erase(row.begin());
    return temp;
}

bool RowOfStacks::isFirst() {
    //idk what this is supposed to do?
    return currIndex == 0;
}

ICardList* RowOfStacks::getLastList() {
    ICardList* temp = (ICardList*)row.back();
    row.pop_back();
    currIndex = row.size() - 1;
    return temp;
}

int RowOfStacks::getListIndex(ICardList* t)
{
    int ans = -1;
    for (int i = 0; i < getCardListSize(); i++) {
        if (getListAtIndex(i) == t) {
            ans = i;
        }
    }
    return ans;
}

int RowOfStacks::getCardIndex(int listIndex, ICard*)
{
    return 0;
}

bool RowOfStacks::isLast() {
    return (currIndex == getCardListSize() - 1);
}

ICardList* RowOfStacks::getNextList() {
    //add check for if at end of list
    ICardList* temp = (ICardList*)row.at(currIndex);
    currIndex++;
    return temp;
}

ICardList* RowOfStacks::getPrevious() {
    //check if at start of list
    ICardList* temp = (ICardList*)row.at(currIndex);
    currIndex--;
    return temp;
}

ICardList* RowOfStacks::getListAtIndex(int i) {
    ICardList* temp = row.at(i);
    return temp;
}

void RowOfStacks::add(CardList* s) { row.push_back(s); }

void RowOfStacks::add(CardList* s, int i) {}

CardList* RowOfStacks::remove(int i) {
    CardList* temp = row.at(i);
    row.erase(row.begin() + i);
    return temp;
}
/*
Stack* RowOfStacks::pop(){
    Stack* temp=row.at(row.size()-1);
    row.erase(row.begin()+(row.size()-1));
    return temp;
}
*/

void RowOfStacks::write() {
    //will write each stack in row based on stacks write (which is based on CardLists write)
    //each stack in row will be seperated soemhow
        //different file for each stack all included in a folder named for this rowOfStacks?
}

void RowOfStacks::read(std::string filename) {
    //based on structure of write()
}


RowOfStacks::RowOfStacks() { currIndex = 0; }
/*
RowOfStacks::~RowOfStacks(){
    delete &row;
}*/