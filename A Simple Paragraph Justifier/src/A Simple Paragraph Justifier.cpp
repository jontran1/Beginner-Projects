 #include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
//#define EvenAdjust

using namespace std;

int main(){
	string text;
	vector<string>inputText;
	vector<string>displayText;
	int spacesTaken = 0;
	int totalTaken = 0;
	int totaldiff = 0;
	//Since spaces will always be i-1; I set the spaces to -1.
	int spaces = -1;
	int placeholder;
	cout<<"Enter text, empty return will quit the input"<<endl;
	cout<<"> ";
	int totallength = 25;
	bool game = true;

	//Reads anything that isn't a space. Places the letters into a string and then places the string of letters into
	//the vector. After that. It will clear the letters and continue to the next non-spaces.
	while(game)
	{
 		while(getline(cin,text)){
			string letters;
			cout<<"> ";
		if(text==""){break;}

			for(int i  = 0 , length = text.length(); i < length; i++ ){
				if(!isspace(text[i])){
					letters += text[i];
				}
				if ((isspace(text[i]) && !isspace(text[i-1]))){
					inputText.push_back(letters);
					letters.clear();
				}
				if(i==length-1){
					inputText.push_back(letters);
					letters.clear();
				}

			}
			for(int i = 0 ; i <inputText.size(); i ++){
				cout<<inputText[i]<<" ";
			}



		}
		//Enter the width(length). Entering a 0 will end the program.
		cout<<"Enter the width of text: ";
		cin>>totallength;
		while(totallength<=0){
			break;
		}
		if(totallength<=0){break;}
				//Print top border.
				for(int i= 0 ; i < totallength;i++){
					if(i==0){
						cout<<"|";
					}
					cout<<"-";
					if(i==totallength-1){
						cout<<"|"<<endl;
					}
				}
				//This nested for loop will adjust the text to the width.
				for (int i = 0; i< inputText.size(); i++)
				{
					//This will calculate the the set of words. {w1, w2,...wi}
					//Then w1.length()+w2.length()....
					//Spaces are set to have i-1. Just one space for each i-1 will be included in the calculations.
					//The total difference will be totaldiff. This is the difference between the width(length) and the
					//collection of words including spaces.
					spacesTaken += inputText[i].length();
					spaces++;
					totalTaken = spacesTaken+spaces;
					totaldiff= totallength-totalTaken;

					//If the (length- total spacesTaken up) is above a zero. This will run. This will continue to add words to the set until
					//The next word. If the word causes the difference to be below zero it will skip.
					if(totaldiff>=0){

						displayText.push_back(inputText[i]);
						//Only on the last iteration do we adjust the remaining words.
						//but when totaldiff < 0 iteration doesn't need to be on the last because there are still words to be added.
						//Add spaces according to i-1.
						if(i==inputText.size()-1){

							for(int j = 0; j <spaces; j++){
								displayText[j]+=" ";
							}
							//The totaldiff will be the number of spaces we need to fill in the width(length).
							while(totaldiff>0){
								if(spaces==0){
									for(int j = 0; j<totaldiff;j++){
									displayText[0]+=" ";
									totaldiff-=1;
									}
								}
								if(totaldiff>spaces||totaldiff==spaces){
									for(int j = 0 ; j < displayText.size()-1;j++){
										displayText[j]+=" ";
										totaldiff-=1;
									}
								}
//Even adjustment only needs to take into account
//for when there are more spaces then spaces we can give.
#ifndef EvenAdjust
								if(totaldiff<spaces && totaldiff!=0 ){
									displayText[i-1]+=" ";
									totaldiff-=1;
								}
#else
								if(totaldiff<spaces && totaldiff != 0 ){
									placeholder=totaldiff;
									for(int j = 0; j <placeholder; j++){
										displayText[j]+=" ";
										totaldiff-=1;
									}
								}
									placeholder = 0;
#endif
								}

								//Prints the set of words.
								for(int j = 0 , length=displayText.size(); j<length;j++){
									if(j==0){
										cout<<"|";
									}
									cout<<displayText[j];
									if(j==length-1){
										cout<<"|"<<endl;
									}
								}
								//This will clear the vector for re use We -1 from spaces because one word wasn't added.
								//Didn't minus 1 from "i" because it doesn't need to read the next word. Because it's difference is above 0.
								displayText.clear();
								spacesTaken = 0;
								spaces=-1;


						}
					}
					//If the total difference is below zero. As in over the width. Then the code will recalculate
					//spaces taken up by letters and included spaces. Code will minus the word that caused < 0 and it will -1 off spaces because it didn't add the last word.
					else if(totaldiff<0){
						spacesTaken -= inputText[i].length();
						spaces -=1;
						totalTaken = spacesTaken + spaces;
						totaldiff = totallength - totalTaken;
						//Add spaces. The spaces will be included in the calculations.
						for(int j = 0; j <spaces; j++){
							displayText[j]+=" ";
						}
						//Adjust the text by filling the difference with spaces.
						while(totaldiff>0){
							if(spaces==0){
								for(int j = 0; j<totaldiff;j++){
									displayText[0]+=" ";
									totaldiff-=1;
									}
								}

							if(totaldiff>spaces||totaldiff==spaces){
								for(int j = 0 ; j < displayText.size()-1;j++){
									displayText[j]+=" ";
									totaldiff-=1;
								}
							}

#ifndef EvenAdjust
							if(totaldiff<spaces && totaldiff!=0 ){
								displayText[spaces-1]+=" ";
								totaldiff-=1;
							}
#else
							if(totaldiff<spaces && totaldiff != 0 ){
								placeholder=totaldiff;
								for(int j = 0; j <placeholder; j++){
									displayText[j]+=" ";
									totaldiff-=1;
								}
							}
							placeholder = 0;
#endif
						}
						//Prints text out and resets the vector and calculations. Spaces -1 because the next word wasn't added.
						// "i" needed to be decreased by 1. To allow the program to continue to the next words. It will continue reading the text because the
						// calculations for spaces taken up was set to 0. Which will set the total to zero so it can continue reading till the difference is > 0 or < 0.
						for(int j = 0 , length =displayText.size();j<length;j++){
							if(j==0){
								cout<<"|";
							}
							cout<<displayText[j];
							if(j==length-1){
								cout<<"|"<<endl;
							}
						}
						displayText.clear();
						spacesTaken = 0;
						spaces=-1;
						i-=1;
					}

				}
				//Runs when codes finishes reading Text in for loop.
				//Prints bottom border.
				for(int i = 0; i < totallength; i++){
					if(i==0){
						cout<<"|";
					}
					cout<<"-";
					if(i==totallength-1){
						cout<<"|"<<endl;
					}
				}
	}
 }
