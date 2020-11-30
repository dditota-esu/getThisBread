#pragma once
#if !defined ICARDCOLLECTION_H
#define ICARDCOLLECTION_H


//This is an interface class 
class ICard;
class ICardList;
class IListOfLists;


class ICardCollection
{
		 public:
					//Harris add-ons
					//Returns the cardlist size
			 
					virtual int getCardListSize()= 0;
					/*
					//ICardList virtual functions
					virtual ICard* getFirst() = 0;
					virtual ICard* getNext() = 0;
					virtual ICard* getLast() = 0;
					virtual ICard* getAt(int) = 0;
					virtual bool isEmpty() = 0;
					*/
					//////IListOfList virtual functions
					//virtual ICardList* getFirstList() = 0;
					//virtual ICardList* getNextList() = 0;
					//virtual ICardList* getLastList() = 0;
					//virtual ICardList* getListAtIndex(int index) = 0;

};
#endif
