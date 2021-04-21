/** 
* @file background.c 
* @brief Test. 
* @author Rayen Team DareDevils 
* @version 0.1 
* @date Apr 21, 2021 
* 
* Testing program for background scrollilng * 
*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_ttf.h>
#include <string.h>
#include <SDL/SDL_mixer.h>
#include "background.h"



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
	void afficher_background(SDL_Surface *screen,background b)
	{
	//SDL_BlitSurface(b->bg,b->scroll,screen,&b->scroll);
	SDL_BlitSurface (b.bg, &(b.scroll), screen, NULL);			
	}	            
 
	 
	void scrolling_Left(background *b)
	{ if (b->scroll.x != 0) 
 	b->scroll.x--;//gauche
		
	}
	void scrolling_Right( background *b)
{
  	if (b->scroll.w - b->scroll.x != CAMERA_W) 
 	b->scroll.x++; 
	}
	void scrolling_Up(background *b)

	{
	  if(b->sens==3)//haut
	  	
	  	b->scroll.y += b->speed;
	  if(b->scroll.y <= 0)
	   	b->scroll.y=0;
	  if(b->scroll.y>=8000-600)
		b->scroll.y=8000-600;
		
	}
void scrolling_Down(background *b)
 
	{ if(b->sens==4)//bas
		
		b->scroll.y -= b->speed;
		if(b->scroll.y <= 0)
			b->scroll.y = 0;
		if(b->scroll.y >= 8000-600)
			b->scroll.y = 8000-600;
		
	}

