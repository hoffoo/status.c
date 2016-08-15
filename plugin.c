#include "plugin.h"
#include <stdio.h>
#include <string.h>

int (*fns[MAX_PLUGINS]) (char *);
int pidx = 0;

void plugin(void* p) {

    if (pidx > MAX_PLUGINS) {
        printf("too many plugins");
        return;
    }

    fns[pidx++] = p;
}

void unrwap_plugins(conf *cfg) {

    char str[50];
    memset(&str, 0, 50);
    for (int i = 0; i < pidx; i++) {
        char cur_state = (char)(*fns[i])(str);
        if (cfg->color) {
            printf("%c%s%c ", cur_state, str, STATE_RESET);
        } else {
            printf("%s ", str);
        }
    }
}
