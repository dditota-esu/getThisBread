#include "CardView.h"


const int CARD_HEIGHT = 100;
const int CARD_WIDTH = 72;

HBITMAP CardView::cardBack;
HBITMAP CardView::cardFront;

CardView::CardView()
{
	x_LL = 0;
	y_LL = 100;
	x_UR = 350;
	y_UR = 0;
	isHidden = true;
	isFaceUp = false;
	isSelected = false;
}

void CardView::LoadImages(char suit, int rank, HINSTANCE hInst)
{
	//This gets the info from CardImage class methods and attributes
	int indexValue = getCardFront(suit, rank, hInst);
	cardFront = cardFrontArray[indexValue];


	//Load back image everytime you load a front image
	cardBack = getCardBack(hInst);
}

void CardView::display(HDC* DeviceContext)
{
	int x = x_LL + CARD_WIDTH / 2;
	int y = y_UR + CARD_HEIGHT / 2;

	if (isHidden) {
		HPEN        hOldPen;
		HBRUSH      hOldBrush;
		hOldPen = (HPEN)SelectObject(*DeviceContext, GetStockObject(BLACK_PEN));
		hOldBrush = (HBRUSH)SelectObject(*DeviceContext, GetStockObject(WHITE_BRUSH));
		Rectangle(*DeviceContext, x - (CARD_WIDTH / 2), y - (CARD_HEIGHT / 2), x + (CARD_WIDTH / 2), y + (CARD_HEIGHT / 2));
		SelectObject(*DeviceContext, hOldBrush);
		SelectObject(*DeviceContext, hOldPen);
	}
	else {
		HDC hdc = *DeviceContext;
		HDC MemDCCard = CreateCompatibleDC(hdc);

		if (isFaceUp)
			SelectObject(MemDCCard, cardFront);
		else
			SelectObject(MemDCCard, cardBack);

		if (isSelected)
			BitBlt(hdc, x - CARD_WIDTH / 2, y - CARD_HEIGHT / 2, CARD_WIDTH, CARD_HEIGHT, MemDCCard, 0, 0, SRCINVERT);
		else
			BitBlt(hdc, x - CARD_WIDTH / 2, y - CARD_HEIGHT / 2, CARD_WIDTH, CARD_HEIGHT, MemDCCard, 0, 0, SRCCOPY);

		DeleteDC(MemDCCard);
	}
}

void CardView::click(int in_x, int in_y)
{
	// cycle through the  combinations of isFaceUp, isSelected, isHidden
	if (!isHidden && isFaceUp && isSelected) { // showing card face, selected
		isSelected = false;
	}
	else if (!isHidden && isFaceUp && !isSelected) { // showing card face, not selected
		isFaceUp = false;
	}
	else if (!isHidden && !isFaceUp && !isSelected) { // showing card back, not selected
		isSelected = true;
	}
	else if (!isHidden && !isFaceUp && isSelected) { // showing card back, selected
		isHidden = true;
	}
	else { // not showing card
		isFaceUp = true;
		isHidden = false;
	}
}