#include "plugin.h"
#include <stdio.h>

void (*fns[MAX_PLUGINS]) ();
int pidx = 0;

void plugin(void* p) {

    if (pidx > MAX_PLUGINS) {
        printf("too many plugins");
        return;
    }

    fns[pidx++] = p;
}

void unrwap_plugins() {

    for (int i = 0; i < pidx; i++) {
        (*fns[i])();
        printf(" ");
    }
}
