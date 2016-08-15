#include "status.h"

int get_line(FILE* f, char* match, char* line) {

    while(1) {
        char *l = fgets(line, LINE_LEN, f);
        if (!l) {
            return 1;
        }

        if (strstr(l, match)) {
            break;
        }
    }

    return 0;
}

float get_float(char* line) {

    char ints[10];
    unsigned short int c = 0;
    for (unsigned short int i = 0; i < strlen(line); i++) {
        if (line[i] >= '0' && line[i] <= '9') {
            ints[c] = line[i];
            c++;
        } else if (c != 0) {
            ints[c] = '\0';
            break;
        }
    }

    return atoi(ints);
}
