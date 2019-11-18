#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <time.h>
using namespace std;

//Generate random String.
string generate(const int length){
	srand(time(0));
	string ran_out;
	string letter;
	string s ="";
	for(int i = 0; i<length; i++){
		int ran_num = rand()%10;
		if(ran_num<8){
			letter='A'+ rand()%26;
		}
		if(ran_num < 4){
			letter='a'+rand()%26;
		}
		if(ran_num ==8){
			letter = "0";
		}
		if(ran_num ==9){
			letter = "*";
		}
		s+=letter;
	}
	return s;
}

//Create a Display String for the User to see.
string DisplayStr(string temp){
    string newStr ="";
    for(int i = 0; i<5; i++){
        if(isdigit(temp[i])){
        newStr+="[0-9]";
        }
        if(!isalnum(temp[i])){
        	newStr+="[%-!]";
        }
        if(!isdigit(temp[i])&&isalnum(temp[i])){
        newStr+=temp[i];}

    }
    return newStr;

}

//Calculates the OffSet of the two Strings.
int getOffSet(string user_temp, string ran_temp){
	int tempset=0;
	string tempchar;
	for(int i = 0; i<user_temp.size();i++)
	{
		if(isalnum(user_temp[i])){
			if(ran_temp[i]=='*'){
			tempset += abs(user_temp[i]-ran_temp[i]);
			}
		}
		if(ran_temp[i]=='0'){
			if(!isdigit(user_temp[i])){
				tempset += abs(user_temp[i]-ran_temp[i]);
			}
		}
		if(isalpha(ran_temp[i])){
			if(user_temp[i]!=ran_temp[i]){
			tempset += abs(user_temp[i]-ran_temp[i]);
			}
		}
	}
	return tempset;
}


int main(){
	string myString;
	int player_balance = 2000;


	while(player_balance >0 && player_balance <5000){
		int start_timer = clock();
		int diff=0;
		//Generate a random string and generates an display string for the user.
		string ranString = generate(5);
		string outputStr = DisplayStr(ranString);


		cout<<"Your current points "<<player_balance<<", just type -> "<<outputStr<<": ";
		//Used getline function to account for white spaces in string.
		getline (cin,myString);
		//offset function.
		int offset = getOffSet(myString, ranString);


		if(offset==0){
			int stop_timer = clock();
			int time_diff = (stop_timer - start_timer);
				if(time_diff<=10000){
					player_balance+=500;
					cout<<time_diff<< " milliseconds, you made it within the interval of 10000..."<<endl;

				}else if(time_diff>10000){
					diff= time_diff-10000;
					player_balance -= diff;
					cout<<time_diff<< " milliseconds, you *failed* it within the interval of 10000..."<<endl;

				}
		}else if (offset!=0){

			int stop_timer = clock();
			int time_diff = (stop_timer - start_timer);
			if(time_diff<10000){
				player_balance -=offset;
				cout<<time_diff<< " milliseconds, you made it within the interval of 10000..."<<endl;
				cout<<"String offset is "<<offset<<", your total penalty is "<<offset<<"..."<<endl;

				}else if(time_diff>10000){
					diff=(offset+(time_diff-10000));
					player_balance -=diff;
					cout<<time_diff<< " milliseconds, you *failed* it within the interval of 10000..."<<endl;
					cout<<"String offset is "<<offset<<", your total penalty is "<<diff<<"..."<<endl;

				}


		}

	}
	cout<<"Bye.."<<endl;


}
