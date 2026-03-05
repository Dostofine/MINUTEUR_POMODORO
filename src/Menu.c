#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "clear.h"
#include "historiques.h"
#include "colors.h"
#include "text_styles.h"
#include "demarrer_pomodoro.h"
#include "Menu.h"
int VerifierChoix()
{
    while(1){
        char buffer[20];
        printf(STYLE_BLINK BLUE "\n                > saisir votre choix: " RESET STYLE_RESET);
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        if (strlen(buffer) == 1 && isdigit((unsigned char)buffer[0]))
            return atoi(buffer);
    }
}
void MenuPricipale()
{
    printf("\n\n");
    printf(
        GREEN "             ╔══════════════════════════════════════════════╗\n" RESET
        YELLOW"             ║      MINUTEUR POMODORO — UCD CyberForce      ║\n" RESET
        GREEN "             ╠══════════════════════════════════════════════╣\n" RESET
        YELLOW"             ║ 1) Démarrer un Pomodoro                      ║\n" RESET
        GREEN "             ║ 2) Voir mes historiques                      ║\n" RESET
        YELLOW"             ║ 3) Se déconnecter                            ║\n" RESET
        GREEN "             ╚══════════════════════════════════════════════╝\n" RESET
    );
    switch (VerifierChoix())
    {
    case 1:
        clear();
        ModType();
        break;
    case 2:
        clear();
        Historique();
        break;
    case 3:
        clear();
        printf("\n\n");
        printf(STYLE_BOLD RED);
        printf("             ╔══════════════════════════════════════════════╗\n");
        printf("            ║    bye-thank u for using dosto-pomodoro-CLI    ║\n");
        printf("             ╚══════════════════════════════════════════════╝\n");
        printf(STYLE_RESET RESET);
        exit(0);
        break;
    default:
        MenuPricipale();
        break;
    }
}