#include "CardView.h"

CardView::CardView(char suit, int rank) 
{
	x_LL = 0;
	y_LL = 100;
	x_UR = 350;
	y_UR = 0;
	isHidden = true;
	isFaceUp = false;
	isSelected = false;

	indexValue = getCardFront(hInst, suit, rank);	//Gets the image from the index array in CardImage

	HBITMAP card = cardFrontArray[indexValue];		//Get bitmap from the array 


}

void CardView::cardViewDisplay(int x, int y, bool isFaceUp, bool isSelected, char suit, int rank)
{
	float CARD_WIDTH = x;
	float CARD_HEIGHT = y;
	int Newx = x_LL + CARD_WIDTH / 2;
	int Newy = y_UR + CARD_HEIGHT / 2;

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
			SelectObject(MemDCCard, card);
		else
			SelectObject(MemDCCard, img.getCardImage());

		if (isSelected)
			BitBlt(hdc, x - CARD_WIDTH / 2, y - CARD_HEIGHT / 2, CARD_WIDTH, CARD_HEIGHT, MemDCCard, 0, 0, SRCINVERT);
		else
			BitBlt(hdc, x - CARD_WIDTH / 2, y - CARD_HEIGHT / 2, CARD_WIDTH, CARD_HEIGHT, MemDCCard, 0, 0, SRCCOPY);

		DeleteDC(MemDCCard);
	}
}