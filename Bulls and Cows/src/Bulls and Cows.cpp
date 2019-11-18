//Jonathan Tran CS 103 Assignment 2 3/13/17

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <time.h>
using namespace std;


int main()
{
	int start_timer = clock();
    int tries=0;
	srand(time(0));
    int guess = 0;
    bool game_over = true;
    vector<int>numbers;
    vector<int>unique_num;
    //Determines the random unique values.
    for(int i = 0; i < 4; i++){
        int random=rand()%9;
        for(int j = 0; j<numbers.size(); j ++){
            if(random==numbers[j])
            {
              random=rand()%9;
          	  j=-1;
            }
        }
        numbers.push_back(random);
        cout<<numbers[i];
    }
   //After 4 unique values are chosen. The code to start the game will run.
   while(game_over){
		cout<<"\nEnter a 4 digit number(unique digits): ";
    	cin>>guess;
    	while(guess<=0 || guess>9999)
    	{
    		cout<<"\nEnter a 4 digit number(unique digits): ";
    		cin>>guess;
        }
    		//If the check for repeating numbers fail this will reset the vector in the loop.
            unique_num.clear();
        	unique_num.push_back(guess/1000);
        	unique_num.push_back((guess/100)%10);
        	unique_num.push_back((guess/10)%10);
        	unique_num.push_back(guess%10);
        	//Checks for repeating input vales.
        	int repeat=0;
            for(int i = 0; i < unique_num.size(); i++)
                {
                    for(int j = 0; j<unique_num.size(); j ++)
                    {
                        if(unique_num[i]==unique_num[j]&& i!=j){
                            repeat++;}
                        if(unique_num[i]==unique_num[j]&& i!=j){
                            repeat++;}
                    }
        	    }
            //If no repeating values are detected. The code below will execute.
            if(repeat==0){
            //To reset the bulls and cows count in the loop.
            int bulls=0;
            int cows=0;
            tries++;
        	//This will check for repeating values bulls and cows.
        		for(int i = 0;i<unique_num.size();i++)
        		{
        			for(int j =0;j<numbers.size();j++)
        			{
        				if(unique_num[i]==numbers[j] && j==i){bulls++;}
        				if(unique_num[i]==numbers[j] && j!=i){cows++;}
        			}
        		}
        		if(bulls!=4){
        			cout<<"bulls = "<<bulls<<" cows = "<<cows<<endl;
                	}
                	else if(bulls==4){
                		cout<<"bulls = "<<bulls<<" cows = "<<cows<<endl;
                		cout<<"You guessed it in "<<tries<<" tries,";
                		game_over=false;
                	}
            }
   	   }
   //This is the timer. Use the difference to calculate time.
   int stop_timer = clock();
   int time_diff = (stop_timer - start_timer)/1000;
   if(time_diff>60){
	    cout<<" taking "<<time_diff/60<<" minutes "<<"and "<<time_diff%60<<" seconds"<<endl;
   	   }else{
   		   cout<<" taking "<<time_diff <<" seconds"<<endl;}
}
