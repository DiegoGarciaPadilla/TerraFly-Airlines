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

    void initialize();                     // Initialize the graph (O(n))
    bool findAirport(string);              // Find an airport in the graph (O(n))
    void addAirport(Airport);              // Add an airport to the graph (O(1))
    void removeAirport(string);            // Remove an airport from the graph (O(n))
    void addConnection(string, string);    // Add a connection to the graph (O(1))
    void removeConnection(string, string); // Remove a connection from the graph (O(1))
    bool areNeighbors(string, string);     // Check if two airports are neighbors (O(1))

    // Print methods

    string toString(); // Convert the object to a string

    // Friend classes

    friend class Airport;
};

#endif // GRAPH_H