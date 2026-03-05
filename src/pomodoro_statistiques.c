#include <stdio.h>
#include <stdio.h>
#include "colors.h"
#include "demarrer_pomodoro.h"
void statistiques(mod_type mod){
    printf(RED "\n");
    printf("  ╔══════════════════════════════════════════════╗\n");
    printf("  ║        ⏱  DOSTO POMODORO  -  STATUS          ║\n");
    printf("  ╠══════════════════════════╦═══════════════════╣\n");
    printf(RESET);
    printf("  ║  " CYAN  "%-24s" RESET "║  " CYAN "%-17s" RESET "║\n", "CHAMP", "VALEUR");
    printf("  ╠══════════════════════════╬═══════════════════╣\n");
    printf("  ║  " GREEN "%-24s" RESET "║" RESET "  " BLUE "%-17s" RESET "║\n", "Nom du pomodoro",  mod.name);
    printf("  ╠══════════════════════════╬═══════════════════╣\n");
    printf("  ║  " GREEN "%-24s" RESET "║" RESET  BLUE "  %-17u" RESET "║\n", "Travail",         mod.TRAVAIL);
    printf("  ╠══════════════════════════╬═══════════════════╣\n");
    printf("  ║  " GREEN "%-24s" RESET "║" RESET  BLUE "  %-17u" RESET "║\n", "Petite Pause",    mod.P_PAUSE);
    printf("  ╠══════════════════════════╬═══════════════════╣\n");
    printf("  ║  " GREEN "%-24s" RESET "║" RESET  BLUE "  %-17u" RESET "║\n", "Grande Pause",    mod.G_PAUSE);
    printf("  ╠══════════════════════════╬═══════════════════╣\n");
    printf("  ║  " GREEN "%-24s" RESET "║" RESET  BLUE "  %-17u" RESET "║\n", "Sessions",    mod.SESSIONS);
    printf("  ╠══════════════════════════╬═══════════════════╣\n");
    printf("  ║  " GREEN "%-24s" RESET "  ║" RESET "  " BLUE "%-17u"     RESET "║\n", "Répétitions",     mod.REPETATIONS);
    printf("  ╠══════════════════════════╬═══════════════════╣\n");
    printf("  ║  " GREEN "%-24s" RESET "║" RESET  BLUE "%-17s"     RESET "║\n", "Date et Heure",   mod.datetime);
    printf("  ╚══════════════════════════╩═══════════════════╝\n\n");
}

