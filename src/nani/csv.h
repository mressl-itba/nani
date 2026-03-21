/**
 * CSV reading and writing module
 * 
 * @brief CSV reading and writing module
 * @author The (not so) helpful university
 */

#ifndef CSVTABLE_H
#define CSVTABLE_H

#include <string>
#include <vector>

/**
 * @brief Type for representing a CSV table (vector of rows, where each row is a vector of fields)
 */
using CSVTable = std::vector<std::vector<std::string>>;

/**
 * @brief Loads a CSV file into a CSVTable structure
 * 
 * @param path Path to the CSV file
 * @param csv_table Output parameter for the CSV table
 * 
 * @return true if the file was loaded successfully, false otherwise
 */
bool LoadCSVTable(const std::string path, CSVTable &csv_table);

/**
 * @brief Saves a CSVTable structure to a CSV file
 * 
 * @param path Path to the CSV file
 * @param csv_table CSV table to save
 * 
 * @return true if the file was saved successfully, false otherwise
 */
bool SaveCSVTable(const std::string path, CSVTable &csv_table);

#endif
