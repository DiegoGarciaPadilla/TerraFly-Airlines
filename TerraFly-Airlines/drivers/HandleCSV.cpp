/**
 * @file HandleCSV.cpp
 * @author DiegoGarciaPadilla
 * @brief Implementation of the HandleCSV class
 * @version 0.1
 * @date 2023-10-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef HANDLECSV_CPP
#define HANDLECSV_CPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

#include "../headers/HandleCSV.h" // Include the header file

// Constructors

/**
 * @brief Construct a new CSVReader:: CSVReader object
 *
 */

HandleCSV::HandleCSV() {}

// Methods

/**
 * @brief Read a CSV file and return a vector of vectors of strings
 *
 * @param filename
 * @param separator
 * @return vector<vector<string>>
 */

vector<vector<string>> HandleCSV::readCSV(const string filename, char separator = ',')
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

/**
 * @brief Write a CSV file
 *
 * @param filename
 * @param data
 */

void HandleCSV::writeCSV(const string &filename, const vector<vector<string>> &data)
{
    // Create a file
    ofstream file(filename);

    // Check if the file is open

    if (!file.is_open())
    {
        cout << "Error opening file" << endl;
        return;
    }

    // Write the data

    for (auto row : data)
    {
        for (auto word : row)
        {
            file << word << ",";
        }
        file << "\n";
    }

    // Close the file
    file.close();
}

#endif // HANDLECSV_CPP