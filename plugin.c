#include "plugin.h"
#include <stdio.h>

void (*fns[MAX_PLUGINS]) ();
int fnsidx = 0;

void plugin(void* p) {

    fns[fnsidx++] = p;
}

void unrwap_plugins() {

    for (int i = 0; i < fnsidx; i++) {
        (*fns[i])();
        if (i+1 != fnsidx) {
            printf(" ");
        }
    }
}
