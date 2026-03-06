#include <stdio.h>
#include "clear.h"
#include "text_styles.h"
#include "colors.h"
#include "prog_infos.h"
void ProgNameANDVersion(){
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
    printf("                ██████╗  ██████╗ ███╗   ███╗ ██████╗ ██████╗  ██████╗ ██████╗  ██████╗ \n");
    printf("                ██╔══██╗██╔═══██╗████╗ ████║██╔═══██╗██╔══██╗██╔═══██╗██╔══██╗██╔═══██╗\n");
    printf("                ██████╔╝██║   ██║██╔████╔██║██║   ██║██║  ██║██║   ██║██████╔╝██║   ██║\n");
    printf("                ██╔═══╝ ██║   ██║██║╚██╔╝██║██║   ██║██║  ██║██║   ██║██╔══██╗██║   ██║\n");
    printf("                ██║     ╚██████╔╝██║ ╚═╝ ██║╚██████╔╝██████╔╝╚██████╔╝██║  ██║╚██████╔╝\n");
    printf("                ╚═╝      ╚═════╝ ╚═╝     ╚═╝ ╚═════╝ ╚═════╝  ╚═════╝ ╚═╝  ╚═╝ ╚═════╝ \n");
    printf(STYLE_RESET RESET);
    printf(STYLE_BOLD BLUE);
    printf("  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("                    ⏱ Focus. Rest. Repeat. ⏱  \n");
    printf("  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf(STYLE_RESET RESET);
    printf(STYLE_BOLD GREEN);
    printf("                          Version 2.0\n");
    printf(STYLE_RESET RESET);
    printf(STYLE_BOLD YELLOW"\n   > Appuyez sur une touche pour continuer... ");
    getchar();
    clear();
}
