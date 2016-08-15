#include "status.h"

struct tm *_time;

void init_time() __attribute__((constructor));
int print_time(char *str);

void init_time() {

    time_t now = time(NULL);
    _time = localtime(&now);

    plugin(print_time);
}

int print_time(char *str) {

    sprintf(str, clean_str(asctime(_time)));
    return STATE_OK;
}
