#include "prog_infos.h"
#include "clear.h"
#include "colors.h"
#include "text_styles.h"
#include <stdio.h>
void ProgNameANDVersion() {
  int c;
  clear();
  printf(STYLE_BOLD RED);
  printf("\n\n");
  printf("        ██████╗  ██████╗ ███████╗████████╗ ██████╗ \n");
  printf("        ██╔══██╗██╔═══██╗██╔════╝╚══██╔══╝██╔═══██╗\n");
  printf("        ██║  ██║██║   ██║███████╗   ██║   ██║   ██║\n");
  printf("        ██║  ██║██║   ██║╚════██║   ██║   ██║   ██║\n");
  printf("        ██████╔╝╚██████╔╝███████║   ██║   ╚██████╔╝\n");
  printf("        ╚═════╝  ╚═════╝ ╚══════╝   ╚═╝    ╚═════╝ \n");
  printf(STYLE_RESET RESET);
  printf("\n\n");
  printf(STYLE_BOLD YELLOW);
  printf("                ██████╗  ██████╗ ███╗   ███╗ ██████╗ ██████╗  "
         "██████╗ ██████╗  ██████╗ \n");
  printf("                ██╔══██╗██╔═══██╗████╗ "
         "████║██╔═══██╗██╔══██╗██╔═══██╗██╔══██╗██╔═══██╗\n");
  printf("                ██████╔╝██║   ██║██╔████╔██║██║   ██║██║  ██║██║   "
         "██║██████╔╝██║   ██║\n");
  printf("                ██╔═══╝ ██║   ██║██║╚██╔╝██║██║   ██║██║  ██║██║   "
         "██║██╔══██╗██║   ██║\n");
  printf("                ██║     ╚██████╔╝██║ ╚═╝ "
         "██║╚██████╔╝██████╔╝╚██████╔╝██║  ██║╚██████╔╝\n");
  printf("                ╚═╝      ╚═════╝ ╚═╝     ╚═╝ ╚═════╝ ╚═════╝  "
         "╚═════╝ ╚═╝  ╚═╝ ╚═════╝ \n");
  printf(STYLE_RESET RESET);
  printf(STYLE_BOLD BLUE);
  printf(
      "  "
      "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("                    ⏱ Focus. Rest. Repeat. ⏱  \n");
  printf(
      "  "
      "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf(STYLE_RESET RESET);
  printf(STYLE_BOLD GREEN);
  printf("                          Version 1.0\n");
  printf(STYLE_RESET RESET);
  printf(STYLE_BOLD YELLOW "\n   > Appuyez sur une touche pour continuer... ");
  if (getchar() != '\n') {
    // clean leftover in `stdin`
    while ((c = getchar()) != '\n' && c != EOF)
      ;
  }
  clear();
}
