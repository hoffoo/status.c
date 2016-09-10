# status.c

Status is a quiet status indicator. It avoids clutter by only showing things when they reach a threshold.

![screenshot](screenshot.png)
_note: usually this much output is disabled. thresholds are configured in config.h_

## reports

1. free memory
1. cpu temp
1. battery
1. disk space
1. time

## requirements

1. window manager that shows xsetroot -name somewhere proper (dwm)
1. lm_sensors for cpu temp
1. (optional) for color support http://dwm.suckless.org/patches/statuscolors
1. gcc extended attributes compiler (it uses the constructor attribute)


## about

I use it like this in my .xinitrc:

```bash

while true
do
    xsetroot -name "$(status --color)"
    sleep 1
done &

```

## extra

1. to disable a statistic you can ommit its .c file from the gcc compile line in the Makefile
1. statistics will show up in the order that they were compiled, to reorder simply reorder them in the Makefile
