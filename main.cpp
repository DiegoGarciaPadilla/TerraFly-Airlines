/**
 * @file main.cpp
 * @author DiegoGarciaPadilla
 * @brief 
 * @version 0.1
 * @date 2023-09-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "drivers/Sorts.cpp"

int main() {
    Sorts<int> s;
    Sorts<double> s2;
    Sorts<string> s3;

    vector<int> intArr = {12, 11, 13, 5, 6, 7};
    vector<double> doubleArr = {12.5, 11.3, 13.7, 5.0, 6.1, 7.8};
    vector<string> stringArr = {"Diego Antonio", "Garcia", "Padilla", "A01710777", "ITC"};
    
    cout << "Arreglo original (enteros): ";
    for (const int& num : intArr) {
        cout << num << " ";
    }
    cout << endl;

    s.sort(intArr);

    cout << "Arreglo ordenado (enteros): ";
    for (const int& num : intArr) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Arreglo original (dobles): ";
    for (const double& num : doubleArr) {
        cout << num << " ";
    }
    cout << endl;

    s2.sort(doubleArr);

    cout << "Arreglo ordenado (dobles): ";
    for (const double& num : doubleArr) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Arreglo original (strings): ";
    for (const string& str : stringArr) {
        cout << str << " ";
    }
    cout << endl;

    s3.sort(stringArr);

    cout << "Arreglo ordenado (strings): ";
    for (const string& str : stringArr) {
        cout << str << " ";
    }
    cout << endl;

    return 0;
}