/**
 * @file Airport.cpp
 * @author DiegoGarciaPadilla
 * @brief Implementation of the Airport class
 * @version 0.1
 * @date 2023-09-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef AIRPORT_CPP
#define AIRPORT_CPP

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <unordered_map>

using namespace std;

#include "../headers/Airport.h" // Include the header file

// Constructor

/**
 * @brief Construct a new Airport:: Airport object
 *
 */

Airport::Airport()
{
    name = "";
    city = "";
    country = "";
    IATA = "";
    latitude = 0;
    longitude = 0;
    connections = unordered_map<Airport *, double>();
}

/**
 * @brief Construct a new Airport:: Airport object
 *
 * @param name
 * @param city
 * @param country
 * @param IATA
 * @param latitude
 * @param longitude
 */

Airport::Airport(string name, string city, string country, string IATA, double latitude, double longitude)
{
    this->name = name;
    this->city = city;
    this->country = country;
    this->IATA = IATA;
    this->latitude = latitude;
    this->longitude = longitude;
    connections = unordered_map<Airport *, double>();
}

// Destructor

/**
 * @brief Destroy the Airport:: Airport object
 *
 */

Airport::~Airport() {}

// Getters

/**
 * @brief Get the name of the airport
 *
 * @return string
 */

string Airport::getName()
{
    return name;
}

/**
 * @brief Get the city of the airport
 *
 * @return string
 */

string Airport::getCity()
{
    return city;
}

/**
 * @brief Get the country of the airport
 *
 * @return string
 */

string Airport::getCountry()
{
    return country;
}

/**
 * @brief Get the IATA code of the airport
 *
 * @return string
 */

string Airport::getIATA()
{
    return IATA;
}

/**
 * @brief Get the latitude of the airport
 *
 * @return double
 */

double Airport::getLatitude()
{
    return latitude;
}

/**
 * @brief Get the longitude of the airport
 *
 * @return double
 */

double Airport::getLongitude()
{
    return longitude;
}

/**
 * @brief Get the connections of the airport
 *
 * @return unordered_map<Airport *, double>
 */

unordered_map<Airport *, double> Airport::getConnections()
{
    return connections;
}

// Setters

/**
 * @brief Set the name of the airport
 *
 * @param name
 */

void Airport::setName(string name)
{
    this->name = name;
}

/**
 * @brief Set the city of the airport
 *
 * @param city
 */

void Airport::setCity(string city)
{
    this->city = city;
}

/**
 * @brief Set the country of the airport
 *
 * @param country
 */

void Airport::setCountry(string country)
{
    this->country = country;
}

/**
 * @brief Set the IATA code of the airport
 *
 * @param IATA
 */

void Airport::setIATA(string IATA)
{
    this->IATA = IATA;
}

/**
 * @brief Set the latitude of the airport
 *
 * @param latitude
 */

void Airport::setLatitude(double latitude)
{
    this->latitude = latitude;
}

/**
 * @brief Set the longitude of the airport
 *
 * @param longitude
 */

void Airport::setLongitude(double longitude)
{
    this->longitude = longitude;
}

/**
 * @brief Set the connections of the airport
 *
 * @param connections
 */

void Airport::setConnections(unordered_map<Airport *, double> connections)
{
    this->connections = connections;
}

// Methods

/**
 * @brief Convert the object to a string
 *
 * @return string
 */

string Airport::toString()
{
    // Create the string
    string str = "";

    // Add the airport information
    str += "Name: " + name + "\n";
    str += "City: " + city + "\n";
    str += "Country: " + country + "\n";
    str += "IATA: " + IATA + "\n";
    str += "Latitude: " + to_string(latitude) + "\n";
    str += "Longitude: " + to_string(longitude) + "\n";

    // Add the connections
    str += "Connections: \n";
    for (auto connection : connections)
    {
        str += "\t" + connection.first->getIATA() + " (" + to_string(connection.second) + " km)\n";
    }

    // Return the string
    return str;
}

/**
 * @brief Calculate the distance to another airport
 *
 * @param destiny
 * @return double
 */

double Airport::distanceTo(Airport &destiny)
{
    // Get the latitude and longitude of the destiny
    double lat2 = destiny.getLatitude() * M_PI / 180;
    double lon2 = destiny.getLongitude() * M_PI / 180;

    // Convert the latitude and longitude to radians
    double lat1 = latitude * M_PI / 180;
    double lon1 = longitude * M_PI / 180;

    // Calculate the difference between the latitudes and longitudes
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;

    // Calculate the distance (Haversine formula)
    double a = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlon / 2), 2); // Square of half the chord length
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));                                       // Angle between the two points
    double distance = 6371 * c;                                                       // Earth radius = 6371 km * angle

    // Return the distance in kilometers
    return distance;
}

// Graph methods

/**
 * @brief Add a connection to the airport
 *
 * @param airport
 */

void Airport::addConnection(Airport *airport)
{
    // Check if the airport is already connected
    if (connections.find(airport) != connections.end())
    {
        // Print an error message
        cout << "The airport is already connected" << endl;
    }
    else
    {
        // Calculate the distance between the airports
        double distance = distanceTo(*airport);

        // Add the connection to the airport
        connections.insert({airport, distance});
    }
}

/**
 * @brief Remove a connection from the airport
 *
 * @param airport
 */

void Airport::removeConnection(Airport *airport)
{
    // Check if the airport is connected
    if (connections.find(airport) != connections.end())
    {
        // Remove the connection from the airport
        connections.erase(airport);
    }
    else
    {
        // Print an error message
        cout << "The airport is not connected" << endl;
    }
}

/**
 * @brief Find a neighbor of the airport
 *
 * @param airport
 * @return true
 * @return false
 */

bool Airport::findNeighbor(Airport *airport)
{
    // Check if the airport is connected
    return connections.find(airport) != connections.end();
}

// Operators

/**
 * @brief Compare if an airport is less than another (by IATA code)
 *
 * @param airport
 * @return true
 * @return false
 */

bool Airport::operator<(Airport airport)
{
    // Get the three characters of the IATA code as integers
    int iata1[3] = {IATA[0], IATA[1], IATA[2]};
    int iata2[3] = {airport.getIATA()[0], airport.getIATA()[1], airport.getIATA()[2]};

    // Compare the IATA codes
    for (int i = 0; i < 3; i++)
    {
        if (iata1[i] < iata2[i])
        {
            return true;
        }
        else if (iata1[i] > iata2[i])
        {
            return false;
        }
    }

    // Else, the IATA codes are equal
    return false;
}

/**
 * @brief Compare if an airport is less than or equal to another (by IATA code)
 *
 * @param airport
 * @return true
 * @return false
 */

bool Airport::operator<=(Airport airport)
{
    // Get the three characters of the IATA code as integers
    int iata1[3] = {IATA[0], IATA[1], IATA[2]};
    int iata2[3] = {airport.getIATA()[0], airport.getIATA()[1], airport.getIATA()[2]};

    // Compare the IATA codes
    for (int i = 0; i < 3; i++)
    {
        if (iata1[i] < iata2[i])
        {
            return true;
        }
        else if (iata1[i] > iata2[i])
        {
            return false;
        }
    }

    // Else, the IATA codes are equal
    return true;
}

/**
 * @brief Compare if an airport is greater than another (by IATA code)
 *
 * @param airport
 * @return true
 * @return false
 */

bool Airport::operator>(Airport airport)
{
    // Get the three characters of the IATA code as integers
    int iata1[3] = {IATA[0], IATA[1], IATA[2]};
    int iata2[3] = {airport.getIATA()[0], airport.getIATA()[1], airport.getIATA()[2]};

    // Compare the IATA codes
    for (int i = 0; i < 3; i++)
    {
        if (iata1[i] > iata2[i])
        {
            return true;
        }
        else if (iata1[i] < iata2[i])
        {
            return false;
        }
    }

    // Else, the IATA codes are equal
    return false;
}

/**
 * @brief Compare if an airport is greater than or equal to another (by IATA code)
 *
 * @param airport
 * @return true
 * @return false
 */

bool Airport::operator>=(Airport airport)
{
    // Get the three characters of the IATA code as integers
    int iata1[3] = {IATA[0], IATA[1], IATA[2]};
    int iata2[3] = {airport.getIATA()[0], airport.getIATA()[1], airport.getIATA()[2]};

    // Compare the IATA codes
    for (int i = 0; i < 3; i++)
    {
        if (iata1[i] > iata2[i])
        {
            return true;
        }
        else if (iata1[i] < iata2[i])
        {
            return false;
        }
    }

    // Else, the IATA codes are equal
    return true;
}

/**
 * @brief Compare two airports (by IATA code)
 *
 * @param airport
 * @return true
 * @return false
 */

bool Airport::operator==(Airport airport)
{
    // Compare the IATA codes
    return IATA == airport.getIATA();
}

/**
 * @brief Compare two airports (by IATA code)
 *
 * @param airport
 * @return true
 * @return false
 */

bool Airport::operator!=(Airport airport)
{
    // Compare the IATA codes
    return IATA != airport.getIATA();
}

#endif // AIRPORT_CPP