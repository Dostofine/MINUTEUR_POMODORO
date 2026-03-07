#ifndef DEMARRER_POMODORO_H
#define DEMARRER_POMODORO_H
typedef struct
{
    unsigned int SESSIONS;
    unsigned int TRAVAIL;
    unsigned int P_PAUSE;
    unsigned int G_PAUSE;
    unsigned int REPETATIONS;
    char name[30];
    char datetime[30];
}mod_type;
void print_state_info(int state);

int ModType();
void pomodoro_session();
#endif