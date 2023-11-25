/**
 * @file LLNode.cpp
 * @author DiegoGarciaPadilla
 * @brief Implementation of the LLNode class (Linked List Node)
 * @version 0.1
 * @date 2023-11-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef LLNODE_CPP
#define LLNODE_CPP

#include <iostream>
#include <string>

#include "../headers/LLNode.h" // Header file

// Constructors

/**
 * @brief Construct a new LLNode:: LLNode object
 *
 */

template <class T>
LLNode<T>::LLNode()
{
    this->data = NULL;
    this->next = NULL;
}

/**
 * @brief Construct a new LLNode:: LLNode object
 *
 * @param data
 */

template <class T>
LLNode<T>::LLNode(T data)
{
    this->data = data;
    this->next = NULL;
}

/**
 * @brief Construct a new LLNode:: LLNode object
 *
 * @param data
 * @param next
 */

template <class T>
LLNode<T>::LLNode(T data, LLNode<T> *next)
{
    this->data = data;
    this->next = next;
}

// Destructor

/**
 * @brief Destruct the LLNode:: LLNode object
 *
 */

template <class T>
LLNode<T>::~LLNode()
{
    data = NULL;
    next = NULL;
}

// Getters

/**
 * @brief Get the data of the node
 *
 * @return T
 */

template <class T>
T LLNode<T>::getData()
{
    return this->data;
}

/**
 * @brief Get the next node of the linked list
 *
 * @return LLNode<T>*
 */

template <class T>
LLNode<T> *LLNode<T>::getNext()
{
    return this->next;
}

// Setters

/**
 * @brief Set the data of the node
 *
 * @param data
 */

template <class T>
void LLNode<T>::setData(T data)
{
    this->data = data;
}

/**
 * @brief Set the next node of the linked list
 *
 * @param next
 */

template <class T>
void LLNode<T>::setNext(LLNode<T> *next)
{
    this->next = next;
}

// Methods

/**
 * @brief Insert a new node in the linked list O(n)
 *
 * @param head
 * @param data
 * @return LLNode<T>*
 */

template <class T>
LLNode<T> *LLNode<T>::insert(LLNode<T> *head, T data)
{
    // Create a new node

    LLNode<T> *newNode = new LLNode<T>(data);

    // Check if the head is null

    if (head == NULL)
    {
        head = newNode;
        return head;
    }

    // Create a temporal node

    LLNode<T> *temp = head;

    // Iterate the linked list

    while (temp->getNext() != NULL)
    {
        temp = temp->getNext();
    }

    // Insert the new node

    temp->setNext(newNode);

    // Return the head

    return head;
}

/**
 * @brief Remove a node from the linked list O(n)
 *
 * @param head
 * @param data
 * @return LLNode<T>*
 */

template <class T>
LLNode<T> *LLNode<T>::remove(LLNode<T> *head, T data)
{
    // Check if the head is null

    if (head == NULL)
    {
        return head;
    }

    // Create a temporal node

    LLNode<T> *temp = head;

    // Check if the head is the node to remove

    if (temp->next == data)
    {
        head = temp->next;
        delete temp;
        return head;
    }

    // Iterate the linked list

    while (temp->next != NULL)
    {
        if (temp->next->data == data)
        {
            LLNode<T> *temp2 = temp->next;
            temp->next = temp2->next;
            delete temp2;
            return head;
        }
        temp = temp->next;
    }

    // Return the head

    return head;
}

/**
 * @brief Search a node in the linked list O(n)
 *
 * @param head
 * @param data
 * @return LLNode<T>*
 */

template <class T>
LLNode<T> *LLNode<T>::search(LLNode<T> *head, T data)
{
    // Check if the head is null

    if (head == NULL)
    {
        return head;
    }

    // Create a temporal node

    LLNode<T> *temp = head;

    // Iterate the linked list

    while (temp != NULL)
    {
        if (temp->data == data)
        {
            return temp;
        }
        temp = temp->next;
    }

    // Return the head

    return head;
}

// Printers

/**
 * @brief Convert the object to a string
 *
 * @return string
 */

template <class T>
string LLNode<T>::toString()
{
    // Create the string

    string str = "";

    // Create a temporal node

    LLNode<T> *temp = this;

    // Iterate the linked list

    while (temp != NULL)
    {
        str += to_string(temp->data) + " -> ";
        temp = temp->next;
    }

    // Return the string

    return str;
}


#endif // LLNODE_CPP