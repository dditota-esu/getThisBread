#include "CardView.h"

HBITMAP CardView::cardFront;
HBITMAP CardView::cardBack;

CardView::CardView(char suit, int rank) 
{
	x_LL = 0;
	y_LL = 100;
	x_UR = 350;
	y_UR = 0;
	isFaceUp = false;
	isSelected = false;

	frontIndex = getCardFront(suit, rank);	//Gets the image from the index array in CardImage
	backIndex = getCardBack();
	cardBack = cardBackArray[backIndex];
	cardFront = cardFrontArray[frontIndex];		//Get bitmap from the array 
}

void CardView::cardViewDisplay(int x, int y, bool isFaceUp, bool isSelected)
{
	int CARD_WIDTH = x;
	int CARD_HEIGHT = y;
	int Newx = x_LL + CARD_WIDTH / 2;
	int Newy = y_UR + CARD_HEIGHT / 2;

	HDC hdc = CreateCompatibleDC(NULL);
	SelectObject(hdc, cardFront);
	while (1)
	{
		HDC hdc_x = GetDC(HWND_DESKTOP);
		BitBlt(hdc_x, x - CARD_WIDTH / 2, y - CARD_HEIGHT / 2, CARD_WIDTH, CARD_HEIGHT, hdc, 0, 0, SRCCOPY);
		ReleaseDC(HWND_DESKTOP, hdc_x);
	}

	/*
	HDC MemDCCard = CreateCompatibleDC(NULL);
	HDC hdc_x = GetDC(HWND_DESKTOP);

	if (isFaceUp)
		SelectObject(MemDCCard, cardFront);
	else
		SelectObject(MemDCCard, cardBack);
	if (isSelected)
		BitBlt(hdc_x, x - CARD_WIDTH / 2, y - CARD_HEIGHT / 2, CARD_WIDTH, CARD_HEIGHT, MemDCCard, 0, 0, SRCINVERT);
	else
		BitBlt(hdc_x, x - CARD_WIDTH / 2, y - CARD_HEIGHT / 2, CARD_WIDTH, CARD_HEIGHT, MemDCCard, 0, 0, SRCCOPY);

		DeleteDC(MemDCCard);
		*/
}