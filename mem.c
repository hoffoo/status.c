#include "status.h"

void init_mem() __attribute__((constructor));
int print_mem(char *str);

char _memfree[LINE_LEN];
float _freemb = 0;

#define MEM_SHOW 2000
#define MEM_WARN 600
#define MEM_CRIT 300

void init_mem() {

    FILE* f = fopen("/proc/meminfo", "r");

    get_line(f, "MemFree", _memfree);
    _freemb = get_float(_memfree)/1024;

    if (_freemb <= MEM_SHOW) {
        plugin(print_mem);
    }
}

int print_mem(char *str) {

    sprintf(str, "%.0fMB", _freemb);

    if (_freemb <= MEM_WARN) {
        return STATE_WARN;
    }

    if (_freemb <= MEM_CRIT) {
        return STATE_CRIT;
    }

    return STATE_OK;
}
