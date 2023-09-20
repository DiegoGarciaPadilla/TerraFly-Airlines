/**
 * @file Airport.h
 * @author DiegoGarciaPadilla
 * @brief Definition of the Airport class
 * @version 0.1
 * @date 2023-09-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef AIRPORT_H
#define AIRPORT_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Airport
{
private:
    string name;      // Name of the airport
    string city;      // City of the airport
    string country;   // Country of the airport
    string IATA;      // IATA code of the airport
    double latitude;  // Latitude of the airport
    double longitude; // Longitude of the airport
    double altitude;  // Altitude of the airport
public:
    // Constructors
    Airport();                                                       // Construct a new Airport:: Airport object
    Airport(string, string, string, string, double, double, double); // Construct a new Airport:: Airport object

    // Destructor
    ~Airport(); // Destruct the Airport:: Airport object

    // Getters
    string getName();      // Get the name of the airport
    string getCity();      // Get the city of the airport
    string getCountry();   // Get the country of the airport
    string getIATA();      // Get the IATA code of the airport
    double getLatitude();  // Get the latitude of the airport
    double getLongitude(); // Get the longitude of the airport
    double getAltitude();  // Get the altitude of the airport

    // Setters
    void setName(string);      // Set the name of the airport
    void setCity(string);      // Set the city of the airport
    void setCountry(string);   // Set the country of the airport
    void setIATA(string);      // Set the IATA code of the airport
    void setLatitude(double);  // Set the latitude of the airport
    void setLongitude(double); // Set the longitude of the airport
    void setAltitude(double);  // Set the altitude of the airport

    // Methods
    string toString(); // Convert the object to a string

    // Operators
    bool operator<(Airport);  // Compare if an airport is less than another (by IATA code)
    bool operator<=(Airport); // Compare if an airport is less than or equal to another (by IATA code)
    bool operator>(Airport);  // Compare if an airport is greater than another (by IATA code)
    bool operator>=(Airport); // Compare if an airport is greater than or equal to another (by IATA code)
    bool operator==(Airport); // Compare two airports (by IATA code)
    bool operator!=(Airport); // Compare two airports (by IATA code)
};

#endif /* AIRPORT_H */