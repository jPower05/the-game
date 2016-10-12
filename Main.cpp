#include "SetUp.h"
using namespace std;
int move;
bool gameOver = false;
bool win = false;
int cardsToAdd = 0;





int main(){
	bool gameOver = false;
	bool win = false;
	int move = 1;
	int minMovesToMake = 2;
	SetUp *pSetUp = new SetUp;
	cout << " Welcome to the Game " << endl;
	
	while (gameOver == false && win == false){
		if ((move % 2) == 0){

			//Computers Go
			cout << " It's my go now " << endl;
			for (int i = 0; i < 1; ++i){
				cout << " Let's see how this goes " << endl;
				pSetUp->computerGo();
			}
			move++;
			
			
			


		}

		else {
			//Player Go
			cout << "It's your turn now " << endl;
			cout << " You have  to make at least make " << minMovesToMake << " moves before you can end your turn " << endl;
			cout << " What do you want to do " << endl;
			cout << "---------------------------------------------------------------------- " << endl;
			cout << " 1 = See the current pile status " << endl;
			cout << " 2 = Show the contents of your hand " << endl;
			cout << " 3 = Play a card " << endl;
			cout << " 4 = End turn " << endl;
			cout << " 5 = Admit defeat " << endl;
			int input;
			cin >> input;


			if (input == 1){
				pSetUp->printVectorsCurrentStatus();
			}

			if (input == 2){
				cout << " Printing PlayerHand  " << endl;
				pSetUp->printPlayerHand();
			}
			if (input == 3){
				cout << " What card do you want to play. Please type the number you wish to place down " << endl;
				int input;
				cin >> input;
				cout << " The entered number is  " << input << endl;
				pSetUp->playPlayerCard(input);
				minMovesToMake--;

			}
			if (input == 4){
				cout << "Ending turn " << endl;
				if (minMovesToMake = 0){
					++move;
				}
				else{
					cout << " You need to make at least " << minMovesToMake << " more moves before you can end your turn " << endl;
					cout << " If this is not possible please admitt defeat " << endl;
				}
			}
			if (input == 5){
				cout << " Well that's a pity " << endl;
				cout << " You lose! " << endl;
				gameOver = true;
			}
		}
	}

		
}