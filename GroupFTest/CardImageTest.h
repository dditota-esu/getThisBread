#if !defined CARDIMAGETEST_H
#define CARDIMAGETEST_H
#include<Windows.h>

class CardImageTest
{
public:
	HBITMAP* getCardFrontImage();
	HBITMAP* getCardImageBack();
	CardImageTest(char s, int v);

private:
	HBITMAP* cardFront;
	HBITMAP* cardBack;
	char suit;
	int rank;
};
#endif