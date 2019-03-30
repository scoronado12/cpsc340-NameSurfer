#include "single_node.h"
#ifndef NODE_CPP
#define NODE_CPP

/**
 * @author Stefano C. Coronado (scoronado)
 * @since 2019-03-20
 * single_node.cpp
 */


/**ListNode constructor
 * Defines the contents of the node
 */


template <class NODETYPE>
ListNode<NODETYPE>::ListNode(const NODETYPE &info){
    data = info;
    next = 0;
}


/** getData - accessor method
 *  @return data - contained within the node
 */

template <class NODETYPE>
NODETYPE ListNode<NODETYPE>::getData() const{
    return data;
}
#endif
