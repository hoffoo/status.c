
all:
	gcc -Wall plugin.c battery.c util.c time.c status.c

desktop:
	gcc -Wall plugin.c util.c time.c status.c
