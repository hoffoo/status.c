#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define LINE_LEN 50

void get_line(FILE* f, char* match, char* line);
float get_float(char* line);

typedef struct {
    int state;
    float charge;
} battery;

void getbattery(battery* b);
char* now();
