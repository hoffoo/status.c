#include "status.h"

struct tm *_time;

void init_time() __attribute__((constructor));
void print_time();

void init_time() {

    time_t now = time(NULL);
    _time = localtime(&now);

    plugin(print_time);
}

void print_time() {

    printf("%s", asctime(_time));
}
