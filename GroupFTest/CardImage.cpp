#include"CardImage.h"
#include<windows.h>
#include <string>



int CardImage::getCardFront(HINSTANCE hInst, char s, int r)
{
	const wchar_t* frontFileName;


	//Spade
	if (s == 's')
	{
		switch (r)
		{
		case 0:
			if (cardFrontArray[0] == NULL)
			{

				frontFileName = L"cardImages/1-1.bmp";
				cardFrontArray[0] = (HBITMAP)LoadImage(hInst, frontFileName,
					IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			}
			else
			{
				return 0;
			}
		case 1:
			if (cardFrontArray[1] == NULL)
			{
				frontFileName = L"cardImages/1-2.bmp";
				cardFrontArray[1] = (HBITMAP)LoadImage(hInst, frontFileName,
					IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			}
			else
			{
				return 1;
			}
		case 2:
			if (cardFrontArray[2] == NULL)
			{
				frontFileName = L"cardImages/1-3.bmp";
				cardFrontArray[2] = (HBITMAP)LoadImage(hInst, frontFileName,
					IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			}
			else
			{
				return 2;
			}
		case 3:
			if (cardFrontArray[3] == NULL)
			{
				frontFileName = L"cardImages/1-4.bmp";
				cardFrontArray[3] = (HBITMAP)LoadImage(hInst, frontFileName,
					IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			}
		case 4:
			if (cardFrontArray[4] == NULL)
			{
				frontFileName = L"cardImages/1-5.bmp";
				cardFrontArray[4] = (HBITMAP)LoadImage(hInst, frontFileName,
					IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			}
		case 5:
			if (cardFrontArray[5] == NULL)
			{
				frontFileName = L"cardImages/1-6.bmp";
				cardFrontArray[5] = (HBITMAP)LoadImage(hInst, frontFileName,
					IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			}
		case 6:
			if (cardFrontArray[6] == NULL)
			{
				frontFileName = L"cardImages/1-7.bmp";
				cardFrontArray[6] = (HBITMAP)LoadImage(hInst, frontFileName,
					IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			}
		case 7:
			if (cardFrontArray[7] == NULL)
			{
				frontFileName = L"cardImages/1-8.bmp";
				cardFrontArray[7] = (HBITMAP)LoadImage(hInst, frontFileName,
					IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			}
		case 8:
			if (cardFrontArray[8] == NULL)
			{
				frontFileName = L"cardImages/1-9.bmp";
				cardFrontArray[8] = (HBITMAP)LoadImage(hInst, frontFileName,
					IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			}
		case 9:
			if (cardFrontArray[9] == NULL)
			{
				frontFileName = L"cardImages/1-a.bmp";
				cardFrontArray[9] = (HBITMAP)LoadImage(hInst, frontFileName,
					IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			}
		case 10:
			if (cardFrontArray[10] == NULL)
			{
				frontFileName = L"cardImages/1-b.bmp";
				cardFrontArray[10] = (HBITMAP)LoadImage(hInst, frontFileName,
					IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			}
		case 11:
			if (cardFrontArray[11] == NULL)
			{
				frontFileName = L"cardImages/1-c.bmp";
				cardFrontArray[11] = (HBITMAP)LoadImage(hInst, frontFileName,
					IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			}
		case 12:
			if (cardFrontArray[12] == NULL)
			{
				frontFileName = L"cardImages/1-d.bmp";
				cardFrontArray[12] = (HBITMAP)LoadImage(hInst, frontFileName,
					IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
			}
		}
	}

	//Diamond
	else if (s == 'd')
	{
		switch (r)
		{
		case 0:
			if (cardFrontArray[13] == NULL)
			{

			}
		case 1:
			if (cardFrontArray[14] == NULL)
			{
				//wchar_t* frontFileName = L"3-c.bmp";
			}
		case 2:
			if (cardFrontArray[15] == NULL)
			{
				//wchar_t* frontFileName = L"3-c.bmp";
			}
		case 3:
			if (cardFrontArray[16] == NULL)
			{
				//wchar_t* frontFileName = L"3-c.bmp";
			}
		case 4:
			if (cardFrontArray[17] == NULL)
			{
				//wchar_t* frontFileName = L"3-c.bmp";
			}
		case 5:
			if (cardFrontArray[18] == NULL)
			{
				//wchar_t* frontFileName = L"3-c.bmp";
			}
		case 6:
			if (cardFrontArray[19] == NULL)
			{
				//wchar_t* frontFileName = L"3-c.bmp";
			}
		case 7:
			if (cardFrontArray[20] == NULL)
			{
				//wchar_t* frontFileName = L"3-c.bmp";
			}
		case 8:
			if (cardFrontArray[21] == NULL)
			{
				//wchar_t* frontFileName = L"3-c.bmp";
			}
		case 9:
			if (cardFrontArray[22] == NULL)
			{
				//wchar_t* frontFileName = L"3-c.bmp";
			}
		case 10:
			if (cardFrontArray[23] == NULL)
			{
				//wchar_t* frontFileName = L"3-c.bmp";
			}
		case 11:
			if (cardFrontArray[24] == NULL)
			{
				//wchar_t* frontFileName = L"3-c.bmp";
			}
		case 12:
			if (cardFrontArray[25] == NULL)
			{
				//wchar_t* frontFileName = L"3-c.bmp";
			}
		}
	}

	//Clubs
	else if (s == 'c')
	{
		switch (r)
		{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		}
	}


	//Hearts
	else if (s == 'h')
	{
		switch (r)
		{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		}
	}

	else
	{
		//cout << "ERROR - NO CARD WITH THAT SUIT" << endl;
	}
}

HBITMAP* CardImage::getCardBack(HINSTANCE hInst)
{
	const wchar_t* frontFileName = L"cardImages/back.bmp";
	HBITMAP* back = (HBITMAP)LoadImage(hInst, frontFileName,
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE); 

	return back;
}




