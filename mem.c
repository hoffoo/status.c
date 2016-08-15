#include "status.h"

void init_mem() __attribute__((constructor));
int print_mem(char *str);

char memfree[LINE_LEN];

void init_mem() {

    FILE* f = fopen("/proc/meminfo", "r");


    memset(memfree, 0, LINE_LEN);

    get_line(f, "MemFree", memfree);

    plugin(print_mem);
}

int print_mem(char *str) {

    float freemb = get_float(memfree)/1024;
    sprintf(str, "%.0fMB", freemb);

    if (freemb < 300) {
        return STATE_WARN;
    } else if (freemb < 100) {
        return STATE_CRIT;
    }

    return STATE_OK;
}
