/**
 * CSV reading and writing module
 * 
 * @brief CSV reading and writing module
 * @author The (not so) helpful university
 */

#include <fstream>

#include "csv.h"

bool LoadCSVTable(const std::string filepath, CSVTable &csv_table)
{
    std::ifstream file(filepath, std::ios_base::binary);

    if (!file.is_open())
        return false;

    std::string line;
    while (std::getline(file, line))
    {
        std::vector<std::string> fields;
        std::string field;
        bool in_quotes = false;

        for (size_t i = 0; i < line.size(); i++)
        {
            char c = line[i];

            if (c == '"')
            {
                if (in_quotes && (i + 1 < line.size()) && (line[i + 1] == '"'))
                {
                    field += '"';
                    i++;
                }
                else
                    in_quotes = !in_quotes;
            }
            else if (c == ',' && !in_quotes)
            {
                fields.push_back(field);
                field.clear();
            }
            else
                field += c;
        }

        if (field.size() || !fields.empty())
            fields.push_back(field);
        
        if (!fields.empty())
            csv_table.push_back(fields);
    }

    return true;
}

bool SaveCSVTable(const std::string filepath, CSVTable &csv_table)
{
    std::ofstream file(filepath, std::ios_base::binary);

    if (!file.is_open())
        return false;

    for (const auto& fields : csv_table)
    {
        bool is_first_field = true;
        for (const auto& field : fields)
        {
            if (!is_first_field)
                file.put(',');
            else
                is_first_field = false;

            file.put('"');
            for (char c : field)
            {
                file.put(c);
                if (c == '"')
                    file.put('"');
            }
            file.put('"');
        }

        file.put('\n');

        if (!file.good())
            return false;
    }

    return true;
}
