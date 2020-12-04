#include "LinkedList.h"
#include <iostream>

/*
 Psuedocode
    initialize head to be equal to nullptr and m_size to 0
 */
LinkedList::LinkedList() : head(nullptr), m_size(0) { }

/*
 Psuedocode
 
 initialize m_size to 0;
 set head equal to nullptr
 create a temporary variable p that points to a node and assign it the rhs's head
 
 while p is not a nullptr
    create a new node n
    assign p's pointer to value to n's pointer to value
    set p equal to p's next
 end while loop
 */
LinkedList::LinkedList(const LinkedList& rhs){
    m_size = 0;
    head = nullptr;
    Node*p = rhs.head;
    
    while (p!= nullptr){
        Node*n = new Node;
        n->value = p->value;
        p = p->next;
 
    }
}
/*
 Psuedocode
 
 create a temporary node p that is set equal to head
 
 while p is not a nullptr
    create n that points to a Node that is assigned p's next
    delete p
    set p = n
 end while loop
 */
LinkedList::~LinkedList(){
    Node*p;
    p= head;
    while (p!=nullptr){
        Node*n = p->next;
        delete p;
        p = n;
    }
}

/*
 Psuedocode
 
 if this is not equal to the rhs //checks for aliasing
    create a linkedlist object temp
    call the swap function and pass in temp as a parameter
 
 return this
 */
const LinkedList& LinkedList::operator=(const LinkedList& rhs){
    if (this != &rhs){
        LinkedList temp;
        
        swap(temp);
    
    }
    return *this;
}

/*
 Psuedocode
 
 create an integer i that is inititalized to 0
 create a temporary node p that is equal to head
 
 while p is not a nullptr
    p is set equal to p's next
    increment i
 end while loop
 
 return i
 */
int LinkedList::size() const{
    int i = 0;
    Node*p;
    p = head;
    while (p != nullptr){
        p = p->next;
        i++;
    }
    return i;
}

/*
 Pseudocode
    Create a p that is a pointer to node
    allocate a new node p
    have p's value be assigned the given val
    set p's next to be assigned head
    have head be assigned p
 */
void LinkedList::insertToFront(const ItemType &val){
    Node *p;
    p = new Node;
    p->value = val;
    p->next = head;
    head = p;
}

/*
 Psuedocode
 
 if size is not equal to 0
    create a temporary node p that is assigned head
    
    while p is not a nullptr
        print out p's value and a space
        set p equal to p's next
    end while loop
 
    print out a newline
 
 else
    return
 */
void LinkedList::printList() const{
    if (size() != 0){
    Node*p;
    p = head;
    while (p!=nullptr){
        std::cout << p->value << " ";
        p = p->next;
    }
    std::cout << std::endl;
    }
    else
        return;
}

/*
 Psuedocode
 
 if the given i is greater than or equal to size of the list or i is less than 0
    return false
 
 create a temporary node p that is assigned head
 
 for int j = 0, j does not equal i, j++
    p is assigned p's next
 end for loop
 
 item is assigned p's value
 return true
 */
bool LinkedList::get(int i, ItemType& item) const{
    if (i >= size() || i < 0){
        return false;
    }
    
    Node*p;
    p = head;
    for (int j = 0; j != i; j++){
        p = p->next;
    }
    item = p->value;
    
    return true;
    
}

/*
 Psuedocode
 
 Create a temporary node p that is assigned head
 create a node next that is equal to nullptr
 create a node prev that is equal to nullptr
 
 while p is not a nullptr
    next is assigned p's pointer to next
    p's pointer to next is assigned prev
 end while loop
 
 set head equal to prev
 */
void LinkedList::reverseList(){
    Node*p;
    p = head;
    Node*next = nullptr;
    Node*prev = nullptr;
    
    while (p!=nullptr){
        next = p->next;
        p->next = prev;

        prev = p;
        p = next;
    }
    head = prev;
   
}

/*
 Psuedocode
 if the size is not equal to 0 //items exist in this lsit
 
 create an int j that is assigned the size of the linked list
 
 for int i = to the size, i > 0, i --
    create a temporary node p that is assigned head
    create a static integer x that is initialized to 0
 
    create an integer k that is assigned the value of x
        while p's pointer to next is not a nullptr, and k is less than j-1
            p is assigned p's pointer to next
            increment k
        end while loop
 
 increment x
 print out the current value of p and a space
 
 end for loop
 
 print out a new line
 
 else //the linked list is empty
    return
 
 */

void LinkedList::printReverse() const{
    if (size() != 0){
    int j = size();
    for (static int i = size(); i > 0; i--){
        Node*p;
        p = head;
        static int x = 0;
  
       int k = x;
        while (p->next !=nullptr && k < j-1){
            p = p->next;
            k++;
        
    }
        x++;
        std::cout << p->value << " ";
    
    }
    std::cout << std::endl;
    }
    else
        return;
}
/*
 Psuedocode
 
 Create a temporary node p that is assigned the other's head
 have the other's head be assigned this's head
 have head be assigned p
 
 create an int i that is assigned the value of size
 assign size to other's private member variable size
 have this's private member variable size be assigned i
 */
// Exchange the contents of this LinkedList with the other // one.
void LinkedList::swap(LinkedList &other){
    Node*p = other.head;
    other.head = head;
    head = p;
    
    int i = size();
    other.m_size = size();
    m_size = i;
    
}
/*
 Pseudocode
 
 Create a temporary node n, that points to head
 
 while n pointing to next is not a nullptr
    assign n pointing to next to n
 
 end loop
// this will traverse to the end of the list right before the nullptr
 
 create a temporary node q that points to other's head

 while q is not a nullptr
    Allocate memory for a new node
    Assign the newNode's value to q's value
    link n's next to the new node
    assign q's pointer to next to q
    assign n's pointer to next to n
 
 end loop
 
 Relink n's next to point to nullptr
 
 */
void LinkedList::append(const LinkedList &other){\
    
    Node * n;
    n = head;
    
    while (n ->next !=nullptr){ //traverses to the end of the list right before the nullptr
        n = n->next;
    }
    
    Node * q;
    q = other.head;
    
    while (q!= nullptr){
        Node*newNode = new Node;
        newNode->value = q->value;
        n->next = newNode;
        q = q->next;
        n = n->next;
    }
    n->next = nullptr;
    
    
    
}
