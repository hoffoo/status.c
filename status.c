#include "status.h"

int main() {

    battery b;
    getbattery(&b);

    char *bstate = malloc(sizeof(char)*50);
    switch(b.state){
    case(0):
        sprintf(bstate, "unplugged %.0f%% ", b.charge);
        break;
    case(1):
        sprintf(bstate, "charging %.0f%% ", b.charge);
        break;
    case(2):
        bstate = "";
        break;
    default:
        bstate = "battery unknown ";
    }

    printf("%s%s", bstate, now());
}
