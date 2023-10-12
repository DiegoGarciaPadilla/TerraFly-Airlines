/**
 * @file CSVReader.h
 * @author DiegoGarciaPadilla
 * @brief Definition of the CSVReader class
 * @version 0.1
 * @date 2023-10-12
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef CSVREADER_H
#define CSVREADER_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class CSVReader
{
public:
    // Constructors
    CSVReader(); // Construct a new CSVReader:: CSVReader object

    // Methods
    vector<vector<string>> read(string, char); // Read a CSV file and return a vector of vectors of strings
};

#endif // CSVREADER_H
