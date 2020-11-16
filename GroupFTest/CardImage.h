#ifndef  CARDIMAGE_H
#define CARDIMAGE_H
#include <windows.h>

class CardImage
{
public:
	HBITMAP* getCardFrontImage();
	HBITMAP* getCardImageBack();
	CardImage(char, int);
private:
	HBITMAP* cardFront;
	HBITMAP* cardBack;
	char suit;
	int rank;
};
#endif