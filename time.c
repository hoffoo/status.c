#include "status.h"

char* now() {

    time_t now = time(NULL);
    struct tm *t;
    t = localtime(&now);

    return asctime(t);
}
