#ifndef DEMARRER_POMODORO_H
#define DEMARRER_POMODORO_H
typedef struct
{
    unsigned int TRAVAIL;
    unsigned int P_PAUSE;
    unsigned int G_PAUSE;
    unsigned int REPETATIONS;
    char name[30];
    char datetime[30];
}mod_type;
void ModType();
void manage_type(int user_choice);
#endif