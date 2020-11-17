#ifndef  CARDIMAGE_H
#define CARDIMAGE_H
#include <windows.h>
#include<iostream>
#include <string>

class CardImage
{
public:
	static int getCardFront(HINSTANCE, char, int);
	static HBITMAP* getCardBack(HINSTANCE);

	static HBITMAP cardFrontArray[51];
	HBITMAP cardBack;

private:
	HBITMAP cardBackArray; //single back image
	static HBITMAP cardFront;
	HBITMAP cardBack;
};
#endif