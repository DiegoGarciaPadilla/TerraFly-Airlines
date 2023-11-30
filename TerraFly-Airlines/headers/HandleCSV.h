/**
 * @file HandleCSV.h
 * @author DiegoGarciaPadilla
 * @brief Definition of the HandleCSV class
 * @version 0.1
 * @date 2023-10-12
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef HANDLECSV_H
#define HANDLECSV_H

#include <vector>
#include <string>

using namespace std;

class HandleCSV {
public:
    HandleCSV();
    vector<vector<string>> readCSV(const string, char);
    void writeCSV(const string&, const vector<vector<string>>&);
};

#endif // HANDLECSV_H
