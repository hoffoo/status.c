
laptop:
	gcc -std=c99 -l sensors -Wall plugin.c util.c temp.c mem.c time.c battery.c main.c

desktop:
	gcc -std=c99 -l sensors -Wall plugin.c util.c temp.c mem.c time.c           main.c
