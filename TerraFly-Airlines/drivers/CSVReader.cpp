/**
 * @file CSVReader.cpp
 * @author DiegoGarciaPadilla
 * @brief Implementation of the CSVReader class
 * @version 0.1
 * @date 2023-10-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef CSVREADER_CPP
#define CSVREADER_CPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

#include "../headers/CSVReader.h" // Include the header file

// Constructors

/**
 * @brief Construct a new CSVReader:: CSVReader object
 *
 */

CSVReader::CSVReader() {}

// Methods

/**
 * @brief Read a CSV file and return a vector of vectors of strings
 *
 * @param filename
 * @param separator
 * @return vector<vector<string>>
 */

vector<vector<string>> CSVReader::read(string filename, char separator)
{
    // Create a vector of vector of strings

    vector<vector<string>> data;
    ifstream file(filename);

    // Check if the file is open

    if (!file.is_open())
    {
        cout << "Error opening file" << endl;
        return data;
    }

    // Read the file line by line

    string line;
    while (getline(file, line))
    {
        // Create a vector of strings

        vector<string> row;
        string word = "";

        // Read the line character by character

        for (auto x : line)
        {
            if (x == separator)
            {
                row.push_back(word);
                word = "";
            }
            else
            {
                word = word + x;
            }
        }

        // Push the last word
        row.push_back(word);

        // Push the row
        data.push_back(row);
    }

    // Close the file
    file.close();

    // Return the data
    return data;
}

#endif // CSVREADER_CPP