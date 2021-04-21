#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <ctype.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_ttf.h>
#include <string.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL.h> 
#define CAMERA_W 500 
#define CAMERA_H 300 

typedef struct {
	               
SDL_Rect scroll; 
SDL_Surface *bg;
int speed;
int sens;
}background;
	
void initialiser_background(background *bg,char url[]);            
void afficher_background(SDL_Surface *screen,background bg);
void scrolling_Left(background *bg);
void scrolling_Right(background *bg);
void scrolling_Up(background *bg);
void scrolling_Down(background *bg);



