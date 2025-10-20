all: bin/scalar

bin/scalar:	obj/main.o	obj/monitor.o	obj/display_core.o
	cd obj && gcc main.o monitor.o display_core.o ../lib/libSDL3.a ../lib/libSDL3_ttf.a -lfreetype -lharfbuzz -lplutosvg -lm -o ../bin/scalar

obj/main.o:	src/main.c
	gcc -c -std=gnu23 -Wall src/main.c -o obj/main.o

obj/monitor.o:	src/monitor/monitor.c	src/monitor/monitor.h
	gcc -c -std=gnu23 -Wall src/monitor/monitor.c -o obj/monitor.o

obj/display_core.o:	src/monitor/display_core.c	src/monitor/display_core.h
	gcc -c -std=gnu23 -Wall src/monitor/display_core.c -o obj/display_core.o

clean:
	rm -rf obj/*
	rm -f bin/scalar
