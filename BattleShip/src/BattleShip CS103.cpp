//============================================================================
// Name	 : JTRAN.cpp
// Author   :
// Version  :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;

void GenerateGrid(vector<vector<char> >& ,int x,int y);
void DisplayGrid(const vector<vector<char> >& );
void ShipPlacement(vector<vector<char> >& , int len, char t);
int Getcol(vector<char>&,char temp_input );
void PrintTop(vector<vector<char> >& );
void Printtext_one(vector<vector<char> >& );
void Printtext_two(vector<vector<char> >& );


int main() {
 srand(time(0));
   vector< vector<char> >grid;
   vector< vector<char> >usergrid;
   vector< vector<char> >cheatgrid;

   int x=0;
   int y=0;
   cout<<"Mininum size: product of row x col must be greater than equal to 30."<<endl;
   cout<<"Enter rows: ";
   cin>>y;
   cout<<"Enter columns: ";
   cin>>x;

   while(!(x*y>=30)){
	   cout<<"Mininum size: product of row x col must be greater than equal to 30."<<endl;

	   cout<<"Enter rows: ";
	   cin>>y;
	   cout<<"Enter columns: ";
	   cin>>x;


   }



   GenerateGrid(grid,y,x);
   GenerateGrid(usergrid,y,x);
   int Carrier = 5;
   int Battleship = 5;
   int Frigate = 3;
   int Submarine = 3;
   int Minesweeper = 2;
   int random = rand()%5;

   char C = 'C';
   char B = 'B';
   char F = 'F';
   char S = 'S';
   char M = 'M';

//Randomly picks which ships will be placed first on the grid.
   vector<int>ran;
for(int i = 0; i < 5; i++){
	random=rand()%5;
	for(int j = 0 ; j < ran.size();j++){
		if(random==ran[j]){
			random=rand()%5;
			j=-1;
		}
	}
	ran.push_back(random);
 	if(ran[i]==0){
		ShipPlacement(grid,Carrier,C);
	}
	if(ran[i]==1){
		ShipPlacement(grid,Battleship,B);
	}
	if(ran[i]==2){
		ShipPlacement(grid,Frigate,F);
	}
	if(ran[i]==3){
		ShipPlacement(grid,Submarine,S);
	}
	if(ran[i]==4){
		ShipPlacement(grid,Minesweeper,M);
	}
}
//Hidden grid for lost game and cheating.
cheatgrid = grid;


//This vector below will be used for getting the x points. It will allow us to
//match the letters with the what the grid is showing the user.
	vector<char>Top_row;
 	char Alpha = 'A';

   	for(int i = 0; i < grid[0].size(); i++){
     		Top_row.push_back(Alpha);
     		Alpha++;
   	}
   	cout<<endl;

    int guesses= 0 ;
    int maxGuesses = 0;
    int totalships = 0;
    maxGuesses = (x*y)/2+5;


   	cout<<"Welcome to Battleship"<<endl;
   	cout<<"You have "<<maxGuesses<<" guesses to find"<<endl;
   	cout<<"\tOne Carrier of length 5"<<endl;
   	cout<<"\tOne Battleship of length 5"<<endl;
   	cout<<"\tOne Frigate of length 3"<<endl;
   	cout<<"\tOne Submarine of length 3"<<endl;
   	cout<<"\tOne Minesweeper of length 2"<<endl;


	PrintTop(grid);
	DisplayGrid(usergrid);

//Where the game starts looping based on guesses or ships sunk..
while(guesses !=maxGuesses){
	char user_input;

	bool col = true;
	bool row = true;
	//Checks to see if the user entered the correct Letter by searching the vector. top_row...
	Printtext_one(grid);
	while(!isalpha(user_input)||islower(user_input)||col){
		cin>>user_input;
		col=true;
		for(int i = 0  ; i < Top_row.size(); i ++){
			if(user_input == Top_row[i]){
				col = false;
			}
		}
		//CHEAT ENTER ? when ask for column...
		if(user_input=='?'){
			PrintTop(grid);
			DisplayGrid(cheatgrid);
		}
		if(col == true){
			Printtext_one(grid);
		}
	}

	//The function below will help watch the letters with the column correctly.
	int userx = Getcol(Top_row,user_input);
	int usery = 0;

	Printtext_two(grid);
	cin>>usery;

	//Checks the row numbers makes sure its within normal bounds...
	while(usery<0 ||usery>grid.size())
		{
			Printtext_two(grid);
			cin>>usery;

		}

	//I used two different vectors to one for keeping tracks of repeating hits and one for displaying the user board.
	//The hidden one will get each dot replaced with an H for hit and the user board with get the correct display.
	//The ships are track by its length hit and guesses also.
	if(grid[usery-1][userx]=='H'){
		cout<<"\n"<<user_input<<usery<<" has already bombed"<<endl;
	}
	if(grid[usery-1][userx]=='.'){
		grid[usery-1][userx]='H';
		usergrid[usery-1][userx]='x';
		guesses++;
	}
	if(grid[usery-1][userx]=='C'){
		grid[usery-1][userx]='H';
		usergrid[usery-1][userx]='C';
		guesses++;
		Carrier--;
		totalships++;
		if(Carrier==0){
			cout<<endl;
			cout<<"You have sunk the Carrier"<<endl;
		}
	}
	if(grid[usery-1][userx]=='B'){
		grid[usery-1][userx]='H';
		usergrid[usery-1][userx]='B';
		guesses++;
		Battleship--;
		totalships++;
		if(Battleship==0){
			cout<<"\nYou have sunk the Battleship"<<endl;
		}
	}
	if(grid[usery-1][userx]=='F'){
		grid[usery-1][userx]='H';
		usergrid[usery-1][userx]='F';
		guesses++;
		Frigate--;
		totalships++;
		if(Frigate==0){
			cout<<"\nYou have sunk the Frigate"<<endl;
		}
	}
	if(grid[usery-1][userx]=='S'){
		grid[usery-1][userx]='H';
		usergrid[usery-1][userx]='S';
		guesses++;
		Submarine--;
		totalships++;
		if(Submarine==0){
			cout<<"\nYou have sunk the Submarine"<<endl;
		}
	}
	if(grid[usery-1][userx]=='M'){
		grid[usery-1][userx]='H';
		usergrid[usery-1][userx]='M';
		guesses++;
		Minesweeper--;
		totalships++;
		if(Minesweeper==0){
			cout<<"\nYou have sunk the Minesweeper"<<endl;
		}
	}
	//checks if you won
	if(totalships==18){
	break;
	}
	cout<<endl;
	cout<<"guess="<<guesses<<endl;
	PrintTop(grid);
	DisplayGrid(usergrid);
}

if(guesses==maxGuesses){
	cout<<"You used up all your guesses"<<endl;
	cout<<"Here is where all of the ships were deployed:"<<endl;
	DisplayGrid(cheatgrid);
}
if(totalships==18){
	cout<<"You sunk all the ships"<<endl;
}

}
//Generates the grid.
void GenerateGrid(vector<vector<char> >& newVector,int y,int x){
 for(int i = 0; i <y; i++){
  vector<char>dummy;
  for(int j = 0 ; j<x; j++){
   dummy.push_back('.');
  }
  newVector.push_back(dummy);
 }
}
//Prints out the top border of the board (A-?)
void PrintTop(vector<vector<char> >& newVector){
	char tempAlpha = 'A';
cout<<"\n";
   	for(int i = 0; i < newVector[0].size(); i++){
   		if(i==0){

   			cout<<"  "<<tempAlpha;
   		}
		if(i>0){
			cout<<" "<<tempAlpha;
		}
		tempAlpha++;
   	}
   	cout<<endl;
}
//Prints the board for user's eyes only.
void DisplayGrid(const vector<vector<char> >& newVector){
	  for(int i = 0 ; i < newVector.size(); i++){
		  cout<<i+1<<" ";
	  	 for(int j = 0 ; j < newVector[i].size();j++ ){
	     	 cout<<newVector[i][j]<<" ";
	  	 }
	  	 cout<<endl;
	   }
}
//Prints text for the user to enter. "col(A-?)"
void Printtext_one(vector<vector<char> >& newVector){
	char tempAlpha = 'A';
	cout<<"Enter col(";

   	for(int i = 0; i < newVector[0].size(); i++){
   		if(i==0){
   			cout<<""<<tempAlpha;
   		}
   		if(i==newVector[0].size()-1){
   			cout<<"-"<<tempAlpha;
   		}
		tempAlpha++;
   	}
   	cout<<"):";
}
//Prints text for the user to enter. "row(1-?)"
void Printtext_two(vector<vector<char> >& newVector){
	cout<<"Enter row(";
	for(int i = 0 ;  i < newVector.size(); i++){
		if(i==0){
			cout<<i+1<<"-";
		}
		if(i==newVector.size()-1){
			cout<<i+1<<"):";
		}
	}
}
//This function matches the letters with the corresponding columns. Push back all the letters into
//a vector and since the indexes start from zero to whatever. You mainly just need the index of each letter.
int Getcol(vector<char>& newVetor,char temp_input){
 	int tempx = 0;
   	for(int i = 0; i<newVetor.size();i++){
   		if(temp_input == newVetor[i]){
   			tempx=i;
   		}
   	}
   	return tempx;
}
//This generates the poistion of the ships. First it picks a random number for Direction.
//1 for horizontal to 4 for diagonal...
void ShipPlacement(vector<vector<char> >& newVector, int len, char t){
 int cleared = 0;
 int net = 0;
	while(net!=1){
		int ran = rand()%4;
		cleared=0;
		//Horizontal  adds the x values by i according to length of the ship -
		if(ran==0){
 			int gridLength = newVector[0].size();
			int ranx = rand()%newVector[0].size();
			int rany = rand()%newVector.size();
 				if(ranx+len<=gridLength){
					for(int i = 0 ; i < len; i++){
						if(newVector[rany][ranx+i]!='.'){
							cleared++;
						}
					}
					if(cleared==0){
						for(int j =0; j<len; j++){
							newVector[rany][ranx+j]=t;
							net=1;
						}
					}
				}
		}
		//Vertical adds the y values by i  |
		if(ran==1){
			int gridLength = newVector.size();
			int ranx = rand()%newVector[0].size();
			int rany = rand()%newVector.size();
 				if(rany+len<=gridLength){
					for(int i = 0 ; i < len; i++){
						if(newVector[rany+i][ranx]!='.'){
							cleared++;
						}
					}
					if(cleared==0){
						for(int j =0; j<len; j++){
							newVector[rany+j][ranx]=t;
							net=1;
						}
					}
				}
		}
		//Diagonal adds x and y by i according to the length of the ship. (\)
		if(ran==2){
			int ranx = rand()%newVector[0].size();
			int rany = rand()%newVector.size();
  				if(ranx+len<=newVector[0].size()&&rany+len<=newVector.size()){
					for(int i = 0 ; i < len; i++){
						if(newVector[rany+i][ranx+i]!='.'){
							cleared++;
						}
						//This checks to make sure both diagonal lines dont intersect.
						if(rany-1>=0&&ranx+1<newVector[0].size()){
							if(newVector[rany+1][ranx]!='.'){
							 cleared++;
							 }
						}
					}
						if(cleared==0){
							for(int j =0; j<len; j++){
								newVector[rany+j][ranx+j]=t;
								net=1;
							}
						}
				}
		}
		//Diagonal minuses i from x and adds i to y according to the length of the ship. /
		if(ran==3){
			int ranx = rand()%newVector[0].size();
			int rany = rand()%newVector.size();
 				if(ranx-(len-1)>=0){
					if(rany+len<=newVector.size()){
						for(int i = 0 ; i < len; i++){
							if(newVector[rany+i][ranx-i]!='.'){
							 cleared++;
							 }
							//This checks to make sure both diagonal lines dont intersect.
							if(rany-1>=0&&ranx+1<newVector[0].size()){
								if(newVector[rany-1][ranx]!='.'){
								 cleared++;
								 }
							}
						}
						if(cleared==0){
							for(int j =0; j<len; j++){
							newVector[rany+j][ranx-j]=t;
							net=1;

							}
						}
					 }
			 }
		}
	}
}

