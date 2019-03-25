/* *
 * @author Stefano C. Coronado (scoronado)
 * @since 2019-03-20
 * Linked_list.cpp */

#ifndef LIST_CPP
#define LIST_CPP
#include "linked_list.h"
#include <iostream>
#include <string>
using namespace std;

template <class NODETYPE>
linked_list<NODETYPE>::linked_list() {
        first = NULL;
        current = NULL;
        last = NULL;
}

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


template <class NODETYPE>
bool linked_list<NODETYPE>::InsertInOrder(NODETYPE value)
{
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
    
    
    
        //call either insertFront or insertRear
    //else if the new node data is less than first data
        //call insertFront
    //else if the new node data is greater than last data
        //call insertRear
    //else
        //set current to first
        //use a while loop to set current to the node before where you want to insert the new node
        //connect the new node next to current next
        //connect current next to the new node
    
    //return true
}
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
        
        //if this is the first node in the linked list
            //set first to current
            //set last to current
            //set current next to nullptr
        //else
            //set last next to current
            //set current next to nullptr
            //set last to current
    return true;
}

template <class NODETYPE>
bool linked_list<NODETYPE>::IsEmpty() const {
        return (first == NULL);
}

template <class NODETYPE>
bool linked_list<NODETYPE>::Search(NODETYPE &value) {
    
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
        return true;
    }
     return false;
}


template <class NODETYPE>
void linked_list<NODETYPE>::PrintAll() {
    //if not empty
        //set current to first
        //use a while loop to check for not equal to nullptr
            //print out data
            //move current over
    if(!IsEmpty()){
        current = first;
        while (current != nullptr){
            cout << current -> data << "\n";
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
    
    //if the value equals the first data and it is the last node in the linked last
    //set value to first data
    //remove the node and set current last and first to nullptr
    //else if the value equals the first data
    //set value to first data
    //set current to first
    //move first to the next node
    //delete current
    //else if the value equals the last data
    //set value to last data
    //set current to first
    //use a while loop to set current to one before last
    //delete last
    //set last to current
    //set current next to nullptr
    //else
    //set current to first
    //use a while loop to check for current does not equal null and current next data does not equal value
    //if current equals null
    //return false
    //else
    //set temp pointer the node you will be deleting
    //set value to the temp data
    //set current next to temp next
    //delete temp
    //return true
}

#endif
