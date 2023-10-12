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
#include "drivers/CSVReader.cpp"

int main()
{
    // Get CSVRreader object
    CSVReader reader;

    // Get data from CSV file
    vector<vector<string>> data = reader.read("data/airports.csv", ',');

    // Create a vector of airports
    vector<Airport> airports;

    // Fill the vector of airports
    for (int i = 0; i < data.size(); i++)
    {
        airports.push_back(Airport(data[i][0], data[i][1], data[i][2], data[i][3], stod(data[i][4]), stod(data[i][5])));
    }

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