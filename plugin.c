#include "plugin.h"
#include <stdio.h>

int (*fns[MAX_PLUGINS]) (char *);
int pidx = 0;

void plugin(void* p) {

    if (pidx > MAX_PLUGINS) {
        printf("too many plugins");
        return;
    }

    fns[pidx++] = p;
}

void unrwap_plugins() {

    char str[50];
    for (int i = 0; i < pidx; i++) {
        char s = (char)(*fns[i])(str);
        printf("%c%s%c ", s, str, STATE_RESET);
    }
    printf("\n");
}
