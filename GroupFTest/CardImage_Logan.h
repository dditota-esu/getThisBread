#ifndef  CARDIMAGE_H
#define CARDIMAGE_H
#include <windows.h>
#include <iostream>
#include <string>

class CardImage
{
public:
	static int getCardFront(char, int);
	static int getCardBack();

	static HBITMAP cardFrontArray[51];
	static HBITMAP cardBackArray[1];
	//static HBITMAP cardFront;

private:
};
#endif