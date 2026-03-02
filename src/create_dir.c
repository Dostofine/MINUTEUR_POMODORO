#include <stdio.h>
#include "create_dir.h"
int create_directory(const char *dir_name){
    if (MKDIR(dir_name) == 0) {
        return 1; //created
    }
    return 0; //failed
}
