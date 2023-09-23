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
}

// Destructor

/**
 * @brief Destroy the Airport:: Airport object
 *
 */

Airport::~Airport()
{
}

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

    // Add the data
    str += "Name: " + name + "\n";
    str += "City: " + city + "\n";
    str += "Country: " + country + "\n";
    str += "IATA: " + IATA + "\n";
    str += "Latitude: " + to_string(latitude) + "\n";
    str += "Longitude: " + to_string(longitude) + "\n";

    // Return the string
    return str;
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