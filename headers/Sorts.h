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
    void swap(T *, T *);                    // Swap function
    void mergeSort(vector<T> &, int, int);  // Merge sort algorithm
    void merge(vector<T> &, int, int, int); // Merge two subarrays
public:
    void sort(vector<T> &); // Sorts a vector with the merge sort algorithm
};

#endif /* SORTS_H */