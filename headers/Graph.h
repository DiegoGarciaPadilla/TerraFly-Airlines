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

#include "../drivers/Airport.cpp" // Friend class

class Graph
{
private:
    // Attributes
    std::unordered_map<std::string, Airport> airports; // Airports of the graph
public:
    // Constructors
    Graph(); // Construct a new Graph:: Graph object

    // Destructor
    ~Graph(); // Destruct the Graph:: Graph object

    // Methods
    bool findAirport(std::string);                     // Find an airport in the graph
    void addAirport(Airport);                          // Add an airport to the graph
    void removeAirport(std::string);                   // Remove an airport from the graph
    void addConnection(std::string, std::string, int); // Add a connection to the graph
    void removeConnection(std::string, std::string);   // Remove a connection from the graph

    // Print methods
    string toString(); // Convert the object to a string

    // Friend classes
    friend class Airport;
};

#endif // GRAPH_H