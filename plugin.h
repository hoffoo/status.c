#define MAX_PLUGINS 10

#define STATE_OK 26
#define STATE_RESET 26
#define STATE_WARN 28
#define STATE_CRIT 29

void plugin(void*);
void unrwap_plugins();
