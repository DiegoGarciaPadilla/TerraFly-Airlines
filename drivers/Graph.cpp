/**
 * @file Graph.cpp
 * @author DiegoGarciaPadilla
 * @brief Implementation of the Graph class
 * @version 0.1
 * @date 2023-10-12
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef GRAPH_CPP
#define GRAPH_CPP

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#include "../headers/Graph.h" // Include the header file
#include "Sorts.cpp"          // Include the Sort class
#include "CSVReader.cpp"      // Include the CSVReader class

// Constructor

/**
 * @brief Construct a new Graph:: Graph object
 *
 */

Graph::Graph()
{
    airports = unordered_map<string, Airport>();
}

// Destructor

/**
 * @brief Destroy the Graph:: Graph object
 *
 */

Graph::~Graph()
{
    // Traverse the airports
    for (auto it = airports.begin(); it != airports.end(); it++)
    {
        // Delete the airport
    }
}

// Methods

/**
 * @brief Initialize the graph
 *
 */

void Graph::initialize()
{
    // Get CSVRreader object
    CSVReader reader;

    // Get data from CSV file
    vector<vector<string>> data = reader.read("data/airports.csv", ',');

    // Fill the vector of airports
    for (int i = 0; i < data.size(); i++)
    {
        // Get the airport
        Airport airport = Airport(data[i][0], data[i][1], data[i][2], data[i][3], stod(data[i][4]), stod(data[i][5]));

        // Add the airport to the graph
        addAirport(airport);
    }

    // Get connections from CSV file
    vector<vector<string>> cData = reader.read("data/connections.csv", ',');

    // Fill the connections
    for (int i = 0; i < cData.size(); i++)
    {
        // Add the connection to the graph
        addConnection(cData[i][0], cData[i][1]);
    }
}

/**
 * @brief Find an airport in the graph
 *
 * @param IATA
 * @return true
 * @return false
 */

bool Graph::findAirport(string IATA)
{
    // Traverse the airports
    for (auto it = airports.begin(); it != airports.end(); it++)
    {
        // Check if the airport is the one we are looking for
        if (it->second.getIATA() == IATA)
        {
            return true;
        }
    }

    return false;
}

/**
 * @brief Add an airport to the graph
 *
 * @param airport
 */

void Graph::addAirport(Airport airport)
{
    // Check if the airport is already in the graph
    if (findAirport(airport.getIATA()))
    {
        // Print an error message
        cout << "The airport is already in the graph" << endl;
    }
    else
    {
        // Add the airport to the graph
        airports.insert({airport.getIATA(), airport});
    }
}

/**
 * @brief Remove an airport from the graph
 *
 * @param IATA
 */

void Graph::removeAirport(string IATA)
{
    // Check if the airport is in the graph
    if (findAirport(IATA))
    {
        // Remove the airport from the graph
        airports.erase(IATA);
    }
    else
    {
        // Print an error message
        cout << "The airport is not in the graph" << endl;
    }
}

/**
 * @brief Add a connection to the graph
 *
 * @param IATA1
 * @param IATA2
 */

void Graph::addConnection(string IATA1, string IATA2)
{
    // Check if the airports are NOT in the graph
    if (!findAirport(IATA1) || !findAirport(IATA2))
    {
        // Print an error message
        cout << "The airports are not in the graph" << endl;
        return;
    }

    // Check if the airports are the same
    if (IATA1 == IATA2)
    {
        // Print an error message
        cout << "The airports are the same" << endl;
        return;
    }

    // Check if the airports are already connected
    if (airports[IATA1].findNeighbor(&airports[IATA2]))
    {
        // Print an error message
        cout << "The airports are already connected" << endl;
        return;
    }

    // Add the connection to the graph
    airports[IATA1].addConnection(&airports[IATA2]);
    airports[IATA2].addConnection(&airports[IATA1]);
}

/**
 * @brief Remove a connection from the graph
 *
 * @param IATA1
 * @param IATA2
 */

void Graph::removeConnection(string IATA1, string IATA2)
{
    // Check if the airports are NOT in the graph
    if (!findAirport(IATA1) || !findAirport(IATA2))
    {
        // Print an error message
        cout << "The airports are not in the graph" << endl;
        return;
    }

    // Check if the airports are the same
    if (IATA1 == IATA2)
    {
        // Print an error message
        cout << "The airports are the same" << endl;
        return;
    }

    // Check if the airports are NOT connected
    if (!airports[IATA1].findNeighbor(&airports[IATA2]))
    {
        // Print an error message
        cout << "The airports are not connected" << endl;
        return;
    }

    // Remove the connection from the graph
    airports[IATA1].removeConnection(&airports[IATA2]);
    airports[IATA2].removeConnection(&airports[IATA1]);
}

/**
 * @brief Check if two airports are neighbors
 *
 * @param IATA1
 * @param IATA2
 * @return true
 * @return false
 */

bool Graph::areNeighbors(string IATA1, string IATA2)
{
    // Check if the airports are NOT in the graph
    if (!findAirport(IATA1) || !findAirport(IATA2))
    {
        // Print an error message
        cout << "The airports are not in the graph" << endl;
        return false;
    }

    // Check if the airports are the same
    if (IATA1 == IATA2)
    {
        // Print an error message
        cout << "The airports are the same" << endl;
        return false;
    }

    // Check if the airports are connected
    if (airports[IATA1].findNeighbor(&airports[IATA2]))
    {
        return true;
    }

    return false;
}

// Print methods

/**
 * @brief Convert the object to a string
 *
 * @return string
 */

string Graph::toString()
{
    // Get Sort class
    Sorts<Airport> s;

    // Create the vector
    vector<Airport> v;

    // Traverse the airports
    for (auto it = airports.begin(); it != airports.end(); it++)
    {
        // Add the airport to the vector
        v.push_back(it->second);
    }

    // Sort the vector
    s.sort(v);

    // Create the string
    string str = "";

    // Traverse the sorted vector
    for (int i = 0; i < v.size(); i++)
    {
        // Add the airport to the string
        str += v[i].toString() + "\n";
    }

    return str;
}

#endif // GRAPH_CPP