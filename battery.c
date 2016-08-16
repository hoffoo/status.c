#include "status.h"

typedef struct {
    int state;
    float charge;
} battery;

void init_battery() __attribute__((constructor));
int get_battery(battery* b);
int print_battery(char *str);

battery* _battery = NULL;

void init_battery() {

    int err = get_battery(_battery);

    if (err) {
        return;
    }

    plugin(print_battery);
}

int get_battery(battery* b) {

    FILE* f = fopen("/proc/acpi/battery/BAT0/state", "r");
    if (errno) {
        errno = 0;
        return 1;
    }

    _battery = malloc(sizeof(battery));

    char line[LINE_LEN];
    memset(line, 0, LINE_LEN);

    if (get_line(f, "charging state", line)) {
        return 1;
    }

    if(strstr(line, "discharging")) {
        b->state = 0;
    } else if(strstr(line, "charged")) {
        b->state = 2;
    } else {
        // charging state
        b->state = 1;
    }

    if (get_line(f, "remaining capacity", line)) {
        return 1;
    }
    float remaining = get_float(line);
    fclose(f);

    f = fopen("/proc/acpi/battery/BAT0/info", "r");
    if (get_line(f, "last full capacity", line)) {
        return 1;
    }
    fclose(f);
    float total = get_float(line);

    b->charge = remaining/total*100;

    return 0;
}

int print_battery(char *str) {

    if (!_battery) {
        return STATE_OK;
    }

    switch(_battery->state){
    case(0):
        sprintf(str, "unplugged %.0f%% ", _battery->charge);
        return STATE_WARN;
    case(1):
        sprintf(str, "charging %.0f%% ", _battery->charge);
        return STATE_OK;
    case(2):
        // battery is full
        return STATE_OK;
    default:
        sprintf(str, "battery unknown");
        return STATE_CRIT;
    }

    // unreachable
    assert(0);
}
