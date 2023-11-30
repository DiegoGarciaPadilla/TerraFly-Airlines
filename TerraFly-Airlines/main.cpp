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
#include "drivers/HandleCSV.cpp"
#include "drivers/Graph.cpp"

int main()
{
    // Variables
    string origin;
    string destination;

    // Create graph
    Graph graph = Graph();

    // Get airports
    graph.initialize();

    // Title
    cout << "TerraFly Airlines" << endl;

    // Book a flight
    cout << "Book a flight" << endl;
    cout << "---------------" << endl;
    cout << "Origin airport" << endl;

    // List of airports
    cout << graph.listAirports();

    // Get origin
    cout << "Origin (write IATA): ";
    cin >> origin;

    // Check if the airport exists
    while (!graph.findAirport(origin))
    {
        cout << "Invalid airport. Try again: ";
        cin >> origin;
    }

    // Clear the screen
    system("cls");

    // List of airports with connections to the origin
    cout << "Destination airport" << endl;
    cout << "--------------------" << endl;
    cout << graph.listConnections(origin);

    cout << "Destination (write IATA): ";
    cin >> destination;

    // Check if the airport exists
    while (!graph.findAirport(destination))
    {
        cout << "Invalid airport. Try again: ";
        cin >> destination;
    }

    // Clear the screen
    system("cls");

    // Get airports
    Airport *originAirport = graph.getAirport(origin);
    Airport *destinationAirport = graph.getAirport(destination);

    // Get data
    double distance = graph.getDistance(origin, destination);
    double price = graph.getPrice(origin, destination);

    // Add data to vectors
    vector<string> flight = {originAirport->getIATA(), destinationAirport->getIATA(), to_string(distance), to_string(price)};

    // Write the flight to the file
    HandleCSV handleCSV = HandleCSV();
    handleCSV.writeCSV("data/flights.csv", {flight});

    // Print the flight
    cout << "Flight" << endl;
    cout << "------" << endl;
    cout << "Origin: " << originAirport->getName() << " (" << originAirport->getIATA() << ")" << endl;
    cout << "Destination: " << destinationAirport->getName() << " (" << destinationAirport->getIATA() << ")" << endl;
    cout << "Distance: " << graph.getDistance(origin, destination) << " km" << endl;
    cout << "Price: $" << price << " USD" << endl;
    
    // Wait for the user to press a key
    cin >> origin;
}