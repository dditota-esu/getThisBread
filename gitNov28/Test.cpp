#include<iostream>
using namespace std;

#include"ICardCollection.h"
#include "CardAreaView.h"
#include"Card.h"
#include"CardList.h"


int checkSize(ICardCollection* x);

int main()
{
		 cout << "Setting up CardList" << endl;
		 CardList* deck = new CardList();

		 if(deck->isEmpty())
		 {
					cout << "The Deck is Empty!" << endl;
		 }

		 cout << "Adding the Cards to the deck" << endl;
		 //Creating two cards to add to cardlist
		 //0 = Ace 10 = Jack 11 = Queen 12 = King
		 Card* numOne = new Card(0, Diamonds);
		 //Card* numTwo = new Card(12, Hearts);

		 //Now create and add to CardList
		 deck->addToBeginning(numOne);
		 //deck->addToBeginning(numTwo);
		 
		 cout << "Now checking the size of the CardList/Deck" << endl;
		 cout << "The deck has " << checkSize(deck) << endl;

		 

		 system("pause");
		 return 0;
}

int checkSize(ICardCollection* x)
{
		 return x->getCardListSize();
}