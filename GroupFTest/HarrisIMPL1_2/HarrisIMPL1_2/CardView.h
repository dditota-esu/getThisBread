#include"CardImage.h"
#if !defined CARDVIEW_H
#define CARDVIEW_H

#include"windows.h"
#include<string>
#include<iostream>
using namespace std;

//include ICard header

class CardView : public CardImage //, publicICard
{
public:

	CardView();		//Add ICard object
	//~CardView();
	void display(HDC* DeviceContent);
	void click(int x, int y);
	static void LoadImages(char suit, int rank, HINSTANCE hInst);

private:
	int x_LL;
	int x_UR;
	int y_LL;
	int y_UR;
	bool isHidden;
	bool isFaceUp;
	bool isSelected;
	static HBITMAP cardFront;
	static HBITMAP cardBack;

};
#endif 