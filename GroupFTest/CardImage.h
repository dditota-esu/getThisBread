#ifndef  CARDIMAGE_H
#define CARDIMAGE_H
#include <windows.h>
#include<iostream>
#include <string>

class CardImage
{
public:
	static HBITMAP* getCardFrontImage(HINSTANCE, char, int);
	static HBITMAP* getCardImageBack(char, int);

private:
	static HBITMAP cardFrontArray[51];
	HBITMAP cardBackArray; //single back image
	void LoadImages(HINSTANCE hInst);

	static HBITMAP cardFront;
	HBITMAP cardBack;
};
#endif