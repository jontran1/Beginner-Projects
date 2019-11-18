/*
 * table1.h
 *
 *  Created on: Nov 19, 2017
 *      Author: W520
 */
#include "node1.h"
#include "list1.h"

#ifndef TABLE1_H_
#define TABLE1_H_

namespace JONTRAN_1{
template<class Item>
	class table{
		friend std::ostream& operator<<(std::ostream& out,const table<Item>& table1){
		//Postcondition: Prints each linked list in each array bracket.
			for(size_t i = 0 ; i < table1.capacity; i++){
					out<<"|";
					out<<table1.data[i];
				}
				return out;
		}
		typedef std::size_t size_type;
		//Value type is size_t for size.
		typedef Item value_type;
		const static size_type DEFAULT_CAPACITY = 11;
		//Starting capacity.
	public:
		table(size_type initial_capacity=DEFAULT_CAPACITY);
		~table();
		table(const table<Item>& table1);
		//Postcondition: Values and keys will be rehashed and copied into
		//a new table.
		void put (const int& key, const Item& entry);
		//Precondition: Key must be an integer.
		//Postcondition: Key will be used to find an index for array using hash function.
		//If data[index].size() is greater then a 5. It will activate the reserve function.
		//This reserve function will increase the array by 11. And the old keys and data will be
		//rehashed and copied into a new array.
		//After reserve, entry will be added to linked list in correct array bracket.
		//If key already exist an error message will appear. and returns nothing.
		//Inserted will be increased by 1.
		bool get(const int& key, Item& entry);
		//Precondition: Key is integer.
		//Postcondition: Key will be used to find array index.
		//Entry will be set to the data associated with the key and returns true.
		//else return false.
		bool remove(int key);
		//Precondition: Key is integer.
		//Postcondition: Key will be used to find array index.
		//If key exist in linked list. Key will be removed and returns true.
		//else returns false and a message will appear.
		//Inserted will be decreased by 1.
		void reserve(const size_type addend_capacity);
		//Precondition: addend_capacity is positive.
		//Postcondition: A new array will be created with a larger size.
		//All the keys from the old array will be rehashed into the new array. The
		//data associated with the key will be added to the new array.
		//The old array data will be returned to heap. and the new larger array will be set to data.
		size_type size()const{
			return inserted;
		}
 		void operator = (const table<Item>& table1);
 		//Postcondition: A new array will be created with a larger size.
		//All the keys from table1 array will be rehashed into the new array. The
		//data associated with the key will be added to the new array.

	private:
		list<Item>* data;
		size_type capacity;
		size_type inserted;
		size_type hash(int key) const;
		//Precondition: Key is integer
		//Postcondition: returns ((key+31)*17%capacity).

	};
}
#include "table1.template"




#endif /* TABLE1_H_ */
