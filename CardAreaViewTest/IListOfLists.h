#if !defined(ILISTOFLISTS_H)
#define ILISTOFLISTS_H

#include "ICardCollection.h"

class ICardList;
class ICard;

class IListOfLists : public ICardCollection
{
public:
	virtual ICardList* getFirstList() = 0;
	virtual ICardList* getNextList() = 0;
	virtual ICardList* getLastList() = 0;
	virtual ICardList* getListAtIndex(int index) = 0;
	// Hof: I'm not sure what the following two methods are supposed to do.
	virtual int getListIndex(ICardList*) = 0;
	virtual int getCardIndex(int listIndex, ICard*) = 0;
	virtual ~IListOfLists() {}
};

#endif