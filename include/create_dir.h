#ifndef CREATE_DIR_H
#define CREATE_DIR_H
#ifdef _WIN32
    #include <direct.h>
    #define MKDIR(path) _mkdir(path)
#else
    #include <sys/stat.h>
    #include <sys/types.h>
    #define MKDIR(path) mkdir(path, 0755)
#endif
int create_directory(const char *dir_name);
#endif