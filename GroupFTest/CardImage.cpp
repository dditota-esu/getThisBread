#include"CardImageTest.h"


HBITMAP* CardImageTest::getCardFrontImage(char s, int r)
{
	//Spade
	if (s == 's')
	{
		switch (r)
		{
		case 0:
			if (cardFrontArray[0] == NULL)
			{
				//wchar_t* frontFileName = L"3-c.bmp";
			}
		case 1:
			if (cardFrontArray[1] == NULL)
			{
				//wchar_t* frontFileName = L"3-c.bmp";
			}
		case 2:
			if (cardFrontArray[2] == NULL)
			{
				//wchar_t* frontFileName = L"3-c.bmp";
			}
		case 3:
			if (cardFrontArray[3] == NULL)
			{
				//wchar_t* frontFileName = L"3-c.bmp";
			}
		case 4:
			if (cardFrontArray[4] == NULL)
			{
				//wchar_t* frontFileName = L"3-c.bmp";
			}
		case 5:
			if (cardFrontArray[5] == NULL)
			{
				//wchar_t* frontFileName = L"3-c.bmp";
			}
		case 6:
			if (cardFrontArray[6] == NULL)
			{
				//wchar_t* frontFileName = L"3-c.bmp";
			}
		case 7:
			if (cardFrontArray[7] == NULL)
			{
				//wchar_t* frontFileName = L"3-c.bmp";
			}
		case 8:
			if (cardFrontArray[8] == NULL)
			{
				//wchar_t* frontFileName = L"3-c.bmp";
			}
		case 9:
			if (cardFrontArray[9] == NULL)
			{
				//wchar_t* frontFileName = L"3-c.bmp";
			}
		case 10:
			if (cardFrontArray[10] == NULL)
			{
				//wchar_t* frontFileName = L"3-c.bmp";
			}
		case 11:
			if (cardFrontArray[11] == NULL)
			{
				//wchar_t* frontFileName = L"3-c.bmp";
			}
		case 12:
			if (cardFrontArray[12] == NULL)
			{
				//wchar_t* frontFileName = L"3-c.bmp";
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
				//wchar_t* frontFileName = L"3-c.bmp";
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
		case 13:
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
		case 13:
		}
	}

	else
	{
		cout << "ERROR - NO CARD WITH THAT SUIT" << endl;
	}


}
