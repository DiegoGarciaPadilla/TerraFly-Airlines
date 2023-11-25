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
#include "drivers/Graph.cpp"

int main()
{
    // Create graph
    Graph graph = Graph();

    // Get airports
    graph.initialize();

    // Print the graph
    cout << graph.toString() << endl;
}