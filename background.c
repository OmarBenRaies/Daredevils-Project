/**
* @file background.c 
*/
#include "background.h"


/** 
* @brief pour initialiser le premier joueur j  . 
* @param j le joueur   
* @return Nothing 
*/

void initialiser_joueur1(joueur *j)
{
    j->p[0]=IMG_Load("p1.png");

    j->pp.x = 5;
    j->pp.y = 300;

}
/** 
* @brief pour initialiser le deuxieme joueur j  . 
* @param j le joueur   
* @return Nothing 
*/
void initialiser_joueur2(joueur *j)
{
    j->p[1]=IMG_Load("p2.png");

    j->pp.x = CAMERA_W/2 + 5;
    j->pp.y = 300;

}
/** 
* @brief pour initialiser The Background b1 pour le partage d'ecran  . 
* @param Background b   
* @return Nothing 
*/
void initialiser_background1(background *b)
{
    b->bg=IMG_Load("background.png");
    b->scroll.x=0;
    b->scroll.y=0;
    b->scroll.w=CAMERA_W/2;
    b->scroll.h=CAMERA_H;
}
/** 
* @brief pour initialiser The Background b2 pour le partage d'ecran  . 
* @param Background b   
* @return Nothing 
*/
void initialiser_background2(background *b)
{
    b->bg=IMG_Load("background.png");
    b->scroll.x=CAMERA_W/2;
    b->scroll.y=0;
    b->scroll.w=CAMERA_W/2;
    b->scroll.h=CAMERA_H;
}
/** 
* @brief pour initialiser The Background b  . 
* @param Background b   
* @return Nothing 
*/
void initialiser_background(background *b, char url[])
	{
	 b->bg=NULL;
        b->bg= IMG_Load (url);
             	       
      b->scroll.x = 0; 
 b->scroll.y = 0; 
 b->scroll.w = b->bg->w; 
 b->scroll.h = b->bg->h; 

	b->speed=2;
	
	}
/** 
* @brief pour afficher The Background b  . 
* @param Background b   
* @return Nothing 
*/
void afficher_background(SDL_Surface *screen,background b)
	{
	//SDL_BlitSurface(b->bg,b->scroll,screen,&b->scroll);
	SDL_BlitSurface (b.bg, &(b.scroll), screen, NULL);			
	}	            
 
/** 
* @brief pour le scrolling a gauche du Background b  . 
* @param Background b   
* @return Nothing 
*/	 
void scrolling_Left(background *b)
	{ if (b->scroll.x != 0) 
 	b->scroll.x--;//gauche
		
	}
	/** 
* @brief pour le scrolling a droite du Background b  . 
* @param Background b   
* @return Nothing 
*/
void scrolling_Right( background *b)
{
  	if (b->scroll.w - b->scroll.x != CAMERA_W) 
 	b->scroll.x++; 
	}
/** 
* @brief pour le scrolling vers le haut du Background b  . 
* @param Background b   
* @return Nothing 
*/	
void scrolling_Up(background *b)

	{
	  if(b->sens==3)//haut
	  	
	  	b->scroll.y += b->speed;
	  if(b->scroll.y <= 0)
	   	b->scroll.y=0;
	  if(b->scroll.y>=8000-600)
		b->scroll.y=8000-600;
		
	}
/** 
* @brief pour le scrolling vers le bas du Background b  . 
* @param Background b   
* @return Nothing 
*/
void scrolling_Down(background *b)
 
	{ if(b->sens==4)//bas
		
		b->scroll.y -= b->speed;
		if(b->scroll.y <= 0)
			b->scroll.y = 0;
		if(b->scroll.y >= 8000-600)
			b->scroll.y = 8000-600;
		
	}

