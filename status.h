
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <assert.h>
#include <getopt.h>

#include "config.h"
#include "plugin.h"

#define LINE_LEN 50

int get_line(FILE* f, char* match, char* line);
float get_float(char* line);
char* clean_str(char* str);
