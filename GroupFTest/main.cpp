#include "CardView.h"
#include <iostream>

int main()
{
	CardView* cv = new CardView();
	CardImage* img = new CardImage('s', 0);
	cv->cardViewInitial(img);//dont know how to load images from files using her view w/ h instance
	cv->cardViewDisplay(); //takes x and y
	return 0;
}