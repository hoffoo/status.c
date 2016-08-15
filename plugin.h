#define MAX_PLUGINS 10

#define STATE_OK 0x01
#define STATE_RESET 0x01
#define STATE_WARN 0x03
#define STATE_CRIT 0x03

typedef struct conf {
    int color;
} conf;

void plugin(void*);
void unrwap_plugins(conf*);
