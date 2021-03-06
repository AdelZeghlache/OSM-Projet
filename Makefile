CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
CPPFLAGS = -I/usr/include/libxml2
LDFLAGS = -lSDL2_gfx $(shell pkg-config --libs sdl2 libxml-2.0 check SDL2_ttf)
EXEC = renderer check_calcul

all: $(EXEC)

parsexml.o: include/parsexml.h include/graphics.h src/parsexml.c
	gcc -c src/parsexml.c $(LDFLAGS) $(CPPFLAGS)
	
calcul.o: include/calcul.h src/calcul.c
	gcc -c src/calcul.c
	
graphics.o: include/calcul.h include/graphics.h src/graphics.c
	gcc -c src/graphics.c

check_calcul.o: include/calcul.h tests/check_calcul.c
	gcc -c tests/check_calcul.c $(LDFLAGS)

renderer: parsexml.o calcul.o graphics.o src/renderer.c
	gcc -o $@ $(CPPFLAGS) $^ $(LDFLAGS)

check_calcul: check_calcul.o calcul.o
	gcc -o $@ $^ $(LDFLAGS)
	
run: renderer
	./renderer maps/02_paris_place_des_vosges.osm 
	
clean:
	rm -rf *.o
	
mrproper: clean
	rm -f $(EXEC)
