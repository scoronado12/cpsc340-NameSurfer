#ifndef NODE
#define NODE

/**
 * @author Stefano C. Coronado (scoronado)
 * @since 2019-03-20
 * single_node.h
 */

template <class NODETYPE> class linked_list;

template <class NODETYPE>

class ListNode{
    
    
    friend class linked_list<NODETYPE>;

    public:
        
        /**ListNode 
         * default constructor
         */
        ListNode() { 
            next = 0;
        }
        
        ListNode(const NODETYPE &);
        
        
        /** getData - accessor method
        *  @return data - contained within the node
        */
        NODETYPE getData() const;

    private:
        
        //holds the actual data contained in node
        NODETYPE data;
        //pointer to the next node
        ListNode <NODETYPE>*next;
};


#include "single_node.cpp"

#endif
