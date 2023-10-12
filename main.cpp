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

    // Fill the vector of airports (only 5 airports for testing)
    for (int i = 0; i < 5; i++)
    {
        airports.push_back(Airport(data[i][0], data[i][1], data[i][2], data[i][3], stod(data[i][4]), stod(data[i][5])));
    }

    // Print the airports
    cout << "Airports:" << endl;
    cout << "---------" << endl;
    cout << endl;

    for (int i = 0; i < airports.size(); i++)
    {
        cout << airports[i].toString() << endl;
    }

    // Create map of connections
    map<string, vector<string>> connections;

    // Fill the map of connections (only 5 connections for testing)
    connections[airports[0].getIATA()] = vector<string>{airports[1].getIATA(), airports[2].getIATA()};
    connections[airports[1].getIATA()] = vector<string>{airports[0].getIATA(), airports[2].getIATA(), airports[3].getIATA()};
    connections[airports[2].getIATA()] = vector<string>{airports[0].getIATA(), airports[1].getIATA(), airports[3].getIATA()};
    connections[airports[3].getIATA()] = vector<string>{airports[1].getIATA(), airports[2].getIATA(), airports[4].getIATA()};
    connections[airports[4].getIATA()] = vector<string>{airports[3].getIATA()};

    // Create connections
    for (int i = 0; i < airports.size(); i++)
    {
        for (int j = 0; j < connections[airports[i].getIATA()].size(); j++)
        {
            airports[i].addConnection(&airports[j]);
        }
    }

    // Print the connections
    cout << "Connections:" << endl;
    cout << "------------" << endl;
    cout << endl;

    for (int i = 0; i < airports.size(); i++)
    {
        cout << airports[i].toString() << endl;
    }

}