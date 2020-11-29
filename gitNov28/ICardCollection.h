#if !defined ICARDCOLLECTION_H
#define ICARDCOLLECTION_H
//This is an interface class 


class ICardCollection
{
		 public:
					//Returns the cardlist size
					virtual int getCardListSize()= 0;


					/*virtual Suit getSuit() = 0;
					virtual int getRank() = 0;*/
};
#endif
