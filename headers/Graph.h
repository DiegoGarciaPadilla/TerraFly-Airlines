/**
 * @file Graph.h
 * @author DiegoGarciaPadilla
 * @brief Definition of the Graph class
 * @version 0.1
 * @date 2023-10-12
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <unordered_map>

using namespace std;

#include "../drivers/Airport.cpp" // Friend class

class Graph
{
private:
    // Attributes

    unordered_map<string, Airport> airports; // Airports of the graph
public:
    // Constructors

    Graph(); // Construct a new Graph:: Graph object

    // Destructor

    ~Graph(); // Destruct the Graph:: Graph object

    // Methods

    bool findAirport(string);              // Find an airport in the graph
    void addAirport(Airport);              // Add an airport to the graph
    void removeAirport(string);            // Remove an airport from the graph
    void addConnection(string, string);    // Add a connection to the graph
    void removeConnection(string, string); // Remove a connection from the graph

    // Print methods

    string toString(); // Convert the object to a string

    // Friend classes

    friend class Airport;
};

#endif // GRAPH_H