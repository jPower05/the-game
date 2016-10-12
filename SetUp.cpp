#include "SetUp.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;




SetUp::SetUp(){
	std::srand(std::time(0));
	//Populates the vector 2-99
	for (int i = 2; i < 100; ++i){
		ptrDeckVec->push_back(i);
	}

	//Shuffles the deck
	random_shuffle(ptrDeckVec->begin(), ptrDeckVec->end());

	//Populates the players hand
	
	for (int i = 0; i < 7; ++i){
		//Gets the last element in the Deck
		int x = ptrDeckVec->back();
		//cout << x << endl;
		//Adds the last element from the Deck to the Player Hand Vector
		ptrPlayerHand->push_back(x);
		//Deletes the last element in the Deck as it is now in the Players Hand
		ptrDeckVec->pop_back();
	}

	// Populates the computers hand
	
	for (int i = 0; i < 7; ++i){
			//Gets the last element in the Deck
			int x = ptrDeckVec->back();
			//cout << x << endl;
			//Adds the last element from the Deck to the Player Hand Vector
			ptrComputerHand->push_back(x);
			//Deletes the last element in the Deck as it is now in the Players Hand
			ptrDeckVec->pop_back();
	}

	// Populates the initial value of 1 to both Increasing vectors
	ptrIncreasingPile1->push_back(1);
	ptrIncreasingPile2->push_back(1);

	//Populates the initial value of 100 to both Decreasing vectors
	ptrDecreasingPile1->push_back(100);
	ptrDecreasingPile2->push_back(100);

}





void SetUp::addCardToPlayerHand(){
	//Gets the last element in the Deck
	int x = ptrDeckVec->back();
	//cout << x << endl;
	//Adds the last element from the Deck to the Player Hand Vector
	ptrPlayerHand->push_back(x);
	//Deletes the last element in the Deck as it is now in the Players Hand
	ptrDeckVec->pop_back();

}





void SetUp::addCardToComputerHand(){
	//Gets the last element in the Deck
	int x = ptrDeckVec->back();
	//Adds the last element from the Deck to the Computers Hand Vector
	ptrComputerHand->push_back(x);
	//Deletes the last element in the Deck as it is now in the Computers Hand
	ptrDeckVec->pop_back();

}







// Simple print function that uses an iterator to print out the Deck vector 
void SetUp::printDeck(){
	//Creates an iterator used to print the deck contents
	vector<int>::iterator iter;

	for (iter = ptrDeckVec->begin(); iter != ptrDeckVec->end(); ++iter){
		cout << *iter << endl;
	}
}





void SetUp::printPlayerHand(){
	//Creates an iterator used to print the deck contents
	vector<int>::iterator iter;

	for (iter = ptrPlayerHand->begin(); iter != ptrPlayerHand->end(); ++iter){
		cout << *iter << endl;
	}
}





void SetUp::printComputerHand(){
	//Creates an iterator used to print the deck contents
	vector<int>::iterator iter;

	for (iter = ptrComputerHand->begin(); iter != ptrComputerHand->end(); ++iter){
		cout << *iter << endl;
	}
}

//This method finds the least playable number for increasing piles

int SetUp::finding1_100Dif(int num){
	vector<int>::iterator iter;
	int bestDif = 100;
	for (iter = ptrComputerHand->begin(); iter != ptrComputerHand->end(); ++iter){
		//Temporary temp difference value gotten for each element
		int temp;
		//Checking that the temp difference is only valid if the element number is greater than the pile number for piles 1-100
		if (*iter < num){
			//Given stupid high difference so it is never chosen
			temp = 1000000;
		}
		else {
			//temp gotten by subtracting the iter number from the pile number
			int temp = *iter - num;
			//Gets the least difference
			if (temp < bestDif){
				bestDif = temp;
			}
		}
		
	}
	return bestDif;
}


//This method finds the greatest playable number for decreasing piles
int SetUp::finding100_1Dif(int num){
	vector<int>::iterator iter;
	int bestDif = 100;
	for (iter = ptrComputerHand->begin(); iter != ptrComputerHand->end(); ++iter){
		//Temporary temp difference value gotten for each element
		int temp;
		//Checking that the temp difference is only valid if the element number is greater than the pile number for piles 1-100
		if (*iter > num){
			//Given stupid high difference so it is never chosen
			temp = 1000000;
		}
		else {
			//temp gotten by subtracting the iter number from the pile number
			int temp = num - *iter;
			//Gets the least difference
			if (temp < bestDif){
				bestDif = temp;
			}
		}

	}
	return bestDif;
}


void SetUp::computerGo(){
	vector<int>::iterator iter;
	int pile1 = ptrIncreasingPile1->back();
	int pile2 = ptrIncreasingPile2->back();
	int pile3 = ptrDecreasingPile1->back();
	int pile4 = ptrDecreasingPile2->back();

	//Loop through the computers hand
	for (iter = ptrComputerHand->begin(); iter != ptrComputerHand->end(); ++iter){
		//Best case is rule of 10. Check for rule of 10 for the piles
		if (*iter == pile1 - 10){
			int cardNum = *iter;
			//Inserts the card into pile 1
			ptrIncreasingPile1->push_back(cardNum);
			cout << " I played " << cardNum << " in the increasing pile 1" << endl;
			//Removes the card from the computers hand and adds a new card
			removeFromComputerHand(cardNum);
		}
		else if (*iter == pile2 - 10){
			int cardNum = *iter;
			//Inserts the card into pile 1
			ptrIncreasingPile2->push_back(cardNum);
			cout << " I played " << cardNum << " in the increasing pile 2" << endl;
			//Removes the card from the computers hand and adds a new card
			removeFromComputerHand(cardNum);
		}
		else if (*iter == pile3 + 10){
			int cardNum = *iter;
			//Inserts the card into pile 1
			ptrDecreasingPile1->push_back(cardNum);
			cout << " I played " << cardNum << " in the decreasing pile 1" << endl;
			//Removes the card from the computers hand and adds a new card
			removeFromComputerHand(cardNum);
		}
		else if (*iter == pile4 + 10){
			int cardNum = *iter;
			//Inserts the card into pile 1
			ptrDecreasingPile2->push_back(cardNum);
			cout << " I played " << cardNum << " in the decreasing pile 2" << endl;
			//Removes the card from the computers hand and adds a new card
			removeFromComputerHand(cardNum);
		}
		else{
			//Get the best differences for each pile
			int bestCase = 100;
			int temp1 = finding1_100Dif(pile1);
			cout << temp1 << endl;
			int temp2 = finding1_100Dif(pile2);
			cout << temp2 << endl;
			int temp3 = finding100_1Dif(pile3);
			cout << temp3 << endl;
			int temp4 = finding100_1Dif(pile4);

			//Calculating the best difference from the 4 options
			if (temp1 < bestCase){
				bestCase = temp1;
				if (temp2 < bestCase){
					bestCase = temp2;
					if (temp3 < bestCase){
						bestCase = temp3;
						if (temp4 < bestCase){
							bestCase = temp4;
						}
					}
				}
			}
			cout << " The best possible difference is " << bestCase << endl;

			//Using best difference I can now find the number that matches and play that number. Finally!
			//Best case - current *iter value == pile 1
			if (bestCase - *iter == pile1){
				//Put the *iter value into the pile1
				ptrIncreasingPile1->push_back(*iter);
				//Remove it from it's hand
				removeFromComputerHand(*iter);
			}
			if (bestCase - *iter == pile2){
				//Put the *iter value into the pile2
				ptrIncreasingPile2->push_back(*iter);
				//Remove it from it's hand
				removeFromComputerHand(*iter);

			}
			if (bestCase + *iter == pile3){
				//Put the *iter value into the pile3
				ptrDecreasingPile1->push_back(*iter);
				//Remove it from it's hand
				removeFromComputerHand(*iter);
			}
			if (bestCase + *iter == pile4){
				//Put the *iter value into the pile3
				ptrDecreasingPile2->push_back(*iter);
				//Remove it from it's hand
				removeFromComputerHand(*iter);
			}

			if (bestCase == 100){
				cout << " I'm afraid it's game over " << endl;
				
			}
		}
	}


}




void SetUp::printVectorsCurrentStatus(){
	cout << " [1] = Pile 1-100  Status: " << ptrIncreasingPile1->back() << endl;
	cout << " [2] = Pile 1-100  Status: " << ptrIncreasingPile2->back() << endl;
	cout << " [3] = Pile 100-1  Status: " << ptrDecreasingPile1->back() << endl;
	cout << " [4] = Pile 100-1  Status: " << ptrDecreasingPile2->back() << endl;

}





void SetUp::removeFromPlayerHand(int cardNum){
	ptrPlayerHand->erase(remove(ptrPlayerHand->begin(), ptrPlayerHand->end(), cardNum), ptrPlayerHand->end());
	//printPlayerHand();

	addCardToPlayerHand();
}







void SetUp::removeFromComputerHand(int cardNum){
	ptrComputerHand->erase(remove(ptrComputerHand->begin(), ptrComputerHand->end(), cardNum), ptrComputerHand->end());
	//printComputerHand();

	addCardToPlayerHand();
}










void SetUp::playPlayerCard(int cardNum){
	//Check if card Number is in the players Hand
	const vector<int>::iterator iter = find(ptrPlayerHand->begin(), ptrPlayerHand->end(), cardNum);
	if (iter == ptrPlayerHand->end()){
		cout << " The Number can't be found ";
	}
	else {

		//Next select what card Pile to place the card in
		cout << " Where do you want to place the card " << cardNum << endl;
		//This prints the 4 piles status showing the user what number equates to what pile
		printVectorsCurrentStatus();
		int input;
		cin >> input;
		cout << " You chose option " << input << endl;


		const int cardNum = *iter;

			if (input == 1){
				//Gets the last element in the pile
				int x = ptrIncreasingPile1->back();
				cout << " The pile you selected is NUMBER 1" << endl;

				//Needs to be greater than the pile
				cout << cardNum << endl;
				//Checks for a vald move and checks for the rule of ten
				if ((cardNum > x) || ((x - 10) == cardNum)){
					cout << " This is a valid move " << endl;
					ptrIncreasingPile1->push_back(cardNum);
					cout << " You played " << cardNum << " in the increasing pile 1" << endl;
					removeFromPlayerHand(cardNum);
				}
				else cout << " Sorry but this isn't a valid move " << endl;
			}
			
			if (input == 2){
				//Gets the last element in the pile
				int x = ptrIncreasingPile2->back();
				//Needs to be greater than the pile
				if ((cardNum > x) || ((x - 10) == cardNum)){
					ptrIncreasingPile2->push_back(cardNum);
					cout << " You played " << cardNum << " in the increasing pile 2" << endl;
					removeFromPlayerHand(cardNum);
				}
				else cout << " Sorry but this isn't a valid move " << endl;
			}
			
			if (input == 3){
				//Gets the last element in the pile
				int x = ptrDecreasingPile1->back();
				//Needs to be less than the number in the pile
				if ((cardNum < x) || ((x + 10) == cardNum)){
					ptrDecreasingPile1->push_back(cardNum);
					cout << " You played " << cardNum << " in the decreasing pile 1" << endl;
					removeFromPlayerHand(cardNum);
				}
				else cout << " Sorry but this isn't a valid move " << endl;
			}
			
			if (input == 4){
				//Gets the last element in the pile
				int x = ptrDecreasingPile2->back();
				//Needs to be less than the number in the pile
				if ((cardNum < x) || ((x + 10) == cardNum)){
					ptrDecreasingPile2->push_back(cardNum);
					cout << " You played " << cardNum << " in the decreasing pile 2" << endl;
					removeFromPlayerHand(cardNum);
				}
				else cout << " Sorry but this isn't a valid move " << endl;
			}
	}
}





