# Scalar Console (Scalarcon) - Makefile

all:	bin/scalar

bin/scalar:				obj/main.o	obj/driver.o	obj/core.o	obj/input.o	obj/input_method.o
	cd obj && gcc main.o driver.o core.o input.o input_method.o -ldrm -o ../bin/scalar

obj/main.o:			src/main.c
	gcc -c src/main.c				-std=gnu23 -Wall	-o obj/main.o

obj/driver.o:		src/display/driver.c	src/display/driver.h
	gcc -c src/display/driver.c		-std=gnu23 -Wall	-o obj/driver.o

obj/core.o:			src/display/core.c src/display/core.h
	gcc -c src/display/core.c				-std=gnu23 -Wall	-o obj/core.o

obj/input.o:		src/input/input.c	src/input/input.h
	gcc -c src/input/input.c		-std=gnu23 -Wall	-o obj/input.o

obj/input_method.o:	src/input/input_method.c	src/input/input_method.h
	gcc -c src/input/input_method.c	-std=gnu23 -Wall	-o obj/input_method.o

clean:
	rm -rf obj/*
	rm -rf bin/*
