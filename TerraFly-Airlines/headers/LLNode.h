/**
 * @file LLNode.h
 * @author DiegoGarciaPadilla
 * @brief Definition of the LLNode class (Linked List Node)
 * @version 0.1
 * @date 2023-11-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef LLNODE_H
#define LLNODE_H

#include <iostream>
#include <vector>

using namespace std;

template <class T>
class LLNode
{
private:
    // Attributes
    T data;         // Data of the node
    LLNode<T> *next; // Next node of the linked list
public:
    // Constructors
    LLNode(); // Construct a new LLNode:: LLNode object
    LLNode(T); // Construct a new LLNode:: LLNode object
    LLNode(T, LLNode<T> *); // Construct a new LLNode:: LLNode object

    // Destructor
    ~LLNode(); // Destruct the LLNode:: LLNode object

    // Getters
    T getData();         // Get the data of the node
    LLNode<T> *getNext(); // Get the next node of the linked list

    // Setters
    void setData(T);         // Set the data of the node
    void setNext(LLNode<T> *); // Set the next node of the linked list

    // Methods
    LLNode<T> *insert(LLNode<T> *, T); // Insert a new node in the linked list O(n)
    LLNode<T> *remove(LLNode<T> *, T); // Remove a node from the linked list O(n)
    LLNode<T> *search(LLNode<T> *, T); // Search a node in the linked list O(n)
    
    // Printers
    string toString(); // Convert the object to a string
};

#endif // LLNODE_H