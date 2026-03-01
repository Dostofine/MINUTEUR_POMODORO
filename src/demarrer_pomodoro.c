#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "colors.h"
#include "clear.h"
#include "Menu.h"
#include "text_styles.h"
#include "demarrer_pomodoro.h"
#include "minuteure.h"
void ModType(){
    printf("\n\n");
    printf(
        GREEN "         ╔══════════════════════════════════════════════╗\n" RESET
        YELLOW"         ║               possibale types                ║\n" RESET
        GREEN "         ╠══════════════════════════════════════════════╣\n" RESET
        GREEN "         ║ 1) Default type                              ║\n" RESET
        YELLOW"         ║ 2) Costum type                               ║\n" RESET
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
    printf(STYLE_BOLD BLUE "\n                > enter pomodoro name: " RESET STYLE_RESET);
    fgets(mod.name, sizeof(mod.name), stdin);
    mod.name[strcspn(mod.name, "\n")] = '\0';
    if(user_choice==1){
        mod.TRAVAIL=25;
        mod.P_PAUSE=5;
        mod.G_PAUSE=30;
        mod.REPETATIONS=4;
    }
    else if(user_choice==2){
        while(1)
        {
            verifier=true;
            char buffer[20];
            printf(STYLE_BOLD BLUE "\n                > enter the work time: " RESET STYLE_RESET);
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
            printf(STYLE_BOLD BLUE "\n                > enter the short break time: " RESET STYLE_RESET);
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
            printf(STYLE_BOLD BLUE "\n                > enter the long break time: " RESET STYLE_RESET);
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
            printf(STYLE_BOLD BLUE "\n                > enter who much repetations: " RESET STYLE_RESET);
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