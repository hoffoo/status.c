#include "status.h"

void init_mem() __attribute__((constructor));
void print_mem();

char memfree[LINE_LEN];

void init_mem() {

    FILE* f = fopen("/proc/meminfo", "r");


    memset(memfree, 0, LINE_LEN);

    get_line(f, "MemFree", memfree);

    plugin(print_mem);
}

void print_mem() {

    printf("%.0fMB", get_float(memfree)/1024);
}
