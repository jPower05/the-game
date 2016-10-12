#ifndef H_SetUp
#define H_SetUp

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class SetUp{

public:
	SetUp();
	void printPlayerHand();
	void printComputerHand();
	void printDeck();
	void printVectorsCurrentStatus();
	void playPlayerCard(int CardNum);
	void addCardToPlayerHand();
	void addCardToComputerHand();
	void removeFromPlayerHand(int cardNum);
	void removeFromComputerHand(int cardNum);
	void computerGo();
	int finding1_100Dif(int num);
	int finding100_1Dif(int num);

private:
	//Pointers for the vectors deck, playerHand, computerHand
	vector<int>* ptrDeckVec = new vector<int>();
	vector<int>* ptrPlayerHand = new vector <int>();
	vector<int>* ptrComputerHand = new vector <int>();
	vector<int>* ptrIncreasingPile1 = new vector <int>();
	vector <int>* ptrIncreasingPile2 = new vector <int>();
	vector <int>* ptrDecreasingPile1 = new vector <int>();
	vector <int>* ptrDecreasingPile2 = new vector <int>();


};






















#endif