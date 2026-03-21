/**
 * nani
 * Language identification using trigram profiles
 * Identification module
 *
 * @brief Language identification using trigram profiles
 * @author The (not so) helpful university
 */

#ifndef NANI_H
#define NANI_H

#include <array>
#include <map>
#include <string>

// File paths for resources
#define LANGUAGE_PROFILES_PATH "resources/language_profiles/"
#define LANGUAGE_NAMES_FILE "resources/language_names.csv"

/**
 * @brief Type for representing a trigram (array of 3 characters)
 */
using Trigram = std::array<char, 3>;

/**
 * @brief Type for representing a language profile (map of trigrams to their frequencies)
 */
using LanguageProfile = std::map<Trigram, float>;

/**
 * @brief Type for representing language codes and their language profiles
 */
using LanguageProfiles = std::map<std::string, LanguageProfile>;

/**
 * @brief Type for representing language codes and their names
 */
using LanguageNames = std::map<std::string, std::string>;

/**
 * @brief Loads language profiles from the resources directory
 *
 * @param language_profiles The map to load the language profiles into
 * @param language_names The map to load the language codes and their names into
 *
 * @return true if the language profiles were loaded successfully, false otherwise
 */
bool LoadLanguageProfiles(LanguageProfiles &language_profiles, LanguageNames &language_names);

/**
 * @brief Identifies the language of the given text using the provided language profiles
 *
 * @param language_profiles The language profiles to use for identification
 * @param text The text to identify the language of
 *
 * @return The identified language code, or an empty string if the language could not be identified
 */
std::string IdentifyLanguage(LanguageProfiles &language_profiles, const char *text);

#endif
