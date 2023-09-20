/**
 * @file main.cpp
 * @author DiegoGarciaPadilla
 * @brief Main file
 * @version 0.1
 * @date 2023-09-12
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

#include "drivers/Airport.cpp"
#include "drivers/Sorts.cpp"

int main()
{
    Airport a1("John F. Kennedy International Airport", "New York", "United States", "JFK", 40.63980103, -73.77890015, 13);
    Airport a2("San Francisco International Airport", "San Francisco", "United States", "SFO", 37.61899948, -122.375, 13);
    Airport a3("Aeropuerto Internacional Benito Juarez", "Mexico City", "Mexico", "MEX", 19.4363, -99.072098, 13);

    vector<Airport> airports;
    airports.push_back(a1);
    airports.push_back(a2);
    airports.push_back(a3);

    cout << "Unsorted airports:" << endl;
    for (int i = 0; i < airports.size(); i++)
    {
        cout << airports[i].toString() << endl;
    }
    cout << endl;

    Sorts<Airport> s;
    s.sort(airports);

    cout << "Sorted airports:" << endl;
    for (int i = 0; i < airports.size(); i++)
    {
        cout << airports[i].toString() << endl;
    }
    cout << endl;
}