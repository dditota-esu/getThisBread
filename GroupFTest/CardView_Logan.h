#if !defined CARDVIEW_H
#define CARDVIEW_H
#include "CardImage.h"
#include <windows.h>

class CardView: public CardImage
{
public:
	CardView(char suit, int rank);
	void cardViewDisplay(int x, int y, bool faceUp, bool isSelected);
private:
	int x_LL;
	int x_UR;
	int y_LL;
	int y_UR;
	bool isFaceUp;
	bool isSelected;
	int frontIndex;
	int backIndex;
	static HBITMAP cardFront;
	static HBITMAP cardBack;
};
#endif
