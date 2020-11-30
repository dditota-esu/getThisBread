#include "CardListSTUB.h"
#include <algorithm>

using namespace std;

CardList::CardList() {
	currentCard = 0;
}

void CardList::readFile(string filename) {
	// One file per CardList? We're not sure how else this could be implemented
}

void CardList::writeFile(string filename) {
	// One file per CardList? We're not sure how else this could be implemented
}

ICard* CardList::getFirst() {
	if (theCards.size() == 0) return 0;
	currentCard = 0;
	return theCards.at(0);
}

ICard* CardList::getNext() {
	currentCard++;

	if (currentCard == theCards.size()) return 0;

	return theCards.at(currentCard);
}

ICard* CardList::getLast() {
	if (theCards.size() == 0) return 0;
	return theCards.at(theCards.size() - 1);
}

ICard* CardList::getAt(int index) {
	if (theCards.size() == 0 || index > theCards.size() - 1) return 0;
	return theCards.at(index);
}

bool CardList::isEmpty() {
	return theCards.empty();
}

void CardList::addToEnd(Card* newCard) {
	theCards.push_back(newCard);
}

void CardList::addToBeginning(Card* newCard) {
	theCards.insert(theCards.begin(), newCard);
}

void CardList::addAtIndex(Card* newCard, int index) {
	theCards.insert(theCards.begin() + index, newCard);
}

Card* CardList::removeAtEnd() {
	Card* removedCard = theCards.at(theCards.size() - 1);
	theCards.erase(theCards.begin() + theCards.size() - 1);
	return removedCard;
}

Card* CardList::removeAtBeginning() {
	if (theCards.size() == 0) return 0;

	Card* removedCard = theCards.at(0);
	theCards.erase(theCards.begin());
	return removedCard;
}

Card* CardList::removeAtIndex(int index) {
	if (index >= theCards.size()) return 0;

	Card* removedCard = theCards.at(index);
	theCards.erase(theCards.begin() + index);
	return removedCard;
}

void CardList::shuffle() {
	// Will need a seed to generate truly random shuffling
	// random_shuffle(theCards.begin(), theCards.end(), randomNumber)
	random_shuffle(theCards.begin(), theCards.end());
}

void CardList::sortBySuit() {
	sort(theCards.begin(), theCards.end(),
		[&](Card* one, Card* two)
		{
			return one->getSuit() < two->getSuit();
		});
}

void CardList::sortByRank() {
	sort(theCards.begin(), theCards.end(),
		[&](Card* one, Card* two)
		{
			return one->getRank() < two->getRank();
		});
}

CardList::~CardList() {
	for (int i = 0; i < theCards.size(); i++) {
		delete theCards[i];
	}
}