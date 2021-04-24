prog:background.o Main.o intro.o
	gcc background.o Main.o intro.o -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf  -g
Main.o:Main.c 
	gcc -c Main.c -g
background.o:background.c 
	gcc -c background.c -g 
intro.o : intro.c
	gcc -o intro.o -c intro.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
