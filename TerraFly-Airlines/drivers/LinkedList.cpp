/**
 * @file LinkedList.cpp
 * @author DiegoGarciaPadilla
 * @brief Implementation of the LinkedList class
 * @version 0.1
 * @date 2023-11-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP

#include <iostream>

using namespace std;

#include "../headers/LinkedList.h" // Include the header file

// Constructors

/**
 * @brief Construct a new LinkedList:: LinkedList object
 * 
 */

template <class T>
LinkedList<T>::LinkedList()
{
    this->head = NULL;
}

/**
 * @brief Construct a new LinkedList:: LinkedList object
 * 
 * @param head 
 */

template <class T>
LinkedList<T>::LinkedList(LLNode<T> *head)
{
    this->head = head;
}

// Destructor

/**
 * @brief Destroy the LinkedList:: LinkedList object
 * 
 */

template <class T>
LinkedList<T>::~LinkedList()
{
    // Traverse the linked list
    while (this->head != NULL)
    {
        // Remove the head
        this->head = this->head->next;
    }
}

// Getters

/**
 * @brief Get the head of the linked list
 * 
 * @return LLNode<T>* 
 */

template <class T>
LLNode<T> *LinkedList<T>::getHead()
{
    return this->head;
}

// Setters

/**
 * @brief Set the head of the linked list
 * 
 * @param head 
 */

template <class T>
void LinkedList<T>::setHead(LLNode<T> *head)
{
    this->head = head;
}

// Methods

/**
 * @brief Insert a new node in the linked list O(n)
 * 
 * @param data 
 */

template <class T>
void LinkedList<T>::insert(T data)
{
    // Create a new node
    LLNode<T> *node = new LLNode<T>(data);

    // Insert the node
    head = head->insert(head, node);
}

/**
 * @brief Remove a node from the linked list O(n)
 * 
 * @param data 
 */

template <class T>
void LinkedList<T>::remove(T data)
{
    // Remove the node
    head = head->remove(head, data);
}

/**
 * @brief Search a node in the linked list O(n)
 * 
 * @param data 
 * @return LLNode<T>* 
 */

template <class T>
LLNode<T> *LinkedList<T>::search(T data)
{
    // Search the node
    return head->search(head, data);
}

// Printers

/**
 * @brief Convert the object to a string
 * 
 * @return string 
 */

template <class T>
string LinkedList<T>::toString()
{
    return head->toString();
}

#endif // LINKEDLIST_CPP
