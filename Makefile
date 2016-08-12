
laptop:
	gcc -Wall plugin.c util.c battery.c mem.c time.c main.c

desktop:
	gcc -Wall plugin.c util.c           mem.c time.c main.c
