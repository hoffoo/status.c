#include "status.h"

void getbattery(battery* b) {

    char line[50];
    memset(line, 0, LINE_LEN);

    FILE* f = fopen("/proc/acpi/battery/BAT0/state", "r");
    get_line(f, "charging state", line);
    if(strstr(line, "discharging")) {
        b->state = 0;
    } else if(strstr(line, "charged")) {
        b->state = 2;
    } else {
        // charging state
        b->state = 1;
    }

    get_line(f, "remaining capacity", line);
    float remaining = get_float(line);
    fclose(f);

    f = fopen("/proc/acpi/battery/BAT0/info", "r");
    get_line(f, "last full capacity", line);
    fclose(f);
    float total = get_float(line);

    b->charge = remaining/total*100;
}
