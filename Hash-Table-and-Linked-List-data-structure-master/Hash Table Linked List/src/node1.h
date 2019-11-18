/*
 * node1.h
 *
 *  Created on: Oct 28, 2017
 *      Author: W520
 */

#include <cstdlib>

#ifndef NODE1_H_
#define NODE1_H_

namespace JONTRAN_1{
	template <class Item>
	class node{
	public:
		typedef Item value_type;
		typedef size_t size_type;
		node(const Item& init_data = Item(),node<Item>* init_link=NULL, const int& init_key = 0){
		//Position: Contains the data field and Link field. The default data
		//value and link is set here. Data field takes in value_type and
		//and Link is set to NULL.
		//key will take integer.
			data_field = init_data;
			link_field = init_link;
			key = 0;
		}
		void set_key(const int& init_key){key=init_key;}
		//Precondition: Key is an integer.
		//Postcondition: key will be set.
		value_type get_key() const{return key;}
		//Postcondition: Key is returned.
  		void set_data(const Item& new_data){data_field = new_data;}
		//Postcondition: The node is set to a new value.
		void set_link(node* new_link){link_field = new_link;}
		//Postcondition: The node link is set to a new value.
		value_type data() const{return data_field;}
		//Postcondition returns data field.
		node* link(){return link_field;}
		//Postcondition returns non constant link field.
		const node* link() const{return link_field;}
		//Postcondition returns constant link field.
		size_type list_length (const node<Item>*& head_ptr);
		//Precondition Head pointer is the head pointer.
		//Postcondition Returns the number of nodes in the Linked List.
	private:
		Item data_field;
		node* link_field;
		int key;
	};
	template <class Item>
	const node<Item>* key_search(const node<Item>* head_ptr, const int& key);
	template <class Item>
	node<Item>* key_search(node<Item>* head_ptr, const int& key);
	//Postcondition: If key is found in linked list. Key will be returned, else return NULL
	template <class Item>
	void list_head_insert_without_key(node<Item>*& head_ptr, const Item& entry);
	//Precondition Head pointer is the head pointer.
	//Postcondition A new node is created with its data value set to entry
	//and its link pointed towards what head pointer was pointing at.
 	//Head_ptr is now pointed towards the new node.
	template <class Item>
	void list_head_insert(node<Item>*& head_ptr, const Item& entry, const int& key);
	//Precondition Head pointer is the head pointer.
	//Postcondition A new node is created with its data value set to entry
	//and its link pointed towards what head pointer was pointing at.
	//That new node's key is also set to key.
	//Head_ptr is now pointed towards the new node.
	template <class Item>
	void list_insert(node<Item>* previous_ptr, const Item& entry);
	//Precondition Previous_ptr points to a node in the Linked list.
	//Postcondition A new node is created, its data field is to entry and
	//it has been added after previous_ptr in the linked list.
	template <class Item>
	const node<Item>* list_search(const node<Item>* head_ptr, const Item& target);
	template <class Item>
	node<Item>* list_search(node<Item>* head_ptr, const Item& target);
	//Precondition Head_ptr is the head pointer to the linked list.
	//Postcondition It returns the pointer that contains the specified target value.
	template <class NodePtr, class SizeType>
	NodePtr* list_locate(NodePtr* head_ptr, SizeType& position);
	template <class NodePtr, class SizeType>
	const NodePtr* list_locate(NodePtr* head_ptr, SizeType position);
	//Precondition Head_ptr is the head pointer to the linked list.
	//Postcondition Returns the pointer at specified index position in linked list.
	template<class Item>
	void list_head_remove (node<Item>*& head_ptr);
	//Precondition Head_ptr is head pointer to the linked list.
	//Postcondition Head pointer has been mark and returned to heap.
	//Head_ptr is now pointing to a n-1 linked list.
	template<class Item>
	void list_remove (node<Item>* previous_ptr);
	//Precondition Previous_ptr is pointing to a node in the linked list.
	//Postcondition The node after previous_ptr is marked and returned to heap.
	//This linked list is now n-1.
	template<class Item>
	void clear(node<Item>*& head_ptr);
	//Precondition Head_ptr is the head pointer to linked list.
	//Postcondition The entire link list is returned to heap. And head_ptr is
	//set to point to NULL.
	template<class Item>
	void list_copy (const node<Item>* source_ptr, node<Item>*& head_ptr, node<Item>*& tail_ptr );
	//Precondition Source_ptr is head pointer to linked list. head_ptr and tail_ptr are
	//set to NULL.
	//Postcondition Head_ptr and tail_ptr is a new linked list that contains the same values
	//as source_ptr.
}
#include "node1.template"




#endif /* NODE1_H_ */
