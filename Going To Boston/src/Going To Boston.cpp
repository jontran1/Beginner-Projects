#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <cstdlib>
using namespace std;
#define AUTOBET

int main()
{

    srand(time(0));
	int bet = 0;
	int player_balance = 1000;
	int machine_balance = 1000;

    int largest = 0;
    int largest_two = 0;
    int pc_largest = 0;
    int pc_largest_two = 0;

    int total_human_score = 0;
    int total_machine_score = 0;
    int difference = 0;
    int rounds = 1;

    bool bigfish_player = true;
    bool bigfish_machine = true;


    while(!(player_balance <0 || machine_balance <0))
    {
    	//Dice_one - three and machine_one - three are the dices
    	int dice_one = rand()%6+1;
    	int dice_two = rand()%6+1;
    	int pcdice_one = rand()%6+1;
    	int pcdice_two = rand()%6+1;
        cout<<"\n[Round "<<rounds++<<"] You rolled "<<" ("<<dice_one<<", "<<dice_two<<", "<<"?),"<<" machine rolled ("<<pcdice_one<<", "<<pcdice_two<<", "<<"?)..."<<'\n';
        cout<<"How much are you going to bet: ";

#ifndef AUTOBET

		cin>>bet;

		while(bet>10 ||bet<=0)
		{
			cout<<"- your bet must between $1 and $10, type again: ";
			cin>>bet;
		}

#else
		    //This will determine the betting value for AUTOBET.
			//Bet will be based on the values of the first two human dice and machine dice.
		    if(dice_one == dice_two && pcdice_one != pcdice_two){
		        bet = rand()% 4 + 7;
		        }else if(dice_one != dice_two && pcdice_one == pcdice_two){
		            bet = rand()% 4 + 1;
		            } else if (dice_one == dice_two && pcdice_one == pcdice_two){
		                bet = rand()% 4 + 7;
		                }else
		                	bet = rand()%4 + 4;
#endif

		    //Rolling third dices to determine bigfish.
		    int dice_three = rand()%6+1;
		    int pcdice_three = rand()%6+1;

		    bigfish_player = (dice_one == dice_two && dice_one==dice_three);
		    bigfish_machine = (pcdice_one == pcdice_two && pcdice_one == pcdice_three);

		    //If both human and machine don't have big fish.
		    if(!bigfish_player && !bigfish_machine){

		            cout<<"You had ("<<dice_one<<", "<<dice_two<<", "<<dice_three<<")-> ";

    		        //Rerolling for the 2nd and 3rd and Calculates the largest dices rolled and adds it to find the total.

	                if(dice_one>=dice_two&&dice_one>=dice_three){
	                	largest = dice_one;
	                	}else if(dice_two>=dice_one&&dice_two>=dice_three){
	                		largest = dice_two;
	                        }else
	                        	largest = dice_three;
	                //Rerolling for human...
	                int dice_one = rand()%6+1;
                    int dice_two = rand()%6+1;

	                if(dice_one>=dice_two)
	                    largest_two = dice_one;
	                    else
	                    	largest_two = dice_two;

	                cout<<"You rolled ("<<dice_one<<", "<<dice_two<<") ";
	                //Third roll for human and then total score.
	                int dice_three = rand()%6+1;
	                cout<<"and then rolled ("<<dice_three<<") -> You"<<endl;

	                total_human_score =largest + largest_two + dice_three;
                    cout<<"scored "<<total_human_score<<". "<<endl;

		            cout<<"Machine had ("<<pcdice_one<<", "<<pcdice_two<<", "<<pcdice_three<<")-> ";

    		        //Rerolling for the 2nd and 3rd and Calculates the largest dices rolled and adds it to find the total.

                    if(pcdice_one>=pcdice_two && pcdice_one>=pcdice_three){
                        pc_largest = pcdice_one;
                            }else if(pcdice_two>=pcdice_one && pcdice_two>=pcdice_three){
                                pc_largest = pcdice_two;
                                    }else
                                        pc_largest = pcdice_three;
                    //Rerolling for machine...
                    int pcdice_one = rand()%6+1;
                    int pcdice_two = rand()%6+1;

                    if(pcdice_one>=pcdice_two)
                        pc_largest_two = pcdice_one;
                        else
                        	pc_largest_two = pcdice_two;

                    cout<<"Machine rolled ("<<pcdice_one<<", "<<pcdice_two<<") ";
                    //Third roll for machine and then total score.
                    int pcdice_three = rand()%6+1;
                    cout<<"and then rolled ("<<pcdice_three<<") ->"<<endl;

                    total_machine_score =pc_largest + pc_largest_two + pcdice_three;
                    cout<<"Machine scored "<<total_machine_score<<"."<<endl;

                    //Determines who has the greater scores
		            if(total_machine_score>total_human_score){
		        	    difference=(total_machine_score-total_human_score)*bet;
		        	    player_balance= player_balance - difference;
		                machine_balance=machine_balance + difference;
		                	cout<<"You lost :(  You have $"<<player_balance<<", machine has $"<<machine_balance<<"... "<<endl;
		            }else if(total_machine_score<total_human_score){
		        	    difference=(total_human_score-total_machine_score)*bet;
		        	    machine_balance = machine_balance - difference;
		                player_balance=player_balance + difference;
		                		cout<<"You won :) You have $"<<player_balance<<", machine has $"<<machine_balance<<"... "<<endl;
		            }else if(total_machine_score == total_human_score){
		                cout<<"You Tied You have $"<<player_balance<<", $"<<machine_balance<<"... "<<endl;
		            }
		    //This will determine who has big fish and the tie.
		    }else if(bigfish_player && !bigfish_machine){
		        cout<<"\nYou had ("<<dice_one<<", "<<dice_two<<", "<<dice_three<<") ... Big Fish!!!"<<endl;
		        cout<<"Machine had: ("<<pcdice_one<<", "<<pcdice_two<<", "<<pcdice_three<<")"<<endl;
		        player_balance = player_balance + (bet *50);
		        machine_balance = machine_balance - (bet * 50);
            		cout<<"You won :) You have $"<<player_balance<<", machine has $"<<machine_balance<<"... "<<endl;
	    	}else if(!bigfish_player && bigfish_machine){
	    		cout<<"\nYou had ("<<dice_one<<", "<<dice_two<<", "<<dice_three<<")"<<endl;
	    		cout<<"Machine had: ("<<pcdice_one<<", "<<pcdice_two<<", "<<pcdice_three<<") ... Big Fish!!!"<<endl;
	    		player_balance = player_balance - (bet *50);
	            machine_balance = machine_balance + (bet * 50);
	            	cout<<"You lost :(  You have $"<<player_balance<<", machine has $"<<machine_balance<<"... "<<endl;
	    	}else if(bigfish_player && bigfish_machine){
	    		cout<<"You had ("<<dice_one<<", "<<dice_two<<", "<<dice_three<<") ... Big Fish!!!\n";
	    		cout<<"Machine had: ("<<pcdice_one<<", "<<pcdice_two<<", "<<pcdice_three<<") ... Big Fish!!!"<<endl;
                cout<<"You Tied You have $"<<player_balance<<", $"<<machine_balance<<"... "<<endl;
		    	}
    }
    cout<<" "<<endl;
}

