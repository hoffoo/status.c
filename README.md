Status indicator

Right now it only supports time and battery state. It prints the status to stdout.

I use it like this in my .xinitrc:

```bash

while true
do
    xsetroot -name "$(status.o)"
    sleep 1
done &

```
