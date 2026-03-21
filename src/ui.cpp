/**
 * nani
 * UI module
 *
 * @brief Language identification using trigram profiles
 * @author The (not so) helpful university
 */

#include <fstream>
#include <iostream>
#include <vector>

#include "raylib.h"

#include "ui.h"
#include "nani/nani.h"

/**
 * Loads a file into a buffer and returns it as a vector of chars.
 *
 * @param path The path to the file to load.
 *
 * @return A vector of chars containing the file's contents, or an empty vector if the file could not be loaded.
 */
static bool LoadFile(const std::string &path, std::vector<char> &buffer)
{
    std::ifstream file(path, std::ios::binary | std::ios::ate);
    if (!file.is_open())
        return false;

    std::streamsize file_size = file.tellg();
    file.seekg(0, std::ios::beg);

    buffer.resize(file_size);
    if (!file.read(buffer.data(), file_size))
        return false;

    file.close();

    return true;
}

void RenderNaniUI(LanguageProfiles &language_profiles, LanguageNames &language_names)
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

    SetTargetFPS(60);

    std::string language_code = "---";

    while (!WindowShouldClose())
    {
        // Check for Ctrl+V or Cmd+V to paste text from the clipboard
        if (IsKeyPressed(KEY_V) &&
            (IsKeyDown(KEY_LEFT_CONTROL) ||
             IsKeyDown(KEY_RIGHT_CONTROL) ||
             IsKeyDown(KEY_LEFT_SUPER) ||
             IsKeyDown(KEY_RIGHT_SUPER)))
        {
            const char *text = GetClipboardText();

            language_code = IdentifyLanguage(language_profiles, text);
        }

        // Check for file drop
        if (IsFileDropped())
        {
            FilePathList dropped_files = LoadDroppedFiles();

            if (dropped_files.count == 1)
            {
                std::vector<char> file_buffer;
                if (LoadFile(dropped_files.paths[0], file_buffer))
                    language_code = IdentifyLanguage(language_profiles, file_buffer.data());
            }

            UnloadDroppedFiles(dropped_files);
        }

        // Render UI
        BeginDrawing();

        ClearBackground(BEIGE);

        DrawText("Nani?", 80, 80, 128, BROWN);
#ifdef __APPLE__
        DrawText("Pega con Cmd+V o arrastra un archivo.", 80, 220, 24, BROWN);
#else
        DrawText("Pega con Ctrl+V o arrastra un archivo.", 80, 220, 24, BROWN);
#endif

        std::string language_name;
        if (language_code != "---")
        {
            if (language_names.find(language_code) != language_names.end())
                language_name = language_names[language_code];
            else
                language_name = "Desconocido";
        }

        int language_name_width = MeasureText(language_name.c_str(), 48);
        DrawText(language_name.c_str(), (WINDOW_WIDTH - language_name_width) / 2, 315, 48, BROWN);

        EndDrawing();
    }

    CloseWindow();
}
