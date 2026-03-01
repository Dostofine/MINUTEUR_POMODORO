#include <stdio.h>
#include <stdio.h>
#include "colors.h"
#include "demarrer_pomodoro.h"
void statistiques(mod_type mod){
    char travail_min[20];
    char ppause_min[20];
    char gpause_min[20];
    snprintf(travail_min, sizeof(travail_min), "%u min", mod.TRAVAIL);
    snprintf(ppause_min, sizeof(ppause_min), "%u min", mod.P_PAUSE);
    snprintf(gpause_min, sizeof(gpause_min), "%u min", mod.G_PAUSE);
    printf(RED "\n");
    printf("  ╔══════════════════════════════════════════════╗\n");
    printf("  ║        ⏱  DOSTO POMODORO  -  STATUS          ║\n");
    printf("  ╠══════════════════════════╦═══════════════════╣\n");
    printf(RESET);
    printf("  ║  " CYAN  "%-24s" RESET "║  " CYAN "%-17s" RESET "║\n", "CHAMP", "VALEUR");
    printf("  ╠══════════════════════════╬═══════════════════╣\n");
    printf("  ║  " GREEN "%-24s" RESET "║" RESET "  " BLUE "%-17s" RESET "║\n", "Nom du pomodoro",  mod.name);
    printf("  ╠══════════════════════════╬═══════════════════╣\n");
    printf("  ║  " GREEN "%-24s" RESET "║" RESET  BLUE "  %-17s" RESET "║\n", "Travail",         travail_min);
    printf("  ╠══════════════════════════╬═══════════════════╣\n");
    printf("  ║  " GREEN "%-24s" RESET "║" RESET  BLUE "  %-17s" RESET "║\n", "Petite Pause",    ppause_min);
    printf("  ╠══════════════════════════╬═══════════════════╣\n");
    printf("  ║  " GREEN "%-24s" RESET "║" RESET  BLUE "  %-17s" RESET "║\n", "Grande Pause",    gpause_min);
    printf("  ╠══════════════════════════╬═══════════════════╣\n");
    printf("  ║  " GREEN "%-24s" RESET "  ║" RESET "  " BLUE "%-17u"     RESET "║\n", "Répétitions",     mod.REPETATIONS);
    printf("  ╠══════════════════════════╬═══════════════════╣\n");
    printf("  ║  " GREEN "%-24s" RESET "║" RESET  BLUE "%-17s"     RESET "║\n", "Date et Heure",   mod.datetime);
    printf("  ╚══════════════════════════╩═══════════════════╝\n\n");
}

