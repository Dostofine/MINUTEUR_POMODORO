#include "Menu.h"
#include "clear.h"
#include "colors.h"
#include "demarrer_pomodoro.h"
#include "helper.h"
#include "historiques.h"
#include "text_styles.h"
#include "parameters.h"

#include <stdio.h>
#include <stdlib.h>

void print_menu();

void MenuPricipale()
{
  int choice;
  int valid_choice;
  int state;

  print_menu();

  do
  {
    valid_choice = 1;

    printf(STYLE_BOLD BLUE
           "\n                > saisir votre choix: " RESET STYLE_RESET);

    state = read_digit(&choice);
    print_state_info(state);

    if (choice < 1 || choice > 4)
    {
      printf(RED "Error: Invalid choice.\n" RESET);
      valid_choice = 0;
    }

  } while (state != 1 ||
           valid_choice == 0); // User cannot get out. check TODO.md file.

  switch (choice)
  {
  case 1:
    clear();
    pomodoro_session();
    break;
  case 2:
    clear();
    Historique();
    break;
  case 3:
    clear();
    ParameteresMenu();
    break;
  case 4:
    clear();
    printf("\n\n");
    printf(STYLE_BOLD RED);
    printf("             ╔═══════════════════════════════════════════════╗\n");
    printf("            ║ au revoir - merci d'utiliser dosto-pomodoro-CLI ║\n");
    printf("             ╚═══════════════════════════════════════════════╝\n");
    printf(STYLE_RESET RESET);
    exit(0);
    break;
  default:
    MenuPricipale();
    break;
  }
}

void print_menu()
{
  printf("\n\n");
  printf(
      GREEN "             ╔══════════════════════════════════════════════╗\n" RESET YELLOW "             ║      MINUTEUR POMODORO — UCD CyberForce      ║\n" RESET GREEN "             ╠══════════════════════════════════════════════╣\n" RESET YELLOW "             ║ 1) Démarrer un Pomodoro                      ║\n" RESET GREEN "             ║ 2) Voir mes historiques                      ║\n" RESET YELLOW "             ║ 3) les paramètres                            ║\n" RESET GREEN "             ║ 4) Se déconnecter                            ║\n" RESET YELLOW "             ╚══════════════════════════════════════════════╝\n" RESET);
}