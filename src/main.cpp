/**
 * nani
 * Language identification using trigram profiles
 * Main module
 *
 * @brief Language identification using trigram profiles
 * @author The (not so) helpful university
 */

#include <iostream>

#include "ui.h"
#include "nani/nani.h"

int main(int, char *[])
{
    // Load language profiles and names
    LanguageProfiles language_profiles;
    LanguageNames language_names;

    if (!LoadLanguageProfiles(language_profiles, language_names))
    {
        std::cout << "Could not load trigram data." << std::endl;
        return 1;
    }

    // Render the UI
    RenderNaniUI(language_profiles, language_names);

    return 0;
}
