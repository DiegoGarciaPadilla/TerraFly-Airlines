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

using namespace std;

template <class T>
struct ListNode
{
    T data;
    ListNode<T> *next;
};

#endif // LINKEDLIST_H