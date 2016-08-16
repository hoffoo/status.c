#include <sys/statvfs.h>

#include "status.h"

#define DISK_WARN 250
#define DISK_CRIT 100

void init_disk() __attribute__((constructor));
int print_disk(char *str);

int _disk_mb = 0;

void init_disk() {

    struct statvfs fs;
    memset(&fs, 0, sizeof(statvfs));

    if (statvfs("/", &fs)) {
        perror("error:");
        return;
    }

    _disk_mb = (fs.f_bsize*fs.f_bavail)/1024/1024;
    if (_disk_mb <= DISK_WARN) {
        plugin(print_disk);
    }
}

int print_disk(char *str) {

    sprintf(str, "/ %dMB", _disk_mb);

    if (_disk_mb <= DISK_CRIT) {
        return STATE_CRIT;
    } else {
        return STATE_WARN;
    }
}
