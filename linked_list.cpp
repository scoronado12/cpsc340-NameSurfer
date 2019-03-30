/**
 * @author Stefano C. Coronado (scoronado)
 * @since 2019-03-20
 * Linked_list.cpp */

#ifndef LIST_CPP
#define LIST_CPP
#include "linked_list.h"
#include <iostream>
#include <string>
using namespace std;


/** linked_list()
 * declares the linked list
 */

template <class NODETYPE>
linked_list<NODETYPE>::linked_list() {
        first = NULL;
        current = NULL;
        last = NULL;
}

/**
 *  ~linked_list())
 *  Deconstructor
 */

template <class NODETYPE>
linked_list<NODETYPE>::~linked_list() {
        current = first;
        while (current != NULL) {
                first = first->next;
                delete current;
                current = first;
        }
        current = last = first = NULL;
}

/** 
 * linked_list() 
 * copy constructor
 */

template <class NODETYPE>
linked_list<NODETYPE>::linked_list(linked_list<NODETYPE> &originalList) {
    
        //Fill in the copy constructor
    originalList.current = originalList.first;
    while (originalList.current != nullptr){
        insertRear(originalList.current-> data);
        originalList.current = originalList.current -> next;
        //cout << first-> data << last->data << endl;
    }
}


/** InsertInOrder
 *  @param value - NODETYPE
 *  Inserts the node of any ADT into the linked list
 */

template <class NODETYPE>
bool linked_list<NODETYPE>::InsertInOrder(NODETYPE value){
    current = new ListNode<NODETYPE>;
    
    //Declare a new node
    //New the node
    //if the new node is not nullptr continue with the insert in order
    if (current == nullptr){
    //else return false
        return false;
    } else {
    //if this is the first node you are inserting the linked list
        current -> data = value;
        if (IsEmpty()){
            //insert front
            InsertFront(value);
        } else if (value >= last -> data){
            //insert rear
            
            InsertRear(value);
        } else if ( first -> data >= value){
            InsertFront(value);
        } else {
            ListNode <NODETYPE> *temp;
            temp = first;
            while (temp != nullptr && temp -> next -> data < value){
                temp = temp -> next;
            }
            current -> next = temp -> next;
            temp -> next = current;
            
             //last = last-> next;
        }
        
        
    }
    return true;
    
}

/** InsertFront
 *  @param value - NODETYPE
 *  Inserts the node of any ADT into the front of linked list
 *  @return bool - if it is possible
 */


template <class NODETYPE>
bool linked_list<NODETYPE>::InsertFront(NODETYPE value) {
    
    //New a new node with current
    current = new ListNode<NODETYPE>;
    
    //if current equal nullptr return false
    if (current == nullptr){
    
        return false;
    
    } else {
        
    //else
        //set current data to value
        current -> data = value;
        
        if (first == nullptr){ //or should I be looking at current == first
            
        //if this is the first node in the linked list
            first = last = current;
            //set first to current
            //set last to current
            current->next = nullptr;
            
            //set current next to nullptr
        } else {
        //else
            //set current next to first
            current->next = first;
            //set first to current
            first = current;
        }
    }
    return true;
    
}

/** InsertRear
 *  @param value - NODETYPE
 *  Inserts the node of any ADT into the back of linked list
 *  @return true - if it is possible
 */

template <class NODETYPE>
bool linked_list<NODETYPE>::InsertRear(NODETYPE value) {
    //New a new node with current
    current = new ListNode <NODETYPE>;
    
    //if current equal nullptr return false
    if (current == nullptr){
        return false;
    } else {
        //set current data to value
        current -> data = value;
        
        if (first == nullptr){
            InsertFront(value);
            return true;
        
        } else {
            current -> next = nullptr;
            last -> next = current;
            last = current;
        }
    }
        
    return true;
}

/**IsEmpty()
 * Helper function to determine if the linked_list is empty
 * @return bool - if first doesn't exist
 */

template <class NODETYPE>
bool linked_list<NODETYPE>::IsEmpty() const {
        return (first == NULL);
}


/** Search
 * @param value - of NODETYPE ADT passed by reference
 * @return bool - if the corresponding node is found in the linked_list
 */

template <class NODETYPE>
bool linked_list<NODETYPE>::Search(NODETYPE& value) {
    
    if (IsEmpty()){
        //if the list is empty return false
        return false;
    } else { //else
        //set current to first
        current = first;
        
            //use a while loop to check not for nullptr and not for current data not equal to the value
        while (current != nullptr && current->data != value){
            
            current = current -> next;
        }
    }
    
    //if current equals null not found
    if (current == nullptr){
        //return false
        return false;
    } else { //else
        //return true
        value = current -> data;
        return true;
    }
     return false;
}

/** PrintAll
 *  Prints out the entire linked_list from start to finish
 */

template <class NODETYPE>
void linked_list<NODETYPE>::PrintAll() {
    //if not empty
    if(!IsEmpty()){
        //set current to first
        current = first;
        //use a while loop to check for not equal to nullptr
        while (current != nullptr){
            //print out data
            cout << current -> data << "\n";
            //move current over
            current = current -> next;
        }
    }
    
    

}

template <class NODETYPE>
bool linked_list<NODETYPE>::RemoveFront(NODETYPE & value) {
    //TODO Debug
    if (first -> data == value && first == last){
        value = first -> data;
        delete first;
        first = last = nullptr;
        return true;
    } else if (first-> data == value){
        value = first -> data;
        current = first -> next;
        delete first;
        first = current;
        return true;
    }
    
    return false;
    
}
template <class NODETYPE>
bool linked_list<NODETYPE>::RemoveRear(NODETYPE & value) {

    
    if (first -> data == value && first == last){
        value = first -> data;
        delete first;
        first = last = nullptr;
        return true;
    } else if (last -> data == value){
        current = first;
        while (current -> next != last){
            current = current -> next;
        }
        value = last -> data;
        delete last;
        last = current;
        last -> next = nullptr;
        return true;
    }
    
    return false;
    
}
template <class NODETYPE>
bool linked_list<NODETYPE>::Remove(NODETYPE & value) {
    
    if (first->data == value && first == last){
        value = first -> data;
        delete first;
        first = last = nullptr;
        return true;
    } else if (first -> data == value){
        value = first -> data;
        current = first -> next;
        delete first;
        first = current;
        return true;
    } else if (last -> data == value){
        current = first;
        while (current -> next != last){
            current = current -> next;
        }
        
        value = last -> data;
        delete last;
        last = current;
        last -> next = nullptr;
        return true;
        
    } else {
        current = first;
        while (current != nullptr && current -> next -> data != value){
            current = current -> next;
        }
        if (current != nullptr) {
            
            value = current -> next -> data;
            ListNode <NODETYPE> *temp = current -> next;
            current -> next = temp -> next;
            delete temp;
            return true;
        }
        
        
    }
    return false;
    
}

#endif
