#include"CardImageTest.h"


HBITMAP* CardImageTest::getCardFrontImage(char s, int r)
{
	//Do not forget the break statements in the switch cases. 0 = A and 11= J, 12 = Q, 13 = K
	//Spade
	if (s == 's')
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

	//Diamond
	else if(s == 'd')
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

	//Clubs
	else if(s == 'c')
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
	else if(s == 'h')
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
