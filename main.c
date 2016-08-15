#include "status.h"
#include <stdbool.h>

int main(int argc, char **argv) {

    static struct conf cfg;

    static struct option opts[] = {
        {"color", no_argument, &(cfg.color), 1},
        {0,0,0,0}
    };

    int opt_idx = 0;
    while (true) {
        int c = getopt_long(argc, argv, "", opts, &opt_idx);
        if (c == -1) {
            break;
        }

        switch(c) {
        case 0:
            break;
        default:
            exit(1);
        }
    }

    unrwap_plugins(&cfg);
}

