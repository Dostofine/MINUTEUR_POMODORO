#include <stdio.h>
#include <stdlib.h>
#include "clock_sound.h"
void PlaySound(char soundname[100])
{
    char soundpath[200];
    char commend[250];
    sprintf(soundpath,"pomodoro_files/pomodoro_clock_sounds/%s",soundname);
    #ifdef _WIN32
    {
        sprintf(commend,"start %s",soundpath);
        system(commend);
    }
    #else
    {
        sprintf(commend,"mpg123 -q 2>/dev/null %s",soundpath);
        system(commend);
    }
    #endif
}