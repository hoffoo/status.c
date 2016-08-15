
all:
	gcc -std=c99 -l sensors -Wall plugin.c util.c battery.c temp.c mem.c time.c main.c

test: all
	./a.out

install: all
	mv a.out ~/usr/status
