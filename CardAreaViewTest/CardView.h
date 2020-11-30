#if !defined CARDVIEW_H
#define CARDVIEW_H
#include"CardImage.h"
#include"ICard.h"
#include<iostream>
using namespace std;

class CardView: public CardImage
{
private:
	int rankCard = -1;
	char suitCard = 'z';
	int frontIndex;			//gets the index of the front image in cardFrontArray
	HBITMAP back;		//Holds the HBITMAP of the back card
	bool faceUp;
	bool selected;
	//---------------------
public:
	CardView(ICard*);	//Initialize cardview by ICard or with char and int parameters
	CardView(char, int);
	void display(int x, int y, HDC*);
	void click(int, int);
};
#endif
