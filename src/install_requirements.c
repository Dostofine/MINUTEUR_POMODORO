#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "install_requirements.h"
#include "clear.h"
void install()
{
    char filepath[200];
    char line[200];
    char commend[250];
    #ifdef _WIN32
        strcpy(filepath,"pomodoro_files/requirements/win_requirements.txt");
    #else
        strcpy(filepath,"pomodoro_files/requirements/linux_requirements.txt");
    #endif
    FILE *path;
    path=fopen(filepath,"r");
    while(fscanf(path, "%[^\n]\n", line) != EOF)
    {
        #ifdef _WIN32
        {
            sprintf(commend,"winget install %s", line);
            system(commend);
        }
        #else
        {
            sprintf(commend,"sudo apt install %s -y", line);
            system(commend);
        }
        #endif
    }
    clear();
}