prog:background.o Main.o 
	gcc background.o Main.o -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf  -g
Main.o:Main.c 
	gcc -c Main.c -g
background.o:background.c 
	gcc -c background.c -g 