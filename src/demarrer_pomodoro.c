#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include <time.h>
#include "colors.h"
#include "clear.h"
#include "Menu.h"
#include "text_styles.h"
#include "demarrer_pomodoro.h"
#include "minuteure.h"
#include "create_dir.h"
void ModType(){
    printf("\n\n");
    printf(
        GREEN "         ╔══════════════════════════════════════════════╗\n" RESET
        YELLOW"         ║               types possibles                ║\n" RESET
        GREEN "         ╠══════════════════════════════════════════════╣\n" RESET
        GREEN "         ║ 1) Type par défaut                           ║\n" RESET
        YELLOW"         ║ 2) Type personnalisé                         ║\n" RESET
        GREEN "         ╚══════════════════════════════════════════════╝\n" RESET
    );
    switch (VerifierChoix())
    {
    case 1:
        manage_type(1);
        break;
    case 2:
        manage_type(2);
        break;
    default:
        ModType();
        break;
    }
}
void manage_type(int user_choice)
{
    time_t now=time(NULL);
    struct tm *t = localtime(&now);
    bool verifier;
    mod_type mod;
    strftime(mod.datetime, sizeof(mod.datetime), "%Y-%m-%d %H:%M:%S", t);
    printf(STYLE_BOLD BLUE "\n                > entrer le nom du pomodoro: " RESET STYLE_RESET);
    fgets(mod.name, sizeof(mod.name), stdin);
    mod.name[strcspn(mod.name, "\n")] = '\0';
    if(user_choice==1){
        mod.TRAVAIL=25;
        mod.P_PAUSE=5;
        mod.G_PAUSE=30;
        mod.REPETATIONS=4;
        mod.SESSIONS=1;
    }
    else if(user_choice==2){
        while(1)
        {
            verifier=true;
            char buffer[20];
            printf(STYLE_BOLD BLUE "\n                > entrer le temps de travail: " RESET STYLE_RESET);
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = '\0';
            for(int i=0;i<strlen(buffer);i++){
                if(!isdigit(buffer[i]))
                    verifier=false;
            }
            if(verifier){
                mod.TRAVAIL=atoi(buffer);
                break;
            }
        }
        while(1)
        {
            verifier=true;
            char buffer[20];
            printf(STYLE_BOLD BLUE "\n                > entrer le temps de courte pause: " RESET STYLE_RESET);
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = '\0';
            for(int i=0;i<strlen(buffer);i++){
                if(!isdigit(buffer[i]))
                    verifier=false;
            }
            if(verifier){
                mod.P_PAUSE=atoi(buffer);
                break;}
        }
        while(1)
        {
            verifier=true;
            char buffer[20];
            printf(STYLE_BOLD BLUE "\n                > entrer le temps de longue pause: " RESET STYLE_RESET);
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = '\0';
            for(int i=0;i<strlen(buffer);i++){
                if(!isdigit(buffer[i]))
                    verifier=false;
            }
            if(verifier){
                mod.G_PAUSE=atoi(buffer);
                break;}
        }
        while(1)
        {
            verifier=true;
            char buffer[20];
            printf(STYLE_BOLD BLUE "\n                > entrer le nombre de répétitions: " RESET STYLE_RESET);
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = '\0';
            for(int i=0;i<strlen(buffer);i++){
                if(!isdigit(buffer[i]))
                    verifier=false;
            }
            if(verifier){
                mod.REPETATIONS=atoi(buffer);
                break;}
        }
                while(1)
        {
            verifier=true;
            char buffer[20];
           printf(STYLE_BOLD BLUE "\n                > entrer le nombre de sessions: " RESET STYLE_RESET);
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = '\0';
            for(int i=0;i<strlen(buffer);i++){
                if(!isdigit(buffer[i]))
                    verifier=false;
            }
            if(verifier){
                mod.SESSIONS=atoi(buffer);
                break;}
        }
    }
    DIR *dir=opendir("setions");
    if(!dir){
        char dir_name[200];
        strcpy(dir_name , "setions");
        create_directory(dir_name);
    }
    FILE *modtype;
    char path[200];
    snprintf(path, sizeof(path), "setions/%s.dat", mod.name);
    modtype = fopen(path, "wb");
    if(modtype == NULL) {  
        printf(RED "Erreur: impossible de créer le fichier '%s'\n" RESET, path);
        return;
    }
    fwrite(&mod, sizeof(mod_type), 1, modtype);
    fclose(modtype);
    SetionMod(mod);
}