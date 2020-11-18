#if !defined CARDIMAGE_H
#define CARDIMAGE_H

#include"windows.h"
#include<string>
#include<iostream>
using namespace std;


//TEST TRIAL 

//=========

class CardImage
{
public:
	//==Attributes==
	static HBITMAP cardFrontArray[51];		 //Array of the card front images
	static HBITMAP cardBackArray[1];					 //Card back image
	static HBITMAP cardBack;
	static HBITMAP cardFront;


	//===function===
	static int getCardFront(char, int, HINSTANCE);			//Function that returns the index of the card image in array
	static HBITMAP getCardBack(HINSTANCE hinst);


};
#endif