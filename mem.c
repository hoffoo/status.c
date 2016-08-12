#include "status.h"

void init_mem() __attribute__((constructor));
void print_mem();

char swapfree[LINE_LEN];
char memfree[LINE_LEN];

void init_mem() {

    FILE* f = fopen("/proc/meminfo", "r");


    memset(memfree, 0, LINE_LEN);
    memset(swapfree, 0, LINE_LEN);

    get_line(f, "MemFree", memfree);
    get_line(f, "SwapFree", swapfree);

    plugin(print_mem);
}

void print_mem() {

    printf("mem: %.0f swap: %.0f", get_float(memfree)/1024, get_float(swapfree)/1024);
}
