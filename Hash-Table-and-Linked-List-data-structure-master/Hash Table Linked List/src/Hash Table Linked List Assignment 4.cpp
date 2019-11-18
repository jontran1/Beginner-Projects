//============================================================================
// Name        : Hash.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "node1.h"
#include "list1.h"
#include "table1.h"
using namespace JONTRAN_1;
using namespace std;

int main() {
	//Because we dont't want the array to get too long and slow down your program.
	//The solution is a dynamic array. This dynamic array will create a larger array.
	//and all the keys will be rehashed into the new array along with the key's data.
	//The hash function will uniformly distribute the keys throughout the array so there is
	//no wasteful space.
	//The reserve function is set to increase by 11 , but prime numbers are best.
  	table<int> table1;
	for(int i = 0 ; i < 60; i++){
		table1.put(i,i);

	}
	cout<<"Table 1 is below..."<<endl;
	cout<<table1<<endl;
	table1.remove(57);
	table1.remove(13);
	table1.remove(35);
	table1.remove(35);
	table1.put(0,0);
	cout<<"Table 1 after removal of 57,13, and 35..."<<endl;
	cout<<table1<<endl;
	table<int> table2(table1);
	cout<<"Table 2 is below which is a copy of table1 after removal."<<endl;
	cout<<table2<<endl;
	int test_value = 999;
	cout<<"Test value is: "<<test_value;
	table2.get(48,test_value);
	cout<<"\nTest value after get function is: "<<test_value<<endl;






}
