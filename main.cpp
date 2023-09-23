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
    Airport a1("John F. Kennedy International Airport", "New York", "United States", "JFK", 40.63980103, -73.77890015);
    Airport a2("San Francisco International Airport", "San Francisco", "United States", "SFO", 37.61899948, -122.375);
    Airport a3("Aeropuerto Internacional Benito Juarez", "Mexico City", "Mexico", "MEX", 19.4363, -99.072098);
    Airport a4("Shanghai Pudong International Airport", "Shanghai", "China", "PVG", 31.14340019, 121.8050003);
    Airport a5("London Heathrow Airport", "London", "United Kingdom", "LHR", 51.4706, -0.461941);

    vector<Airport> airports = {a1, a2, a3, a4, a5};

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