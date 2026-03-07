#include "demarrer_pomodoro.h"
#include "colors.h"
#include "create_dir.h"
#include "helper.h"
#include "minuteure.h"
#include "text_styles.h"

#include <dirent.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define FAIL 0
#define SUCC 1
#define TRAN 2
#define EMPTY -1
#define N_DIGIT -2
#define N_ONE_DIGIT -3

#define DEFAULT 1
#define COSTUM 2

// Local helper functions
int read_mod_status(unsigned int *status, char *msg);
void set_status_to_default(mod_type *mod_p);
void print_state_info(int state);
void print_possible_pomo_types();

int ModType() {

  int choice;
  int state;
  int valid_choice;

  print_possible_pomo_types();

  do {
    valid_choice = 1;

    printf(STYLE_BLINK BLUE
           "\n                > saisir votre choix: " RESET STYLE_RESET);

    state = read_digit(&choice);
    print_state_info(state);

    if (choice != DEFAULT && choice != COSTUM) {
      printf(RED "Error: Invalid choice.\n" RESET);
      valid_choice = 0;
    }
  } while (state != SUCC ||
           valid_choice == 0); // User cannot get out. check TODO.md file.

  return choice;
}

void pomodoro_session() {

  time_t now = time(NULL);
  struct tm *t = localtime(&now);
  int len;

  mod_type mod;
  int user_choice = ModType();

  strftime(mod.datetime, sizeof(mod.datetime), "%Y-%m-%d %H:%M:%S", t);

  do {
    printf(STYLE_BOLD BLUE
           "\n                > entrer le nom du pomodoro: " RESET STYLE_RESET);

    read_line(mod.name, sizeof(mod.name));

    len = strlen(mod.name);
    if (len == 0)
      printf(RED "Error: Empty name are not allowed.\n" RESET);

  } while (len == 0);

  if (user_choice == DEFAULT) {
    set_status_to_default(&mod);
  } else if (user_choice == COSTUM) {
    read_mod_status(&mod.TRAVAIL, "entrer le temps de travail");
    read_mod_status(&mod.P_PAUSE, "entrer le temps de courte pause");
    read_mod_status(&mod.G_PAUSE, "entrer le temps de longue pause");
    read_mod_status(&mod.REPETATIONS, "entrer le nombre de répétitions");
    read_mod_status(&mod.SESSIONS, "entrer le nombre de sessions");
  }

  DIR *dir = opendir("setions");
  if (!dir) {
    char dir_name[200];
    strcpy(dir_name, "setions");
    create_directory(dir_name);
  }

  FILE *modtype;
  char path[200];
  snprintf(path, sizeof(path), "setions/%s.dat", mod.name);
  modtype = fopen(path, "wb");
  if (modtype == NULL) {
    printf(RED "Erreur: impossible de créer le fichier '%s'\n" RESET, path);
    return;
  }

  fwrite(&mod, sizeof(mod_type), 1, modtype);
  fclose(modtype);
  SetionMod(mod);
}

void set_status_to_default(mod_type *mod_p) {
  mod_p->TRAVAIL = 25;
  mod_p->P_PAUSE = 5;
  mod_p->G_PAUSE = 30;
  mod_p->REPETATIONS = 4;
  mod_p->SESSIONS = 1;
}

int read_mod_status(unsigned int *status, char *msg) {

  int reading;

  do {
    printf(STYLE_BOLD BLUE "\n                >%s: " RESET STYLE_RESET, msg);

    reading = read_int(status);
    print_state_info(reading);

  } while (reading != SUCC);

  return SUCC;
}

void print_state_info(int state) {
  if (state == FAIL) {
    printf(RED "Error: FAIL.\n" RESET);
  } else if (state == N_DIGIT) {
    printf(RED "Error: Input is not a digit (number).\n" RESET);
  } else if (state == EMPTY) {
    printf(RED "Error: Enpty input.\n");
  } else if (state == N_ONE_DIGIT) {
    printf(RED "Error: Input is not one digit.\n");
  }
}

void print_possible_pomo_types() {
    printf("\n\n");
    printf(
        GREEN "         ╔══════════════════════════════════════════════╗\n" RESET
        YELLOW"         ║               types possibles                ║\n" RESET
        GREEN "         ╠══════════════════════════════════════════════╣\n" RESET
        GREEN "         ║ 1) Type par défaut                           ║\n" RESET
        YELLOW"         ║ 2) Type personnalisé                         ║\n" RESET
        GREEN "         ╚══════════════════════════════════════════════╝\n" RESET
    );
}
