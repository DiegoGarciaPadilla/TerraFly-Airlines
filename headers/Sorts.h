/**
 * @file Sorts.h
 * @author DiegoGarciaPadilla
 * @brief Definition of the Sorts class
 * @version 0.1
 * @date 2023-09-12
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SORTS_H
#define SORTS_H

#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Sorts
{
private:
    // Swap the values of two pointers
    void swap(T *, T *);
    // Merge sort algorithm
    void mergeSort(vector<T> &, int, int);
    void merge(vector<T> &, int, int, int);
public:
    void sort(vector<T> &);
};

#endif /* SORTS_H */