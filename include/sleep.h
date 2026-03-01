#ifndef SLEEP_H
#define SLEEP_H
#ifdef _WIN32
    #include <windows.h>
    #define sleep_sec(s) Sleep((s) * 1000)
#else
    #include <unistd.h>
    #define sleep_sec(s) sleep(s)
#endif
#endif