//
//  LinkedList.hpp
//  Summer HW 1
//
//  Created by Richard Chung on 7/3/20.
//  Copyright © 2020 Richard Chung. All rights reserved.
//

#ifndef LINKEDLIST_INCLUDED
#define LINKEDLIST_INCLUDED
#include <string>

typedef std::string ItemType;

/*
 Name: struct Node
 Input:
 Output:
 Desciption: Creates a Node struct that holds member variables necessary for Linked Lists
 */
struct Node {
    ItemType value;
    Node *next;
    
};

class LinkedList {
    
private:
    Node *head;
    bool flag = false;
    int m_size;
    
public:
    
    /*
    Name: Default Constructor
    Input: a Linked List object
    Output: A constructed LinkedList Object with the corresponding member variables
    Desciption: Constructs a default LinkedList Object
    */
    LinkedList();
    
    /*
    Name: Copy Constructor
    Input: Reference to a constant LinkedList object
    Output: A LinkedList Object
    Desciption: Prevents shallow copying
    */
    LinkedList(const LinkedList& rhs);
    
    /*
    Name: Destructor
    Input: a Linked List object
    Output:
    Desciption: Destroys all the dynamically allocated memory in the list.
    */
    ~LinkedList();
    


    /*
    Name: Assignment Operator
    Input: Reference to a constant LinkedList object
    Output:
    Desciption: Allows for assignments of member variables of objects
    */
    const LinkedList& operator=(const LinkedList& rhs);
    
    
    /*
    Name: insertToFront
    Input: Reference to a constant variable of type Itemtype
    Output: type void
    Desciption: Inserts val at the front of the list
    */
    void insertToFront(const ItemType &val);
    
    /*
    Name: printList
    Input: a Linked List object
    Output: Prints out the values of the Linked List
    Desciption: Prints the Linked List
    */
    void printList() const;
    
    /*
    Name: get
    Input: a user given integer i, and a reference to a variable of type ItemType
    Output: a boolean that returns true or false if there exists an item at position i
    Desciption: Sets item to the value at position i in this LinkedList and return true, returns false if there is no element i
    */
      
    bool get(int i, ItemType& item) const;
    
    /*
    Name: reverseList
    Input: a Linked List object
    Output: reverses the values of the linked list
    Desciption: Reverses the Linked List
    */
    void reverseList();
    
    /*
    Name: printReverse
    Input: a Linked List object
    Output: Type void
    Desciption: Prints the LinkedList in reverse order
    */

    void printReverse() const;
    
    /*
    Name: append
    Input: a reference to a constant LinkedList object
    Output: type void
    Desciption: Appends the values of other onto the end of this // LinkedList.
    */

    void append(const LinkedList &other);
    
    /*
    Name: swap
    Input: A reference to a different LinkedList object
    Output: Type void
    Desciption: Exchange the contents of this LinkedList with the other one.
    */

    void swap(LinkedList &other);
    
    /*
    Name: size
    Input:
    Output: returns an integer value that corresponds to the size of the Linked List
    Desciption: Returns the number of items in the Linked List.
    */

    int size() const;
    
};


#endif //LINKEDLIST_INCLUDED
