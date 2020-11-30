#if !defined CARDIMAGE_H
#define CARDIMAGE_H

#include"windows.h"

class CardImage
{

		 public:
	//static 
			 int loadImages(char, int);	//Given suit and rank a image is loaded
	//static 
			 int getImageFront(char, int);			//Returns the card image front as an HBITMAP or index
			 static HBITMAP getImageBack();		//Returns the hbitmap of the card back
		   static HBITMAP cardFrontArray[52]; //Data structure to hold all card image in a deck
};
#endif

