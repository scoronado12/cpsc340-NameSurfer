/**
 * @author Stefano C. Coronado (scoronado)
 * @since 2019-03-20
 * Linked_list.h
 */

#ifndef linked_list_H
#define linked_list_H
#include "single_node.h"
#include <iostream>
#include <string>


using namespace std;

template <class NODETYPE>
class linked_list{

	public:
        
        /** linked_list()
        * declares the linked list
        */
        linked_list();
        
        /**
        *  ~linked_list())
        *  Deconstructor
        */
        ~linked_list();
        
        /** 
        * linked_list() 
        * copy constructor
        */
        linked_list(linked_list<NODETYPE> &originalList);
        
        /** InsertInOrder
        *  @param value - NODETYPE
        *  Inserts the node of any ADT into the linked list
        */
        bool InsertInOrder(NODETYPE value);
        
        /** InsertRear
        *  @param value - NODETYPE
        *  Inserts the node of any ADT into the back of linked list
        *  @return true - if it is possible
        */
        bool InsertRear(NODETYPE value);
        
        /** InsertFront
        *  @param value - NODETYPE
        *  Inserts the node of any ADT into the front of linked list
        *  @return bool - if it is possible
        */
        bool InsertFront(NODETYPE value);
        
        /** Remove
        *  @param value - passed by reference
        *  Removes node at the in the linked list depending on where it is
        *  @return bool - depends on if it is done
        */
        bool Remove(NODETYPE & value);
        
        /** RemoveFront
        *  @param value - passed by reference
        *  Removes node at the front of the linked_list
        *  @return bool - depends on if it is done
        */
        bool RemoveFront(NODETYPE & value);
        
        /** RemoveRear
        *  @param value - passed by reference
        *  Removes node at the rear of the linked_list
        *  @return bool - depends on if it is done
        */
        bool RemoveRear(NODETYPE & value);
        
        /** Search
        * @param value - of NODETYPE ADT passed by reference
        * @return bool - if the corresponding node is found in the linked_list
        */
        bool Search(NODETYPE &value);
        
        /** PrintAll
        *  Prints out the entire linked_list from start to finish
        */
        void PrintAll();
        
        /**IsEmpty()
        * Helper function to determine if the linked_list is empty
        * @return bool - if first doesn't exist
        */
        bool IsEmpty() const;
	private:
        ListNode<NODETYPE> *first;
        ListNode<NODETYPE> *current;
        ListNode<NODETYPE> *last;

};

#include "linked_list.cpp"
#endif
