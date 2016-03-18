all: main.o
	gcc -Wall -o sokoban main.o editor.o game.o menu.o move.o level.o print.o -lSDL -lSDL_image -lSDL_ttf

main.o: main.c editor.c editor.h game.c game.h menu.c menu.h move.c move.h level.c level.h print.c print.h struct.h
	gcc -Wall -c main.c editor.c game.c menu.c move.c level.c print.c

clean:
	rm sokoban *.o
