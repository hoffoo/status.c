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

    sprintf(str, "%.0fMB", get_float(memfree)/1024);
    return STATE_OK;
}
