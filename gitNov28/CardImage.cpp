#include"CardImage.h"

//Data structure used to hold the card images to be called later
HBITMAP CardImage::cardFrontArray[52];


//This will retrieve the back of the card image as an hbitmap
HBITMAP CardImage::getImageBack()
{
		 HBITMAP backCard;
		 const wchar_t* frontFileName = L"cardImages/back.bmp";
		 HBITMAP back = (HBITMAP)LoadImage(NULL, frontFileName, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		 backCard = back;
		 return backCard;
}



//This will retrieve the front of the card from the card array
int CardImage::getImageFront(char s, int r)
{
		 int cardIndexValue = loadImages(s, r);
		 return cardIndexValue;
}

//This will load the images and if its already loaded will return the index of that card in the array
int CardImage::loadImages(char s, int r)
{
		 const wchar_t* frontFileName;

		 //Spades
		 if (s == 's')
		 {
					switch (r)
					{
					case 0:
							 if (cardFrontArray[0] == NULL)
							 {

										frontFileName = L"cardImages/1-1.bmp";
										cardFrontArray[0] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

										return 0;
										break;
							 }
							 else
							 {
										return 0;
										break;
							 }
					case 1:
							 if (cardFrontArray[1] == NULL)
							 {
										frontFileName = L"cardImages/1-2.bmp";
										cardFrontArray[1] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 1;
										break;
							 }
							 else
							 {
										return 1;
										break;
							 }
					case 2:
							 if (cardFrontArray[2] == NULL)
							 {
										frontFileName = L"cardImages/1-3.bmp";
										cardFrontArray[2] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 2;
										break;
							 }
							 else
							 {
										return 2;
										break;
							 }
					case 3:
							 if (cardFrontArray[3] == NULL)
							 {
										frontFileName = L"cardImages/1-4.bmp";
										cardFrontArray[3] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 3;
										break;
							 }
							 else
							 {
										return 3;
										break;
							 }
					case 4:
							 if (cardFrontArray[4] == NULL)
							 {
										frontFileName = L"cardImages/1-5.bmp";
										cardFrontArray[4] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 4;
										break;
							 }
							 else
							 {
										return 4;
										break;
							 }
					case 5:
							 if (cardFrontArray[5] == NULL)
							 {
										frontFileName = L"cardImages/1-6.bmp";
										cardFrontArray[5] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 5;
										break;
							 }
							 else
							 {
										return 5;
										break;
							 }
					case 6:
							 if (cardFrontArray[6] == NULL)
							 {
										frontFileName = L"cardImages/1-7.bmp";
										cardFrontArray[6] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 6;
										break;
							 }
							 else
							 {
										return 6;
										break;
							 }
					case 7:
							 if (cardFrontArray[7] == NULL)
							 {
										frontFileName = L"cardImages/1-8.bmp";
										cardFrontArray[7] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 7;
										break;
							 }
							 else
							 {
										return 7;
										break;
							 }
					case 8:
							 if (cardFrontArray[8] == NULL)
							 {
										frontFileName = L"cardImages/1-9.bmp";
										cardFrontArray[8] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 8;
										break;
							 }
							 else
							 {
										return 8;
										break;
							 }
					case 9:
							 if (cardFrontArray[9] == NULL)
							 {
										frontFileName = L"cardImages/1-a.bmp";
										cardFrontArray[9] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 9;
										break;
							 }
							 else
							 {
										return 9;
										break;
							 }
					case 10:
							 if (cardFrontArray[10] == NULL)
							 {
										frontFileName = L"cardImages/1-b.bmp";
										cardFrontArray[10] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 10;
										break;
							 }
							 else
							 {
										return 10;
										break;
							 }
					case 11:
							 if (cardFrontArray[11] == NULL)
							 {
										frontFileName = L"cardImages/1-c.bmp";
										cardFrontArray[11] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 11;
										break;
							 }
							 else
							 {
										return 11;
										break;
							 }
					case 12:
							 if (cardFrontArray[12] == NULL)
							 {
										frontFileName = L"cardImages/1-d.bmp";
										cardFrontArray[12] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 12;
										break;
							 }
							 else
							 {
										return 12;
										break;
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
										frontFileName = L"cardImages/4-1.bmp";
										cardFrontArray[13] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 13;
										break;
							 }
							 else
							 {
										return 13;
										break;
							 }
					case 1:
							 if (cardFrontArray[14] == NULL)
							 {
										frontFileName = L"cardImages/4-2.bmp";
										cardFrontArray[14] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 14;
										break;
							 }
							 else
							 {
										return 14;
										break;
							 }
					case 2:
							 if (cardFrontArray[15] == NULL)
							 {
										frontFileName = L"cardImages/4-3.bmp";
										cardFrontArray[15] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 15;
										break;
							 }
							 else
							 {
										return 15;
										break;
							 }
					case 3:
							 if (cardFrontArray[16] == NULL)
							 {
										frontFileName = L"cardImages/4-4.bmp";
										cardFrontArray[16] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 16;
										break;
							 }
							 else
							 {
										return 16;
										break;
							 }
					case 4:
							 if (cardFrontArray[17] == NULL)
							 {
										frontFileName = L"cardImages/4-5.bmp";
										cardFrontArray[17] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 17;
										break;
							 }
							 else
							 {
										return 17;
										break;
							 }
					case 5:
							 if (cardFrontArray[18] == NULL)
							 {
										frontFileName = L"cardImages/4-6.bmp";
										cardFrontArray[18] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 18;
										break;
							 }
							 else
							 {
										return 18;
										break;
							 }
					case 6:
							 if (cardFrontArray[19] == NULL)
							 {
										frontFileName = L"cardImages/4-7.bmp";
										cardFrontArray[19] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 19;
										break;
							 }
							 else
							 {
										return 19;
										break;
							 }
					case 7:
							 if (cardFrontArray[20] == NULL)
							 {
										frontFileName = L"cardImages/4-8.bmp";
										cardFrontArray[20] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 20;
										break;
							 }
							 else
							 {
										return 20;
										break;
							 }
					case 8:
							 if (cardFrontArray[21] == NULL)
							 {
										frontFileName = L"cardImages/4-9.bmp";
										cardFrontArray[21] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 21;
										break;
							 }
							 else
							 {
										return 21;
										break;
							 }
					case 9:
							 if (cardFrontArray[22] == NULL)
							 {
										frontFileName = L"cardImages/4-a.bmp";
										cardFrontArray[22] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 22;
										break;
							 }
							 else
							 {
										return 22;
										break;
							 }
					case 10:
							 if (cardFrontArray[23] == NULL)
							 {
										frontFileName = L"cardImages/4-b.bmp";
										cardFrontArray[23] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 23;
										break;
							 }
							 else
							 {
										return 23;
										break;
							 }
					case 11:
							 if (cardFrontArray[24] == NULL)
							 {
										frontFileName = L"cardImages/4-c.bmp";
										cardFrontArray[24] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 24;
										break;
							 }
							 else
							 {
										return 24;
										break;
							 }
					case 12:
							 if (cardFrontArray[25] == NULL)
							 {
										frontFileName = L"cardImages/4-d.bmp";
										cardFrontArray[25] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 25;
										break;
							 }
							 else
							 {
										return 25;
										break;
							 }
					}
		 }

		 //Clubs
		 else if (s == 'c')
		 {
					switch (r)
					{
					case 0:
							 if (cardFrontArray[26] == NULL)
							 {
										frontFileName = L"cardImages/2-1.bmp";
										cardFrontArray[26] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 26;
										break;
							 }
							 else
							 {
										return 26;
										break;
							 }
					case 1:
							 if (cardFrontArray[27] == NULL)
							 {
										frontFileName = L"cardImages/2-2.bmp";
										cardFrontArray[27] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 27;
										break;
							 }
							 else
							 {
										return 27;
										break;
							 }
					case 2:
							 if (cardFrontArray[28] == NULL)
							 {
										frontFileName = L"cardImages/2-3.bmp";
										cardFrontArray[28] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 28;
										break;
							 }
							 else
							 {
										return 28;
										break;
							 }
					case 3:
							 if (cardFrontArray[29] == NULL)
							 {
										frontFileName = L"cardImages/2-4.bmp";
										cardFrontArray[29] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 29;
										break;
							 }
							 else
							 {
										return 29;
										break;
							 }
					case 4:
							 if (cardFrontArray[30] == NULL)
							 {
										frontFileName = L"cardImages/2-5.bmp";
										cardFrontArray[30] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 30;
										break;
							 }
							 else
							 {
										return 30;
										break;
							 }
					case 5:
							 if (cardFrontArray[31] == NULL)
							 {
										frontFileName = L"cardImages/2-6.bmp";
										cardFrontArray[31] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 31;
										break;
							 }
							 else
							 {
										return 31;
										break;
							 }
					case 6:
							 if (cardFrontArray[32] == NULL)
							 {
										frontFileName = L"cardImages/2-7.bmp";
										cardFrontArray[32] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 32;
										break;
							 }
							 else
							 {
										return 32;
										break;
							 }
					case 7:
							 if (cardFrontArray[33] == NULL)
							 {
										frontFileName = L"cardImages/2-8.bmp";
										cardFrontArray[33] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 33;
										break;
							 }
							 else
							 {
										return 33;
										break;
							 }
					case 8:
							 if (cardFrontArray[34] == NULL)
							 {
										frontFileName = L"cardImages/2-9.bmp";
										cardFrontArray[34] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 34;
										break;
							 }
							 else
							 {
										return 34;
										break;
							 }
					case 9:
							 if (cardFrontArray[35] == NULL)
							 {
										frontFileName = L"cardImages/2-a.bmp";
										cardFrontArray[35] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 35;
										break;
							 }
							 else
							 {
										return 35;
										break;
							 }
					case 10:
							 if (cardFrontArray[36] == NULL)
							 {
										frontFileName = L"cardImages/2-b.bmp";
										cardFrontArray[36] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 36;
										break;
							 }
							 else
							 {
										return 36;
										break;
							 }
					case 11:
							 if (cardFrontArray[37] == NULL)
							 {
										frontFileName = L"cardImages/2-c.bmp";
										cardFrontArray[37] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 37;
										break;
							 }
							 else
							 {
										return 37;
										break;
							 }
					case 12:
							 if (cardFrontArray[38] == NULL)
							 {
										frontFileName = L"cardImages/2-d.bmp";
										cardFrontArray[38] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 38;
										break;
							 }
							 else
							 {
										return 38;
										break;
							 }
					}
		 }

		 //Hearts
		 else if (s == 'h')
		 {
					switch (r)
					{
					case 0:
							 if (cardFrontArray[39] == NULL)
							 {
										frontFileName = L"cardImages/3-1.bmp";
										cardFrontArray[39] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 39;
										break;
							 }
							 else
							 {
										return 39;
										break;
							 }
					case 1:
							 if (cardFrontArray[40] == NULL)
							 {
										frontFileName = L"cardImages/3-2.bmp";
										cardFrontArray[40] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 40;
										break;
							 }
							 else
							 {
										return 40;
										break;
							 }
					case 2:
							 if (cardFrontArray[41] == NULL)
							 {
										frontFileName = L"cardImages/3-3.bmp";
										cardFrontArray[41] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 41;
										break;
							 }
							 else
							 {
										return 41;
										break;
							 }
					case 3:
							 if (cardFrontArray[42] == NULL)
							 {
										frontFileName = L"cardImages/3-4.bmp";
										cardFrontArray[42] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 42;
										break;
							 }
							 else
							 {
										return 42;
										break;
							 }
					case 4:
							 if (cardFrontArray[43] == NULL)
							 {
										frontFileName = L"cardImages/3-5.bmp";
										cardFrontArray[43] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 43;
										break;
							 }
							 else
							 {
										return 43;
										break;
							 }
					case 5:
							 if (cardFrontArray[44] == NULL)
							 {
										frontFileName = L"cardImages/3-6.bmp";
										cardFrontArray[44] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 44;
										break;
							 }
							 else
							 {
										return 44;
										break;
							 }
					case 6:
							 if (cardFrontArray[45] == NULL)
							 {
										frontFileName = L"cardImages/3-7.bmp";
										cardFrontArray[45] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 45;
										break;
							 }
							 else
							 {
										return 45;
										break;
							 }
					case 7:
							 if (cardFrontArray[46] == NULL)
							 {
										frontFileName = L"cardImages/3-8.bmp";
										cardFrontArray[46] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 46;
										break;
							 }
							 else
							 {
										return 46;
										break;
							 }
					case 8:
							 if (cardFrontArray[47] == NULL)
							 {
										frontFileName = L"cardImages/3-9.bmp";
										cardFrontArray[47] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 47;
										break;
							 }
							 else
							 {
										return 47;
										break;
							 }
					case 9:
							 if (cardFrontArray[48] == NULL)
							 {
										frontFileName = L"cardImages/3-a.bmp";
										cardFrontArray[48] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 48;
										break;
							 }
							 else
							 {
										return 48;
										break;
							 }
					case 10:
							 if (cardFrontArray[49] == NULL)
							 {
										frontFileName = L"cardImages/3-b.bmp";
										cardFrontArray[49] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 49;
										break;
							 }
							 else
							 {
										return 49;
										break;
							 }
					case 11:
							 if (cardFrontArray[50] == NULL)
							 {
										frontFileName = L"cardImages/3-c.bmp";
										cardFrontArray[50] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 50;
										break;
							 }
							 else
							 {
										return 50;
										break;
							 }
					case 12:
							 if (cardFrontArray[51] == NULL)
							 {
										frontFileName = L"cardImages/3-d.bmp";
										cardFrontArray[51] = (HBITMAP)LoadImage(NULL, frontFileName,
												 IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
										return 51;
										break;
							 }
							 else
							 {
										return 51;
										break;
							 }
					}
		 }
		 return -1;
}