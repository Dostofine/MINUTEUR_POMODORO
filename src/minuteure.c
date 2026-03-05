#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minuteure.h"
#include "demarrer_pomodoro.h"
#include "colors.h"
#include "text_styles.h"
#include "sleep.h"
#include "clear.h"
#include "Menu.h"
#include "pomodoro_statistiques.h"
void SetionMod(mod_type setion_mod)
{
    clear();
    unsigned int travail_temps=setion_mod.TRAVAIL;
    unsigned int P_pause_temps=setion_mod.P_PAUSE;
    unsigned int G_pause_temps=setion_mod.G_PAUSE;
    unsigned int setion_repetitions=setion_mod.REPETATIONS;
    unsigned int N_sessions=setion_mod.SESSIONS;
    char setion_name[30];
    char setion_datetime[30];
    strcpy(setion_name, setion_mod.name);
    strcpy(setion_datetime, setion_mod.datetime);
    statistiques(setion_mod);
    for(int ses=0;ses<N_sessions;ses++)
    {
        for(int rep=0;rep<setion_repetitions;rep++){
            if(rep!=setion_repetitions-1){
                Travail(travail_temps);
                printf("\a");
                printf(STYLE_BOLD BLUE"\n\n Pomodoro %d terminé ! \n\n" STYLE_RESET RESET,rep+1);
                sleep_sec(1);
                PPause(P_pause_temps);
                printf("\a");
                printf(STYLE_BOLD BLUE"\n\n Pause %d terminé ! \n\n" STYLE_RESET RESET,rep+1);
                sleep_sec(1);
            }
            else{
                Travail(travail_temps);
                printf("\a");
                sleep_sec(1);
            }
        }
        printf(STYLE_BOLD BLUE"\n\n Pomodoro terminé ! Bravo ! \n\n" STYLE_RESET RESET);
        GPause(G_pause_temps);
    }
    MenuPricipale();
}
void Travail(unsigned int travail_temps)
{
    unsigned int travail_minuteure;
    travail_minuteure=travail_temps-1;
    for(int minute=0;minute<travail_temps;minute++){
        unsigned int conteur_sec=60;
        for(int sec=0;sec<=60;sec++){
            printf(STYLE_BOLD GREEN "\r        ⏱ Temps de travail : %u : %u "STYLE_RESET RESET ,travail_minuteure,conteur_sec);
            fflush(stdout);
            sleep_sec(1);
            conteur_sec--;
        }
        travail_minuteure--;
    }
}
void PPause(unsigned int P_pause_temps){
    unsigned int ppause_minuteure=P_pause_temps-1;
    for(int minute=0;minute<P_pause_temps;minute++){
        unsigned int conteur_sec=60;
        for(int sec=0;sec<=60;sec++){
            printf(STYLE_BOLD GREEN "\r        ⏱ Courte pause  : %u : %u "STYLE_RESET RESET ,ppause_minuteure,conteur_sec);
            fflush(stdout);
            sleep_sec(1);
            conteur_sec--;
        }
        ppause_minuteure--;
    }

}
void GPause(unsigned int G_pause_temps){
    unsigned int gpause_minuteure=G_pause_temps-1;
    for(int minute=0;minute<G_pause_temps;minute++){ 
        unsigned int conteur_sec=60;
        for(int sec=0;sec<=60;sec++){
            printf(STYLE_BOLD GREEN "\r        ⏱ Longue pause  : %u : %u "STYLE_RESET RESET ,gpause_minuteure,conteur_sec);
            fflush(stdout);
            sleep_sec(1);
            conteur_sec--;
        }
        gpause_minuteure--;
    }
}