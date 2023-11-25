/**
 * @file LinkedList.h
 * @author DiegoGarciaPadilla
 * @brief Definition of the LinkedList class
 * @version 0.1
 * @date 2023-11-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <vector>
#include <string>

#include "../drivers/LLNode.cpp" // Friend class

using namespace std;

template <class T>
class LinkedList
{
private:
    // Attributes
    LLNode<T> *head; // Head of the linked list
public:
    // Constructors
    LinkedList();            // Construct a new LinkedList:: LinkedList object
    LinkedList(LLNode<T> *); // Construct a new LinkedList:: LinkedList object

    // Destructor
    ~LinkedList(); // Destruct the LinkedList:: LinkedList object

    // Getters
    LLNode<T> *getHead(); // Get the head of the linked list

    // Setters
    void setHead(LLNode<T> *); // Set the head of the linked list

    // Methods
    void insert(T);       // Insert a new node in the linked list O(n)
    void remove(T);       // Remove a node from the linked list O(n)
    LLNode<T> *search(T); // Search a node in the linked list O(n)

    // Printers
    string toString(); // Convert the object to a string

    // Friends
    class LLNode<T>; // Friend class
};

#endif // LINKEDLIST_H