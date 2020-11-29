#pragma once
#if !defined CARDIMAGE_H
#define CARDIMAGE_H

#include"windows.h";

class CardImage
{

public:

		 //Given suit and rank a image is loaded
		 int loadImages(char, int);
		 //Returns the card image front as an HBITMAP or index
		 int getImageFront(char, int);

		 //STATIC-----------------------------------------------
		 //Returns the hbitmap of the card back
		 static HBITMAP getImageBack();

		 //Data structure to hold all card image in a deck
		 static HBITMAP cardFrontArray[52];
};
#endif