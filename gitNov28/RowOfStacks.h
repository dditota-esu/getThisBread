/*
* made by Sean Crowley: team A
* discord username: mr_crowley#8084
*/
#ifndef ROWOFSTACKS_H
#define ROWOFSTACKS_H
#include "IListOfLists.h"
#include "CardList.h"
#include <vector>

class RowOfStacks : public IListOfLists {
private:
    std::vector<CardList*> row;
    int currIndex;
public:
    //ICardList* listIterator(); // this is in IListofLists, but not clear what it is supposed to do


    // Hof: I'm not sure what the following two methods are supposed to do.
    virtual int getListIndex(ICardList*);
    virtual int getCardIndex(int listIndex, ICard*);

    //Harris info--------------------

    int getCardListSize();
    ICardList* getFirstList();
    bool isFirst();
    ICardList* getLastList();
    bool isLast();
    ICardList* getNextList();
    ICardList* getPrevious();
    //above inheritted
    //there are return type issues from above
    void add(CardList*);
    void add(CardList*, int);
    CardList* remove(int);
    void read(std::string);
    void write();
    RowOfStacks();
    //~RowOfStacks(){};
    ICardList* getListAtIndex(int);
};

#endif