#include "plugin.h"
#include <string.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int (*fns[MAX_PLUGINS]) (char *);
int pidx = 0;

void plugin(void* p) {

    if (pidx > MAX_PLUGINS) {
        printf("too many plugins\n");
        exit(1);
    }

    fns[pidx++] = p;
}

void unrwap_plugins(conf *cfg) {

    char str[50];
    memset(&str, 0, 50);
    for (int i = 0; i < pidx; i++) {
        char cur_state = (char)(*fns[i])(str);
        if (cfg->color && cur_state != STATE_OK) {
            putchar(cur_state);
        }
        printf(str);
        if (cfg->color && cur_state != STATE_OK) {
            putchar(STATE_RESET);
        }
        putchar(' ');
    }
}
