/**
 * nani
 * Language identification using trigram profiles
 * Identification module
 *
 * @brief Language identification using trigram profiles
 * @author The (not so) helpful university
 */

#include <iostream>

#include "csv.h"
#include "nani.h"

/**
 * @brief Decodes a trigram from its hexadecimal string representation
 * 
 * @param encoded_trigram The hexadecimal string representation of the trigram (6 characters, 2 for each byte)
 * @param trigram Output parameter for the decoded trigram
 * 
 * @return true if the trigram was decoded successfully, false otherwise
 */
static bool DecodeTrigram(std::string encoded_trigram, Trigram &trigram)
{
    if (encoded_trigram.size() != 6)
        return false;

    for (size_t i = 0; i < 3; i++)
    {
        std::string byteString = encoded_trigram.substr(i * 2, 2);
        try
        {
            trigram[i] = std::stoul(byteString, nullptr, 16);
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error decoding trigram: " << e.what() << std::endl;
            return false;
        }
    }

    return true;
}

bool LoadLanguageProfiles(LanguageProfiles &language_profiles, LanguageNames &language_names)
{
    // Reads language codes and their names
    std::cout << "Reading language codes..." << std::endl;

    CSVTable language_codes;
    if (!LoadCSVTable(LANGUAGE_NAMES_FILE, language_codes))
        return false;

    // Reads trigram profiles for each language code
    for (auto &language_entry : language_codes)
    {
        if (language_entry.size() != 2)
            continue;

        std::string language_code = language_entry[0];
        std::string language_name = language_entry[1];

        language_names[language_code] = language_name;

        std::cout << "Reading trigram profile for language code \"" << language_code << "\"..." << std::endl;

        CSVTable language_profiles_table;
        if (!LoadCSVTable(LANGUAGE_PROFILES_PATH + language_code + ".csv", language_profiles_table))
            return false;

        LanguageProfile language_profile;
        for (auto &language_profile_entry : language_profiles_table)
        {
            if (language_profile_entry.size() != 2)
                continue;

            std::string encoded_trigram = language_profile_entry[0];
            std::string frequency_string = language_profile_entry[1];

            Trigram trigram;
            if (!DecodeTrigram(encoded_trigram, trigram))
                continue;
            float frequency = std::stof(frequency_string);

            language_profile[trigram] = frequency;
        }

        language_profiles[language_code] = language_profile;
    }

    return true;
}

std::string IdentifyLanguage(LanguageProfiles &language_profiles, const char *text)
{
    return "";
}
