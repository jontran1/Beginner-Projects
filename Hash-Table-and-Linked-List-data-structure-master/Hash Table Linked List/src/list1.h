
#include <cstdlib>
#include "node1.h"
#include <ostream>

#ifndef list_H_
#define list_H_

namespace JONTRAN_1{
template<class Item>
	class list{

	public:
	friend std::ostream& operator<<(std::ostream& out, const list<Item>& list1){
	//Postcondition: Items for key and data will be printed out for linked list.
		node<Item>* current_ptr;
				current_ptr = list1.head_ptr;
				out<<"(";
				while(current_ptr != NULL){
					out<<"(";
					out<<current_ptr->data();
					out<<", key:";
					out<<current_ptr->get_key();
					out<<")";
					out<<" , ";
					current_ptr = current_ptr->link();
				}
				out<<")";
				return out;
	}
		typedef Item value_type;
		typedef size_t size_type;
		list();
		//Postcondition Head_ptr is pointing to NULL and many_noes is set to 0.
		list(const list& source);
		//Copy Constructor
		//Postcondition All values in source is copied to to a new linked list.
		~list();
		size_type erase(const Item& target);
		//Postcondition All target values have been removed from Linked List.
		//All items are returned to heap. Returns number of removed items.
		bool erase_one(const Item& target);
		//Postcondition One target value has been removed from Linked List and returned to heap.
		//Returns true if target is found or false if not.
		bool remove_key(const int& key);
		//Precondition: Key is integer.
		//Postcondition: If key exist in linked list. Key and data will be removed from linked list.
		//and returned to heap.
		void insert(const Item& entry, const int& key);
		//Postcondition A copy of entry has been inserted into Linked list
		void clear_list(list& source);
		//Postcondition Linked list values all been removed and returned to heap.
		void operator += (const list& addend);
		//Postcondition All the items in addend is added into linked list.
		void operator =(const list& source);
		//Postcondition All source values are copied into new linked list.
 		size_type size() const{
		//Postcondition Returns number of nodes.
			return many_nodes;
		}
		bool operator ==(const list& source);
		//Postcondition Returns true or false if two linked list head_ptr are pointing
		//to the same linked list.
		bool operator !=(const list& source);
		//Postcondition Returns true or false if two linked list head_ptr are pointing
		//to the same linked list.

		size_type count(const Item& target)const;
		//Postcondition Returns number of target values in linked list.
		int list_search_key(const list<Item>& list1, size_type position);
		//Precondition: Position > 0 && position < size().
		//Postcondition: Key will be returned at position x.
		bool is_key_there(const int& key);
		//Precondition: Key is integer.
		//Postcondition: If key exist in linked list.
		//returns true if key is in the list.
		//otherwise returns false.
		Item list_get_data(const int& key);
		//Precondition: Key is integer.
		//Postcondition: Returns data associated  with key.
  		Item list_search_data(const list<Item>& list1, size_type position);
  		//Precondition: Position > 0 && position < size().
  		//Postcondition: Returns data at position x.

	private:
		node<Item> *head_ptr;
		size_type many_nodes;
 	};
template<class Item>
list<Item> operator +(const list<Item>& List1, const list<Item>& List2);
	//Postcondition Adds contains of list 1 and list 2 into a new linked list.

}
#include "list1.template"



#endif /* BAG1_H_ */
