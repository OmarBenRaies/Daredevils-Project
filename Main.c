/** 
* @file Main.c 
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
#include <ctype.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_ttf.h>
#include <string.h>
#include <SDL/SDL_mixer.h>
#include "background.h"
 

 
int main (int argc, char *argv[])
{
   background backg;
   SDL_Event event; 	
   SDL_Surface *screen = NULL;
   Mix_Music *music;

    
   if (SDL_Init (SDL_INIT_VIDEO) == -1) { 
 printf ("Can't init SDL: %s\n", SDL_GetError ()); 
  return EXIT_FAILURE; 
 } 
 
	screen =SDL_SetVideoMode (CAMERA_W, CAMERA_H, 32,  SDL_HWSURFACE | SDL_DOUBLEBUF); 
	
	if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1) 
	{
		printf("%s",Mix_GetError());
   	}
	music = Mix_LoadMUS("musique.mp3");
	Mix_PlayMusic(music,-1);
	
	initialiser_background(&backg, "background.png");
	afficher_background(screen,backg);
	 SDL_Flip(screen); 
	 int continuer=0;
	 SDL_EnableKeyRepeat (SDL_DEFAULT_REPEAT_DELAY,  SDL_DEFAULT_REPEAT_INTERVAL); 
	while (!continuer)
    {
         while (SDL_PollEvent (&event)){
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 1;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                                
                {                  
                    case SDLK_RIGHT:
                        
                         
                                              
                        scrolling_Right(&backg);
                         
                        break;
                    case SDLK_LEFT:
                                       
                        scrolling_Left(&backg); 
                        
                        break;
             	    case SDLK_UP:
                      
                                           
                        scrolling_Up(&backg); 
                        
                        break;
                   case SDLK_DOWN:
                       
                                           
                        scrolling_Down(&backg); 
                        
                        break;
                
                }
                break;           
        }      }  
        afficher_background(screen,backg);
        SDL_Flip(screen);
    } SDL_FreeSurface(screen); 
	Mix_FreeMusic(music);
	SDL_FreeSurface(backg.bg);
		

}
