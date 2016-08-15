
#include <sensors/sensors.h>

#include "status.h"

#define _SENSORS_CONFIG "/etc/sensors3.conf"

void init_temp() __attribute__((constructor));
int print_temp(char *str);

void init_temp() {

    FILE* f = fopen(_SENSORS_CONFIG, "r");
    if (errno) {
        perror(_SENSORS_CONFIG);
        return;
    }

    if (sensors_init(f)) {
        return;
    }

    plugin(print_temp);
}

int print_temp(char *str) {

    double value = 0;
    double sum = 0;
    int core_count = 0;
    int chip_idx = 0;

    // loop chips
    for (;;) {

        const struct sensors_chip_name *chip = sensors_get_detected_chips(NULL, &chip_idx);
        if (chip == NULL) {
            break;
        }

        // loop chip features
        int feature_idx = 0;
        for (;;) {
            const struct sensors_feature *feature = sensors_get_features(chip, &feature_idx);
            if (feature == NULL) {
                break;
            }
            // only show core temp
            if (!strstr(sensors_get_label(chip, feature), "Core")) {
                continue;
            }

            // get temp
            const struct sensors_subfeature *subfeature = sensors_get_subfeature(chip, feature, SENSORS_SUBFEATURE_TEMP_INPUT);
            if (subfeature == NULL) {
                break;
            }

            if (sensors_get_value(chip, subfeature->number, &value)) {
                printf("WTF\n");
                break;
            }
            sum += value;
            core_count++;
        }

        // NOTE: not freeing anything on purpose
    }

    double avg = sum/core_count;
    sprintf(str, "%0.f°C", avg);

    if (avg > 40) {
        return STATE_WARN;
    } else if (avg > 50) {
        return STATE_CRIT;
    }

    return STATE_OK;
}
