/**
 * @file Sorts.cpp
 * @author DiegoGarciaPadilla
 * @brief Implementation of the Sorts class
 * @version 0.1
 * @date 2023-09-12
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SORTS_CPP
#define SORTS_CPP

#include <iostream>
#include <vector>

using namespace std;

#include "../headers/Sorts.h" // Include the header file

/**
 * @brief Swap the values of two pointers
 *
 * @tparam T
 * @param i
 * @param j
 */

template <class T>
void Sorts<T>::swap(T *i, T *j)
{
    T aux = i;
    i = j;
    j = aux;
}

/**
 * @brief Merge two subarrays of arr[]
 *
 * @tparam T
 * @param arr
 * @param left
 * @param mid
 * @param right
 */

template <typename T>
void Sorts<T>::merge(vector<T> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp arrays
    vector<T> leftArr(n1);
    vector<T> rightArr(n2);

    // Copy data to temp arrays leftArr[] and rightArr[]
    for (int i = 0; i < n1; i++)
    {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        rightArr[i] = arr[mid + 1 + i];
    }

    // CombinE the temp arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr[], if there are any
    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr[], if there are any
    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

/**
 * @brief Recursive merge sort function
 *
 * @tparam T
 * @param arr
 * @param left
 * @param right
 */

template <typename T>
void Sorts<T>::mergeSort(vector<T> &arr, int left, int right)
{
    if (left < right)
    {
        // Encuentra el punto medio del vector
        int mid = left + (right - left) / 2;

        // Ordena la primera mitad
        mergeSort(arr, left, mid);

        // Ordena la segunda mitad
        mergeSort(arr, mid + 1, right);

        // Combina las mitades ordenadas
        merge(arr, left, mid, right);
    }
}

/**
 * @brief Sorts the vector using merge sort
 *
 * @tparam T
 * @param arr
 */

template <typename T>
void Sorts<T>::sort(vector<T> &arr)
{
    mergeSort(arr, 0, arr.size() - 1);
}

#endif /* SORTS_CPP */