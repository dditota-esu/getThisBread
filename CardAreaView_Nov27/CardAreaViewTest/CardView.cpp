#include"CardView.h"
const int CARD_HEIGHT = 100;
const int CARD_WIDTH = 72;

CardView::CardView(ICard* card)
{

	rankCard = card->getRank();

	if (card->getSuit() == Spades)
	{
		suitCard = 's';
	}
	else if (card->getSuit() == Hearts)
	{
		suitCard = 'h';
	}
	else if (card->getSuit() == Diamonds)
	{
		suitCard = 'd';
	}
	else if (card->getSuit() == Clubs)
	{
		suitCard = 'c';
	}
	else
	{
		cout << "Card suit does not exist" << endl;
	}
	int index = loadImages(suitCard, rankCard);

	//Get index of the front in the cardFrontArray
	frontIndex = getImageFront(suitCard, rankCard);

	//Get the HBITMAP of the back card
	back = getImageBack();

	
}

CardView::CardView(char suit, int rank)
{
	rankCard = rank;
	suitCard = suit;


	//Get index of the front in the cardFrontArray
	int index = loadImages(suitCard, rankCard);
	frontIndex = getImageFront(suitCard, rankCard);

	//Get the HBITMAP of the back card
	back = getImageBack();
}

void CardView::display(int xP, int yP, bool isFaceUpX, bool isSelectedX, HDC* DeviceContext)
{
	//int x = x_LL + CARD_WIDTH / 2;
	int x = xP + CARD_WIDTH / 2;
	int y = yP + CARD_HEIGHT / 2;
	//int y = y_UR + CARD_HEIGHT / 2;


		HDC hdc = *DeviceContext;
		HDC MemDCCard = CreateCompatibleDC(hdc);

		if (isFaceUpX)									//The value here calls the front image from the array
			SelectObject(MemDCCard, cardFrontArray[frontIndex]);
		else
			SelectObject(MemDCCard, back);

		if (isSelectedX)
			BitBlt(hdc, x - CARD_WIDTH / 2, y - CARD_HEIGHT / 2, CARD_WIDTH, CARD_HEIGHT, MemDCCard, 0, 0, SRCINVERT);
		else
			BitBlt(hdc, x - CARD_WIDTH / 2, y - CARD_HEIGHT / 2, CARD_WIDTH, CARD_HEIGHT, MemDCCard, 0, 0, SRCCOPY);


		DeleteDC(MemDCCard);

		
}

void CardView::click(int in_x, int in_y)
{
	
}
