
#if !defined CARDVIEW_H
#define CARDVIEW_H
#include "CardImage.h"
#include <windows.h>

class CardView: public CardImage
{
public:
	CardView(char suit, int rank);
	void cardViewDisplay(int x, int y, bool faceUp, bool isSelected, char suit, int rank);
private:
	int x_LL;
	int x_UR;
	int y_LL;
	int y_UR;
	bool isHidden;
	bool isFaceUp;
	bool isSelected;
	int indexValue //Stores the value of the image in the array
};
#endif
