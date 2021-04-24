#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <ctype.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_ttf.h>
#include <string.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL.h> 
#define CAMERA_W 800 
#define CAMERA_H 626 

/**
* @struct Background
* @brief struct for background
*/
typedef struct {
	               
SDL_Rect scroll; /*!<Rectangle*/ 
SDL_Surface *bg; /*!<Surface. */ 
int speed;
int sens;
}background;
typedef struct {
SDL_Surface *p[6];
SDL_Rect pp;
}joueur;
void initialiser_joueur1(joueur *j);
void initialiser_joueur2(joueur *j);
//void partage(joueur *j1, joueur *j2 , background *b1, background *b2);
void initialiser_background1(background *b);
void initialiser_background2(background *b);	
void initialiser_background(background *bg,char url[]);            
void afficher_background(SDL_Surface *screen,background bg);
void scrolling_Left(background *bg);
void scrolling_Right(background *bg);
void scrolling_Up(background *bg);
void scrolling_Down(background *bg);



