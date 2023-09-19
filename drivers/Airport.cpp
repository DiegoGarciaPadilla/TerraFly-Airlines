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
    altitude = 0;
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
 * @param altitude
 */

Airport::Airport(string name, string city, string country, string IATA, double latitude, double longitude, double altitude)
{
    this->name = name;
    this->city = city;
    this->country = country;
    this->IATA = IATA;
    this->latitude = latitude;
    this->longitude = longitude;
    this->altitude = altitude;
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

/**
 * @brief Get the altitude of the airport
 *
 * @return double
 */

double Airport::getAltitude()
{
    return altitude;
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
 * @brief Set the altitude of the airport
 *
 * @param altitude
 */

void Airport::setAltitude(double altitude)
{
    this->altitude = altitude;
}

// Methods

/**
 * @brief Convert the object to a string
 *
 * @return string
 */

string Airport::toString()
{
    // 
    string str = "";

    str += "Name: " + name + "\n";
    str += "City: " + city + "\n";
    str += "Country: " + country + "\n";
    str += "IATA: " + IATA + "\n";
    str += "Latitude: " + to_string(latitude) + "\n";
    str += "Longitude: " + to_string(longitude) + "\n";
    str += "Altitude: " + to_string(altitude) + "\n";

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
    return IATA < airport.getIATA();
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
    return IATA > airport.getIATA();
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
    return IATA != airport.getIATA();
}

#endif // AIRPORT_CPP