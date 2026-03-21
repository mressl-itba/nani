/**
 * nani
 * UI module
 *
 * @brief Language identification using trigram profiles
 * @author The (not so) helpful university
 */

#include <fstream>
#include <iostream>

#include "raylib.h"

#include "ui.h"

#include "nani/nani.h"

void RenderNaniUI(LanguageProfiles &language_profiles, LanguageNames &language_names)
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

    SetTargetFPS(60);

    std::string language_code = "---";

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_V) &&
            (IsKeyDown(KEY_LEFT_CONTROL) ||
             IsKeyDown(KEY_RIGHT_CONTROL) ||
             IsKeyDown(KEY_LEFT_SUPER) ||
             IsKeyDown(KEY_RIGHT_SUPER)))
        {
            const char *text = GetClipboardText();

            language_code = IdentifyLanguage(language_profiles, text);
        }

        if (IsFileDropped())
        {
            FilePathList dropped_files = LoadDroppedFiles();

            if (dropped_files.count == 1)
            {
                std::string path(dropped_files.paths[0]);

                std::ifstream file(path, std::ios::binary | std::ios::ate);
                if (file.is_open())
                {
                    std::streamsize file_size = file.tellg();
                    file.seekg(0, std::ios::beg);

                    char *text = new char[file_size + 1];
                    text[file_size] = '\0';

                    if (file.read(text, file_size))
                        language_code = IdentifyLanguage(language_profiles, text);

                    delete[] text;

                    file.close();
                }
            }

            UnloadDroppedFiles(dropped_files);
        }

        BeginDrawing();

        ClearBackground(BEIGE);

        DrawText("Nani?", 80, 80, 128, BROWN);
        DrawText("Pega con Ctrl+V o arrastra un archivo.", 80, 220, 24, BROWN);

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
