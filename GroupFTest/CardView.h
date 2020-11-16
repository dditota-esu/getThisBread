
#if !defined CARDVIEW_H
#define CARDVIEW_H
#include "CardImage.h"

#include <windows.h>

	class CardView
{
public:
	void cardViewInitial(CardImage*);
	void cardViewDisplay(float x, float y, bool faceUp, bool isSelected);
	CardView();
private:
	int x_LL;
	int x_UR;
	int y_LL;
	int y_UR;
	bool isHidden;
	bool isFaceUp;
	bool isSelected;
	CardImage* img;
};
#endif
