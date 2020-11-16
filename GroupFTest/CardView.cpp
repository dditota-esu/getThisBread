#include "CardView.h"

CardView::CardView() {}
void CardView::cardViewInitial(CardImage* c)
{
	x_LL = 0;
	y_LL = 100;
	x_UR = 350;
	y_UR = 0;
	isHidden = true;
	isFaceUp = false;
	isSelected = false;
}
void CardView::cardViewDisplay(float x, float y, bool isFaceUp, bool isSelected)
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
			SelectObject(MemDCCard, img.getCardFrontImage());
		else
			SelectObject(MemDCCard, img.getCardImageBack());

		if (isSelected)
			BitBlt(hdc, x - CARD_WIDTH / 2, y - CARD_HEIGHT / 2, CARD_WIDTH, CARD_HEIGHT, MemDCCard, 0, 0, SRCINVERT);
		else
			BitBlt(hdc, x - CARD_WIDTH / 2, y - CARD_HEIGHT / 2, CARD_WIDTH, CARD_HEIGHT, MemDCCard, 0, 0, SRCCOPY);

		DeleteDC(MemDCCard);
	}
}