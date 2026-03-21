/**
 * nani
 * UI module
 * 
 * @brief Language identification using trigram profiles
 * @author The (not so) helpful university
 */

#ifndef UI_H
#define UI_H

#include "nani/nani.h"

// Screen parameters
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 450
#define WINDOW_TITLE "何？"

/**
 * @brief Renders the UI for the nani language identification application
 * 
 * @param language_profiles The language profiles to use for identification
 * @param language_names The language codes and their names to display in the UI
 * 
 * @return void
 */
void RenderNaniUI(LanguageProfiles &language_profiles, LanguageNames &language_names);

#endif
