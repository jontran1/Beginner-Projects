#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
#include <ctime>

using namespace std;

struct Cards{
	char suite;
	string rank;
}temp;

void BuildDeck( vector<Cards >& );
void DisplayCards(const vector<Cards >& );
void DealsCard(vector<Cards >&, vector<Cards>&);
void Printhand(const vector<Cards >& );
int getPick (vector<char>& , char temp);
void swapplayer (vector<Cards >&, vector<Cards >& , int temp);
char KeepCards (vector<Cards>& );
void swapNPC (vector<Cards >&, vector<Cards >& , char temp);
void cheat (vector<Cards >&);
bool CheckHand (vector<Cards >&, vector<Cards >& , vector<Cards >& ,vector<Cards >& ,vector<Cards >&);

int main(){
	srand(time(0));
 	vector<Cards>Deck;
	vector<Cards>Player0;
	vector<Cards>Player1;
	vector<Cards>Player2;
	vector<Cards>Player3;
	vector<Cards>Player4;
	vector<char>picklist;
	picklist.push_back('a');
	picklist.push_back('b');
	picklist.push_back('c');
	picklist.push_back('d');
	picklist.push_back('e');
	picklist.push_back('f');
	picklist.push_back('g');
//BuildsDeck
	BuildDeck(Deck);
	random_shuffle(Deck.begin(), Deck.end());
//Deals Cards
	DealsCard(Deck,Player0);
  	DealsCard(Deck,Player1);
	DealsCard(Deck,Player2);
	DealsCard(Deck,Player3);
	DealsCard(Deck,Player4);
	bool game_over = true;


 	while(game_over){
		int checkpick = 0;
		Printhand(Player0);
		char pick;
		cout<<"Which one to replace? ";
		cin>>pick;
//Check users input....
		while(!isalpha(pick)){
 			if(pick == '?'){
				cout<<"Player 1";cheat(Player1);
				cout<<"Player 2";cheat(Player2);
				cout<<"Player 3";cheat(Player3);
				cout<<"Player 4";cheat(Player4);

 			}
 			for(int i = 0 ; i < picklist.size();i++){
 				if(pick==picklist[i]){
 					break;
 				}
 			}
 			cout<<"Which one to replace? ";
 			cin>>pick;
		}



//Matches my pick with the vector in the player's hand. a == 0, b == 1, etc....
		int PicksLetter = 0;
		PicksLetter = getPick(picklist, pick);

		cout<<"Hint: player 0 passed ";
		swapplayer (Player0,Player1,PicksLetter);
		cout<<" to player 1"<<endl;

		char temp = KeepCards(Player1);
		cout<<"Hint: player 1 passed ";
		swapNPC(Player1, Player2, temp);
		cout<<" to player 2"<<endl;

		char temp1 = KeepCards(Player2);
		cout<<"Hint: player 2 passed ";
		swapNPC(Player2, Player3, temp1);
		cout<<" to player 3"<<endl;

		char temp2 = KeepCards(Player3);
		cout<<"Hint: player 3 passed ";
		swapNPC(Player3, Player4, temp2);
		cout<<" to player 4"<<endl;

		char temp3 = KeepCards(Player4);
		cout<<"Hint: player 4 passed ";
		swapNPC(Player4, Player0, temp3);
		cout<<" to player 0"<<endl;

 		if(CheckHand(Player0,Player1,Player2,Player3,Player4)==0){
 			game_over = false;
 		}
	}
 	cout<<"[ Final card distributions ]"<<endl;
	cout<<"Player 1";cheat(Player1);
	cout<<"Player 2";cheat(Player2);
	cout<<"Player 3";cheat(Player3);
	cout<<"Player 4";cheat(Player4);
}
//Cheating Screen
void cheat (vector<Cards >& vect){
	char Alpha = 'a';
 	for(int i = 0 ; i < vect.size() ; i ++){
		cout<<"("<<Alpha<<") "<<vect.at(i).suite<<""<<vect.at(i).rank<<" ";
		Alpha ++;
		}
	cout<<endl;
}
//For testing purposes to display Cards.
void DisplayCards(const vector<Cards >& vect ){
	for(int i = 0 ; i < vect.size(); i ++){
		cout<<vect.at(i).suite<<""<<vect.at(i).rank<<" ";
	}
}
//Deals the first vector element to each player and eraces it from that vector.
void DealsCard(vector<Cards >& vect, vector<Cards>& vect_t){
	for(int i = 0 ; i < 7 ; i++){
		vect_t.push_back(vect[0]);
		vect.erase (vect.begin()+0);
	}
}
void Printhand(const vector<Cards >& vect){
	char Alpha = 'a';
	cout<<endl;
	for(int i = 0 ; i < vect.size() ; i ++){
		cout<<"("<<Alpha<<") "<<vect.at(i).suite<<""<<vect.at(i).rank<<" ";
		Alpha ++;
		}
	cout<<endl;
	}
//This will match the letter the player picks with the element of the vector.
int getPick (vector<char>& vect, char temp){
	int num = 0;
	for(int i = 0 ; i < vect.size(); i ++){
		if(temp == vect[i]){
			num=i;
		}
	}
	return num;
}
//Swapps the human card to the next player.
void swapplayer (vector<Cards >& vect, vector<Cards >& vect_t, int temp){
	vect_t.push_back(vect[temp]);
	cout<<vect.at(temp).suite<<""<<vect.at(temp).rank;
	vect.erase (vect.begin()+temp);
}
//This will pick which card to keep. It counts the highest repeating sutie.
char KeepCards (vector<Cards>& vect){
	int countS=0;
	int countH=0;
	int countD=0;
	int countC=0;
	char temp;
 	for(int i = 0 ; i < vect.size(); i++){
		if(vect[i].suite == 'S'){
		countS++;
		}
		if(vect[i].suite == 'H'){
		countH++;
		}
		if(vect[i].suite == 'D'){
		countD++;
		}
		if(vect[i].suite == 'C'){
		countC++;
		}
	}
	if(countS>=countH && countS>=countD && countS>=countC ){
		temp ='S';
	}
	if(countH>=countS && countH>=countD && countH>=countC ){
		temp ='H';
	}
	if(countD>=countS && countD>=countD && countD>=countC ){
		temp ='D';
	}
	if(countC>=countS && countC>=countD && countC>=countH ){
		temp ='C';
	}
//	if(countS==countH && countS==countD && countS ==countC){
	//	temp ='S';
	//}
 	return temp;
}
//Swaps the nonHighest suite, which will be the lowest.
void swapNPC (vector<Cards >& vect, vector<Cards >& vect_t, char temp){
	for(int i = 0 ; i < vect.size();i++){
		if(vect.at(i).suite!=temp){
			vect_t.push_back(vect[i]);
			cout<<vect.at(i).suite<<""<<vect.at(i).rank;
			vect.erase (vect.begin()+i);
			break;
		}
	}
}
//Checks for winner.
bool CheckHand (vector<Cards >& vect0, vector<Cards >& vect1 , vector<Cards >& vect2, vector<Cards >& vect3, vector<Cards >& vect4){
	bool test = true;
	int temp = 0;
	int temp1 = 0;
	int temp2 = 0;
	int temp3 = 0;
	int temp4 = 0;

	for(int i = 0 ; i < vect0.size(); i ++){
		if(vect0.at(0).suite==vect0.at(i).suite){
			temp ++;
 		}
		if(vect1.at(0).suite==vect1.at(i).suite){
			temp1 ++;
		}
		if(vect2.at(0).suite==vect2.at(i).suite){
			temp2 ++;
		}
		if(vect3.at(0).suite==vect3.at(i).suite){
			temp3 ++;
		}
		if(vect4.at(0).suite==vect4.at(i).suite){
			temp4 ++;
		}
	}
	if(temp==7){
		cout<<"My Ship Sails! --- Player 0 Won..."<<endl;
		test=false;
	}
	if(temp1==7){
		cout<<"My Ship Sails! --- Player 1 Won..."<<endl;
		test=false;
	}
	if(temp2==7){
		cout<<"My Ship Sails! --- Player 2 Won..."<<endl;
		test=false;
	}
	if(temp3==7){
		cout<<"My Ship Sails! --- Player 3 Won..."<<endl;
		test=false;
	}
	if(temp4==7){
		cout<<"My Ship Sails! --- Player 4 Won..."<<endl;
		test=false;
	}
 	return test;
}
void BuildDeck( vector<Cards >& vect){
struct Cards temprank;
struct Cards tempsuite;
	for(int i = 0 ; i < 52; i ++){
		if(i < 13){
		tempsuite.suite = 'S';
		}
		if(i>=13 && i < 26){
		tempsuite.suite = 'H';
		}
		if(i>=26&&i<39){
		tempsuite.suite = 'C';
		}
		if(i>=39 && i < 52){
		tempsuite.suite = 'D';
		}
		if(i%13==0){
		temprank.rank = "A";
		}
		if(i%13==1){
		temprank.rank = "2";
		}
		if(i%13==2){
		temprank.rank = "3";
		}
		if(i%13==3){
		temprank.rank = "4";
		}
		if(i%13==4){
		temprank.rank = "5";
		}
		if(i%13==5){
		temprank.rank = "6";
		}
		if(i%13==6){
		temprank.rank = "7";
		}
		if(i%13==7){
		temprank.rank= "8";
		}
		if(i%13==8){
		temprank.rank = "9";
		}
		if(i%13==9){
		temprank.rank = "10";
		}
		if(i%13==10){
		temprank.rank = "J";
		}
		if(i%13==11){
		temprank.rank = "Q";
		}
		if(i%13==12){
		temprank.rank = "K";
		}
		vect.push_back(Cards {tempsuite.suite,temprank.rank});
	}
}
