/**
* @file Main.c 
* @brief Test. 
* @author Rayen Team DareDevils 
* @version 0.2 
* @date Apr 24, 2021 
* 
* Testing program for background scrollilng + Screen Sharing
*/

#include "header.h"

 
int main (int argc, char *argv[])
{
    background backg;
    SDL_Event event; 	
    SDL_Surface *screen = NULL, *trait=NULL;
    Mix_Music *music;
    joueur j1,j2;
    background b1,b2;
    SDL_Rect camera1, camera2, p_trait;

    camera1.x=626;
    camera1.y=00;
    camera1.w=CAMERA_W/2;
    camera1.h=CAMERA_H;

    camera2.x=0;
    camera2.y=00;
    camera2.w=CAMERA_W/2;
    camera2.h=CAMERA_H;

    p_trait.x=CAMERA_W/2;
    p_trait.y=0;
    
   if (SDL_Init (SDL_INIT_VIDEO) == -1) { 
 printf ("Can't init SDL: %s\n", SDL_GetError ()); 
  return EXIT_FAILURE; 
 } 
 
	intro(&screen);

	screen =SDL_SetVideoMode (CAMERA_W, CAMERA_H, 32,  SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF); 
	SDL_WM_SetCaption("DareDevils", NULL);
	
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
                        case SDLK_p :
                        
                        {
 

    SDL_Init(SDL_INIT_VIDEO);

    screen=SDL_SetVideoMode(CAMERA_W,CAMERA_H,16,SDL_HWSURFACE|SDL_RESIZABLE|SDL_DOUBLEBUF);
    initialiser_background1(&b1);
    initialiser_background2(&b2);
    initialiser_joueur1(&j1);
    initialiser_joueur2(&j2);
    trait = IMG_Load("trait.png");

    continuer=0;

    SDL_BlitSurface(b1.bg,&camera1,screen,&b1.scroll);
    SDL_BlitSurface(b2.bg,&camera2,screen,&b2.scroll);
    SDL_BlitSurface(j1.p[0],NULL,screen,&j1.pp);
    SDL_BlitSurface(j2.p[1],NULL,screen,&j2.pp);
    SDL_BlitSurface(trait,NULL,screen,&p_trait);
    SDL_Flip(screen);
    
    SDL_Event event;

    while(continuer==0)
    {
    SDL_BlitSurface(b1.bg,&camera1,screen,&b1.scroll);
    SDL_BlitSurface(b2.bg,&camera2,screen,&b2.scroll);
    SDL_BlitSurface(j1.p[0],NULL,screen,&j1.pp);
    SDL_BlitSurface(j2.p[1],NULL,screen,&j2.pp);
    SDL_BlitSurface(trait,NULL,screen,&p_trait);
    SDL_Flip(screen);

        SDL_WaitEvent(&event);
        switch(event.type)
        {
    case SDL_QUIT:
        continuer=1;
        break;
        case SDL_KEYDOWN :
            switch(event.key.keysym.sym)
            {
                case SDLK_RIGHT:
                      scrolling_Right(&b1);
                         
                        break;
                    case SDLK_LEFT:
                                       
                        scrolling_Left(&b1);
                        break;
                        case SDLK_c:
                        
                         
                                              
                        scrolling_Right(&b2);
                         
                        break;
                    case SDLK_x:
                                       
                        scrolling_Left(&b2);
                        break; 
                    case SDLK_ESCAPE:
                                       
                        continuer=1;
                        break;   
            }
            break;
        }

    }

    

}
                        
                        break;
                        case SDLK_ESCAPE:
                                       
                        continuer=1;
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
