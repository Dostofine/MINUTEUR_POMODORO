#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "colors.h"
#include "text_styles.h"
#include "pomodoro_statistiques.h"
#include "demarrer_pomodoro.h"
#include "Menu.h"
void Historique(){
    mod_type mod_hist;
    printf(STYLE_BOLD   GREEN
    "       ╔══════════════════════════╗\n"
    "       ║   Pomodoro historiques   ║\n"
    "       ╚══════════════════════════╝\n"
    STYLE_RESET RESET);

    DIR *dir = opendir("setions/");
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') continue;  // skip hidden files
        printf(STYLE_BOLD GREEN"       ║ %-24s ║\n"STYLE_RESET RESET, entry->d_name);
    }
    printf(STYLE_BOLD GREEN"       ╚══════════════════════════╝\n"STYLE_RESET RESET);
    closedir(dir);
    char filename[100];
    printf(STYLE_BOLD GREEN "Entrer le nom du fichier: "STYLE_RESET RESET);
    fgets(filename, sizeof(filename), stdin);   
    filename[strcspn(filename, "\n")] = 0;
    char path[200];
    snprintf(path, sizeof(path), "setions/%s.dat", filename);
    FILE *file;
    file=fopen(path,"rb");
    if(file==NULL){
        printf("\n\n");
        printf(STYLE_BOLD RED "     >Fichier introuvable.\n" STYLE_RESET RESET);
    }
    else{
        fread(&mod_hist, sizeof(mod_type), 1, file);
        statistiques(mod_hist);
    }
    MenuPricipale();
}