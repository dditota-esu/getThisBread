
#include "CardView.h"
#include <iostream>

int main()
{
	CardView* cv = new CardView('s', 0);
	cv->cardViewDisplay(72, 100, true, false);
	return 0;
}