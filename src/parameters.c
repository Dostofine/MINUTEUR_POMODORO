#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dirent.h>
#include "clear.h"
#include "colors.h"
#include "text_styles.h"
#include "parameters.h"
#include "Menu.h"
#include "helper.h"

void Setsound()
{
    char soundname[100];
    bool verifier = true;
    while (verifier)
    {
        printf("\n\n");
        printf(STYLE_BOLD GREEN
               "       ╔══════════════════════════╗\n"
               "       ║sons de l'horloge pomodoro║\n"
               "       ╚══════════════════════════╝\n" STYLE_RESET RESET);

        DIR *dir = opendir("pomodoro_files/pomodoro_clock_sounds");
        if (dir)
        {
            // print all files
            struct dirent *entry;
            while ((entry = readdir(dir)) != NULL)
            {
                if (entry->d_name[0] == '.')
                    continue;
                printf(STYLE_BOLD GREEN "       ║ %-24s ║\n" STYLE_RESET RESET, entry->d_name);
            }

            printf(STYLE_BOLD GREEN "       ╚══════════════════════════╝\n" STYLE_RESET RESET);
            printf(STYLE_BOLD BLUE "\n\n        > entrer le nom du fichier son que vous voulez: " STYLE_RESET RESET);

            fgets(soundname, sizeof(soundname), stdin);
            soundname[strcspn(soundname, "\n")] = '\0';
            // check if file exists
            rewinddir(dir);
            while ((entry = readdir(dir)) != NULL)
            {
                if (entry->d_name[0] == '.')
                    continue;
                if (strcmp(soundname, entry->d_name) == 0)
                {
                    verifier = false;
                }
            }

            closedir(dir);
        }
        else
        {
            printf("       Erreur: dossier introuvable.\n");
            return;
        }
    }

    FILE *file = fopen("pomodoro_parameters/clock_sound.dat", "wb");
    if (file)
    {
        soundname[strcspn(soundname, "\0")] = '\n';
        fwrite(soundname, sizeof(char), strlen(soundname), file);
        fclose(file);
    }

    clear();
    MenuPricipale();
}
void ParameteresMenu()
{
    unsigned int choice;

    printf(
        GREEN "         ╔══════════════════════════════════════════════╗\n" RESET YELLOW "         ║              les paramètres                  ║\n" RESET GREEN "         ╠══════════════════════════════════════════════╣\n" RESET YELLOW "         ║1) paramètres de la voix                      ║\n" RESET GREEN "         ╚══════════════════════════════════════════════╝\n" RESET);

    read_int(&choice);

    switch (choice)
    {
    case 1:
        Setsound();
        break;
    default:
        ParameteresMenu();
        break;
    }
}