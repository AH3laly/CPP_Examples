#include<string>
#include "./types.hpp"

#ifndef __LINKED_LIST_GUARD_H
#define __LINKED_LIST_GUARD_H

namespace LinkedListCustomImplementation {

template <class NodeEntryType>
class LinkedList {

    private:
        class LinkedListNode {            
            public:
                class LinkedListNode *next;
                class LinkedListNode *prev;
                void setData(NodeEntryType*);
                NodeEntryType* getData() const;
                void print() const;
                NodeEntryType* get() const;
            
            private:
                NodeEntryType *data;
        };
        
        int count;
        /**
         * Initialize the List with the first Node
         */
        void addFirstNode(NodeEntryType *nodeEntry);

        /**
         * Reset everything for a new Empty List
         */
        void reset();

        LinkedListNode* createLinkedListNode(NodeEntryType *nodeEntry);
        //void createLinkedListNode(NodeEntryType *nodeEntry);

    public:
        LinkedListNode *cursor, *head, *end, *current;
        LinkedList();
        ~LinkedList();

        /**
         * Push LinkedListNode on the Top
         * Note: This operation Resets the cursor
         */
        void pushTop(NodeEntryType *nodeEntry);

        /**
         * Push LinkedListNode at the End
         * Note: This operation Resets the cursor
         */
        void pushEnd(NodeEntryType *nodeEntry);
        
        /**
         * POP LinkedListNode from the Top and saves it to popped
         * Note: This operation sets the cursor to Head
         */
        void popTop(NodeEntryType* &popped);

        /**
         * POP LinkedListNode from the End and saves it to popped
         * Note: This operation sets the cursor to End
         */
        void popEnd(NodeEntryType* &popped);

        /**
         * Insert LinkedListNode at the cursor position
         * Note: This operation moves the cursor to inserted Node
         */
        void insert(NodeEntryType *nodeEntry);

        /**
         * Insert LinkedListNode after the cursor position
         * Note: The cursor position will NOT change
         */
        void insertAfter(NodeEntryType *nodeEntry);

        /**
         * Insert LinkedListNode before the cursor position
         * Note: The cursor position will change to the inserted Node
         */
        void insertBefore(NodeEntryType *nodeEntry);

        /**
         * Traverse LinkedList and execure the passed function on all Nodes.
         */
        void traverse(void(*pt)(NodeEntryType *nodeEntry));

        /**
         * Remove LinkedListNode at the cursor position
         * Note: This operation moves the cursor to next Node
         */
        void remove();

        /**
         * Move cursor to the next Node
         */
        bool next();

        /**
         * Move cursor to the previous Node
         */
        bool prev();
        
        /**
         * Reset the cursor to head
         */
        void cursorBegin();

        /**
         * Reset the cursor to end
         */
        void cursorEnd();

        /**
         * Returns the number of Elements in the list
         */
        int getCount() const;

        /**
         * Returns true if the list is empty
         */
        int isEmpty() const;

        /**
         * Remove all elements from the List
         */
        void empty();
};

}
#endif