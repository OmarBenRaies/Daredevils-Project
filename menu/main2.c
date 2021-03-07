#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
int main ()
{
Mix_Music *music;
Mix_Chunk *clic;
SDL_Surface *texte=NULL;
SDL_Surface *screen=NULL;
SDL_Surface *image1=NULL;
SDL_Surface *jeu=NULL;
SDL_Surface *option=NULL;
SDL_Surface *play=NULL;
SDL_Surface *settings=NULL;
SDL_Surface *exit=NULL;
SDL_Surface *play1=NULL;
SDL_Surface *settings1=NULL;
SDL_Surface *exit1=NULL;
SDL_Surface *sound1=NULL;
SDL_Surface *sound2=NULL;
SDL_Surface *fullscreen=NULL;
SDL_Surface *sound11=NULL;
SDL_Surface *sound22=NULL;
SDL_Surface *fullscreen1=NULL;
SDL_Event event;
SDL_Rect positionecran;
SDL_Rect positionClic;
TTF_Font *police=NULL;
SDL_Color couleur={0, 0, 0};
int continuer=1;
int isHome = 1;
int Exit = 1;
int Exit1 = 1;
int i=50;
int issettings=0;
int ng=1,op=0,ex=0;

if(SDL_Init(SDL_INIT_VIDEO) != 0)
{
printf("Erreur lors de l'initialisation de la SDL : %s",SDL_GetError());
return (1);
}
TTF_Init();
screen = SDL_SetVideoMode(1400, 1000, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
if (screen == NULL)
{
printf("Erreur lors du placement du mode video : %s",SDL_GetError());
return (1);
}
SDL_WM_SetCaption("Jeu" , NULL);
image1=IMG_Load("menu.png");
if (image1 == NULL)
{
printf("Erreur lors de telechargement de l'image : %s", SDL_GetError());
return (1);
}
jeu=IMG_Load("menu.png");
if(jeu == NULL)
{
printf("Erreur lors du telechargement de l'image jeu : %s",SDL_GetError());
return (1);
}
option=IMG_Load("menu.png");
if(option == NULL)
{
printf("Erreur lors du telechargement de l'image option : %s", SDL_GetError());
return (1);
}
play=IMG_Load("play.png");
if(!play)
{
printf("Erreur lors de telechargement du bouton play: %s", SDL_GetError());
return (1);
}
settings=IMG_Load("settings.png");
if(!settings)
{
printf("Erreur lors de chargement du bouton settings : %s", SDL_GetError());
return (1);
}
exit=IMG_Load("exit.png");
if(!exit)
{
printf("Erreur lors du chargement du bouton exit : %s", SDL_GetError());
return (1);
}
play1=IMG_Load("play1.png");
if(!play1)
{
printf("Erreur lors du chargement du bouton play1 : %s", SDL_GetError());
return (1);
}
settings1=IMG_Load("settings1.png");
if(!settings1)
{
printf("Erreur lors du chargement du bouton settings1 : %s", SDL_GetError());
return (1);
}
exit1=IMG_Load("exit1.png");
if(!exit1)
{
printf("Erreur lors du chargement du bouton exit1 : %s", SDL_GetError());
return (1);
}
sound1=IMG_Load("sound1.png");
if(!sound1)
{
printf("Erreur lors du chargement du bouton sound1 : %s", SDL_GetError());
return (1);
}
sound2=IMG_Load("sound2.png");
if(!sound2)
{
printf("Erreur lors du chargement du bouton sound2 : %s", SDL_GetError());
return (1);
}
sound11=IMG_Load("sound11.png");
if(!sound11)
{
printf("Erreur lors du chargement du bouton sound2 : %s", SDL_GetError());
return (1);
}
fullscreen=IMG_Load("sound22.png");
if(!fullscreen)
{
printf("Erreur lors du chargement du bouton fullscreen : %s", SDL_GetError());
return (1);
}
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{
printf("%s",Mix_GetError());
}
music=Mix_LoadMUS("son.mp3");
Mix_PlayMusic(music, -1);
clic=Mix_LoadWAV("son1.wav");
police = TTF_OpenFont("COMICATE.TTF", 55);
texte = TTF_RenderText_Blended(police, "Daredevils", couleur);
SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255));
positionecran.x=0;
positionecran.y=0;
SDL_BlitSurface(image1, NULL, screen, &positionecran);
positionecran.x=650;
positionecran.y=500;
SDL_BlitSurface(play, NULL, screen, &positionecran);
positionecran.x=650;
positionecran.y=600;
SDL_BlitSurface(settings, NULL, screen, &positionecran);
positionecran.x=650;
positionecran.y=700;
SDL_BlitSurface(exit, NULL, screen, &positionecran);
positionecran.x=300;
positionecran.y=170;
SDL_BlitSurface(texte, NULL, screen, &positionecran);
SDL_Flip(screen);
while (continuer)
{
SDL_WaitEvent(&event);
switch (event.type)
{
case SDL_MOUSEMOTION:
if(isHome==1){
	 if(event.motion.x>=650 && event.motion.x<=800 && event.motion.y>=500 && event.motion.y<=599   )
	{  
		positionecran.x=1700;
		positionecran.y=1200;
		SDL_BlitSurface(play, NULL, screen, &positionecran);
		positionecran.x=650;
		positionecran.y=500;
		SDL_BlitSurface(play1, NULL, screen, &positionecran);
		SDL_Flip(screen);
		
	}else{
		positionecran.x=1700;
		positionecran.y=1200;
		SDL_BlitSurface(play1, NULL, screen, &positionecran);
		positionecran.x=650;
		positionecran.y=500;
		SDL_BlitSurface(play, NULL, screen, &positionecran);
		SDL_Flip(screen);
		
	}
	if(event.motion.x>=650 && event.motion.x<=800 && event.motion.y>=600 && event.motion.y<=699  )
	{  
		positionecran.x=1700;
		positionecran.y=1200;
		SDL_BlitSurface(settings, NULL, screen, &positionecran);
		positionecran.x=650;
		positionecran.y=600;
		SDL_BlitSurface(settings1, NULL, screen, &positionecran);
		SDL_Flip(screen);
		
	}else{
		positionecran.x=1700;
		positionecran.y=1200;
		SDL_BlitSurface(settings1, NULL, screen, &positionecran);
		positionecran.x=650;
		positionecran.y=600;
		SDL_BlitSurface(settings, NULL, screen, &positionecran);
		SDL_Flip(screen);
		
	}
	 if(event.motion.x>=650 && event.motion.x<=800 && event.motion.y>=700 && event.motion.y<=800   )
		{  
			positionecran.x=1700;
			positionecran.y=1200;
			SDL_BlitSurface(exit, NULL, screen, &positionecran);
			positionecran.x=650;
			positionecran.y=700;
			SDL_BlitSurface(exit1, NULL, screen, &positionecran);
			SDL_Flip(screen);
			
		}else{
			positionecran.x=1700;
			positionecran.y=1200;
			SDL_BlitSurface(exit1, NULL, screen, &positionecran);
			positionecran.x=650;
			positionecran.y=700;
			SDL_BlitSurface(exit, NULL, screen, &positionecran);
			SDL_Flip(screen);
			
		}
}
	continue;
case SDL_MOUSEBUTTONUP:
          if(event.button.button==SDL_BUTTON_LEFT)
            
       {
         positionClic.x=event.button.x;
         positionClic.y=event.button.y;

 if(event.button.x>=650 && event.button.x<=800 && event.button.y>=700 && event.button.y<=800  )
{      
issettings=0; 
isHome=0;    
     if(Mix_PlayChannel(-1,clic,0)==-1)
{
return (1);
}
positionecran.x=1700;
positionecran.y=1200;
SDL_BlitSurface(exit, NULL, screen, &positionecran);
positionecran.x=650;
positionecran.y=700;
SDL_BlitSurface(exit1, NULL, screen, &positionecran);

continuer=0;
break;
SDL_Flip(screen);
 continue;               
}
else if(event.button.x>=650 && event.button.x<=800 && event.button.y>=500 && event.button.y<=599 )
{
issettings=0;
isHome=0;
 if(Mix_PlayChannel(-1,clic,0)==-1)
{
return (1);
}
positionecran.x=1700;
positionecran.y=1200;
SDL_BlitSurface(play, NULL, screen, &positionecran);
positionecran.x=650;
positionecran.y=500;
SDL_BlitSurface(image1, NULL, screen, &positionecran);
SDL_BlitSurface(play1, NULL, screen, &positionecran);
SDL_BlitSurface(settings, NULL, screen, &positionecran);
SDL_BlitSurface(exit, NULL, screen, &positionecran);
positionecran.x=0;
positionecran.y=0;
SDL_BlitSurface(jeu, NULL, screen, &positionecran);
SDL_Flip(screen);
continue;             
}
else if(event.button.x>=650 && event.button.x<=800 && event.button.y>= 600 && event.button.y<=699 )
{ 
   issettings=1;
   isHome=0;  
           if(Mix_PlayChannel(-1,clic,0)==-1)
{
return (1);
}
positionecran.x=1700;
positionecran.y=1200;
SDL_BlitSurface(settings, NULL, screen, &positionecran);
positionecran.x=650;
positionecran.y=600;
SDL_BlitSurface(settings1, NULL, screen, &positionecran);
SDL_BlitSurface(image1, NULL, screen, &positionecran);
SDL_BlitSurface(play, NULL, screen, &positionecran);
SDL_BlitSurface(settings, NULL, screen, &positionecran);
SDL_BlitSurface(exit, NULL, screen, &positionecran);
positionecran.x=0;
positionecran.y=0;
SDL_BlitSurface(option, NULL, screen, &positionecran);
positionecran.x=200;
positionecran.y=300;
SDL_BlitSurface(sound1, NULL, screen, &positionecran);
positionecran.x=350;
positionecran.y=300;
SDL_BlitSurface(sound2, NULL, screen, &positionecran);
positionecran.x=500;
positionecran.y=300;
SDL_BlitSurface(fullscreen, NULL, screen, &positionecran);
SDL_Flip(screen);
if(event.button.x>=200 && event.button.x<=277 && event.button.y>= 300 && event.button.y<=377 )
{  
		positionecran.x=1700;
		positionecran.y=1200;
		SDL_BlitSurface(sound1, NULL, screen, &positionecran);
		positionecran.x=200;
		positionecran.y=300;
		SDL_BlitSurface(sound11, NULL, screen, &positionecran);
		SDL_Flip(screen);
i=i-10;
Mix_VolumeMusic(i);
		
	}else{
		positionecran.x=1700;
		positionecran.y=1200;
		SDL_BlitSurface(sound11, NULL, screen, &positionecran);
		positionecran.x=200;
		positionecran.y=300;
		SDL_BlitSurface(sound1, NULL, screen, &positionecran);
		SDL_Flip(screen);
	
i=i-10;
Mix_VolumeMusic(i);
}

continue;
default:
continue;
}
    
            
     }




case SDL_KEYDOWN:
switch(event.key.keysym.sym)
{

case SDLK_DOWN:
                
                    if (ng==1)
                    {
ex=1;
                        ng=0;
                        op=0;

                      positionecran.x=1700;
positionecran.y=1200;
SDL_BlitSurface(exit, NULL, screen, &positionecran);
positionecran.x=650;
positionecran.y=700;
SDL_BlitSurface(exit1, NULL, screen, &positionecran);
SDL_Flip(screen);
continue;

                    }

                    else if(op==1)
                    {
ng=1;
                            op=0;
                            ex=0;
                                          issettings=0;
isHome=0;
if(Mix_PlayChannel(-1,clic,0)==-1)
{
return (1);
}
positionecran.x=1700;
positionecran.y=1200;
SDL_BlitSurface(play, NULL, screen, &positionecran);
positionecran.x=650;
positionecran.y=500;
SDL_BlitSurface(play1, NULL, screen, &positionecran);
SDL_Flip(screen);
continue;

                    }

                    else if (ex==1)
                    {
op=1;
                        ex=0;
                        ng=0;
                       issettings=1;
isHome=0;
if(Mix_PlayChannel(-1,clic,0)==-1)
{
return (1);
}
positionecran.x=1700;
positionecran.y=1200;
SDL_BlitSurface(settings, NULL, screen, &positionecran);
positionecran.x=650;
positionecran.y=600;
SDL_BlitSurface(settings1, NULL, screen, &positionecran);
SDL_Flip(screen);
continue;

                    }
            break;
                   

                case SDLK_UP:
                    
                    if (ng==1)
                    {
ng=0;
                            op=1;
                            ex=0;
                       
                                                   issettings=1;
isHome=0;
if(Mix_PlayChannel(-1,clic,0)==-1)
{
return (1);
}
positionecran.x=1700;
positionecran.y=1200;
SDL_BlitSurface(settings, NULL, screen, &positionecran);
positionecran.x=650;
positionecran.y=600;
SDL_BlitSurface(settings1, NULL, screen, &positionecran);
SDL_Flip(screen);
continue;

                       
                    }
                    else if(op==1)
                    {
ng=0;
                        op=0;
                        ex=1;
                                            positionecran.x=1700;
positionecran.y=1200;
SDL_BlitSurface(exit, NULL, screen, &positionecran);
positionecran.x=650;
positionecran.y=700;
SDL_BlitSurface(exit1, NULL, screen, &positionecran);
SDL_Flip(screen);
continue;

                    }
                    else if (ex==1)
                    {
 op=0;
                        ex=0;
                        ng=1;
                                          issettings=0;
isHome=0;
if(Mix_PlayChannel(-1,clic,0)==-1)
{
return (1);
}
positionecran.x=1700;
positionecran.y=1200;
SDL_BlitSurface(play, NULL, screen, &positionecran);
positionecran.x=650;
positionecran.y=500;
SDL_BlitSurface(play1, NULL, screen, &positionecran);
SDL_Flip(screen);
continue;

                    }
                    
                    break;





case SDLK_z:
positionecran.x=1700;
positionecran.y=1300;
SDL_BlitSurface(sound2, NULL, screen, &positionecran);
positionecran.x=500;
positionecran.y=300;
SDL_BlitSurface(sound22, NULL, screen, &positionecran);
i=i-10;
Mix_VolumeMusic(i);

SDL_Flip(screen);
continue;
case SDLK_x:
positionecran.x=1700;
positionecran.y=1300;
SDL_BlitSurface(sound1, NULL, screen, &positionecran);
positionecran.x=200;
positionecran.y=300;
SDL_BlitSurface(sound11, NULL, screen, &positionecran);
i=i+10;
Mix_VolumeMusic(i);

SDL_Flip(screen);
continue;
case SDLK_f:
positionecran.x=1700;
positionecran.y=1300;
SDL_BlitSurface(fullscreen, NULL, screen, &positionecran);
positionecran.x=350;
positionecran.y=300;
SDL_BlitSurface(fullscreen1, NULL, screen, &positionecran);
SDL_WM_ToggleFullScreen(screen);

SDL_Flip(screen);
continue;


case SDLK_r:
issettings=0;
isHome=1;
positionecran.x=0;
positionecran.y=0;
SDL_BlitSurface(image1, NULL, screen, &positionecran);
positionecran.x=650;
positionecran.y=500;
SDL_BlitSurface(play, NULL, screen, &positionecran);
positionecran.x=650;
positionecran.y=600;
SDL_BlitSurface(settings, NULL, screen, &positionecran);
positionecran.x=650;
positionecran.y=700;
SDL_BlitSurface(exit, NULL, screen, &positionecran);
positionecran.x=300;
positionecran.y=170;
SDL_BlitSurface(texte, NULL, screen, &positionecran);
SDL_Flip(screen);
continue;
case SDLK_q:
if(Mix_PlayChannel(-1,clic,0)==-1)
{
return (1);
}
positionecran.x=1700;
positionecran.y=1200;
SDL_BlitSurface(exit, NULL, screen, &positionecran);
positionecran.x=650;
positionecran.y=700;
SDL_BlitSurface(exit1, NULL, screen, &positionecran);
SDL_Flip(screen);
continue;
case SDLK_p:
issettings=0;
isHome=0;
if(Mix_PlayChannel(-1,clic,0)==-1)
{
return (1);
}
positionecran.x=1700;
positionecran.y=1200;
SDL_BlitSurface(play, NULL, screen, &positionecran);
positionecran.x=650;
positionecran.y=500;
SDL_BlitSurface(play1, NULL, screen, &positionecran);
SDL_Flip(screen);
continue;
case SDLK_o:
issettings=1;
isHome=0;
if(Mix_PlayChannel(-1,clic,0)==-1)
{
return (1);
}
positionecran.x=1700;
positionecran.y=1200;
SDL_BlitSurface(settings, NULL, screen, &positionecran);
positionecran.x=650;
positionecran.y=600;
SDL_BlitSurface(settings1, NULL, screen, &positionecran);
SDL_Flip(screen);
continue;
default:
continue;
}

case SDL_KEYUP:
switch(event.key.keysym.sym)
{

case SDLK_DOWN:
                
                    if (ng==1)
                    {
ex=1;
                        ng=0;
                        op=0;

                      positionecran.x=1700;
positionecran.y=1200;
SDL_BlitSurface(exit1, NULL, screen, &positionecran);
positionecran.x=650;
positionecran.y=700;
SDL_BlitSurface(exit, NULL, screen, &positionecran);
SDL_Flip(screen);
continue;

                    }

                    else if(op==1)
                    {
ng=1;
                            op=0;
                            ex=0;
                                          issettings=0;
isHome=0;
if(Mix_PlayChannel(-1,clic,0)==-1)
{
return (1);
}
positionecran.x=1700;
positionecran.y=1200;
SDL_BlitSurface(play1, NULL, screen, &positionecran);
positionecran.x=650;
positionecran.y=500;
SDL_BlitSurface(play, NULL, screen, &positionecran);
SDL_Flip(screen);
continue;

                    }

                    else if (ex==1)
                    {
op=1;
                        ex=0;
                        ng=0;
                       issettings=1;
isHome=0;
if(Mix_PlayChannel(-1,clic,0)==-1)
{
return (1);
}
positionecran.x=1700;
positionecran.y=1200;
SDL_BlitSurface(settings1, NULL, screen, &positionecran);
positionecran.x=650;
positionecran.y=600;
SDL_BlitSurface(settings, NULL, screen, &positionecran);
SDL_Flip(screen);
continue;

                    }
            break;
                   

                case SDLK_UP:
                    
                    if (ng==1)
                    {
ng=0;
                            op=1;
                            ex=0;
                       
                                                   issettings=1;
isHome=0;
if(Mix_PlayChannel(-1,clic,0)==-1)
{
return (1);
}
positionecran.x=1700;
positionecran.y=1200;
SDL_BlitSurface(settings1, NULL, screen, &positionecran);
positionecran.x=650;
positionecran.y=600;
SDL_BlitSurface(settings, NULL, screen, &positionecran);
SDL_Flip(screen);
continue;

                       
                    }
                    else if(op==1)
                    {
ng=0;
                        op=0;
                        ex=1;
                                            positionecran.x=1700;
positionecran.y=1200;
SDL_BlitSurface(exit1, NULL, screen, &positionecran);
positionecran.x=650;
positionecran.y=700;
SDL_BlitSurface(exit, NULL, screen, &positionecran);
SDL_Flip(screen);
continue;

                    }
                    else if (ex==1)
                    {
 op=0;
                        ex=0;
                        ng=1;
                                          issettings=0;
isHome=0;
if(Mix_PlayChannel(-1,clic,0)==-1)
{
return (1);
}
positionecran.x=1700;
positionecran.y=1200;
SDL_BlitSurface(play1, NULL, screen, &positionecran);
positionecran.x=650;
positionecran.y=500;
SDL_BlitSurface(play, NULL, screen, &positionecran);
SDL_Flip(screen);
continue;

                    }
                    
                    break;




case SDLK_q:
continuer=0;
break;
case SDLK_o:
issettings=1;
isHome=0;
positionecran.x=1700;
positionecran.y=1200;
SDL_BlitSurface(settings1, NULL, screen, &positionecran);
positionecran.x=650;
positionecran.y=600;
SDL_BlitSurface(settings, NULL, screen, &positionecran);
positionecran.x=1700;
positionecran.y=1200;
SDL_BlitSurface(image1, NULL, screen, &positionecran);
SDL_BlitSurface(play, NULL, screen, &positionecran);
SDL_BlitSurface(settings, NULL, screen, &positionecran);
SDL_BlitSurface(exit, NULL, screen, &positionecran);
positionecran.x=0;
positionecran.y=0;
SDL_BlitSurface(option, NULL, screen, &positionecran);
positionecran.x=200;
positionecran.y=300;
SDL_BlitSurface(sound1, NULL, screen, &positionecran);
positionecran.x=350;
positionecran.y=300;
SDL_BlitSurface(sound2, NULL, screen, &positionecran);
positionecran.x=500;
positionecran.y=300;
SDL_BlitSurface(fullscreen, NULL, screen, &positionecran);
SDL_Flip(screen);
continue;

continue;
case SDLK_h:
if(issettings==1)
{
if(Exit1==1){
Mix_HaltMusic();
Exit1=0;
continue;
}else{
Mix_PlayMusic(music, -1);
Exit1=1;

}
}
continue;
case SDLK_p:
issettings=0;
isHome=0;
positionecran.x=1700;
positionecran.y=1200;
SDL_BlitSurface(play1, NULL, screen, &positionecran);
positionecran.x=650;
positionecran.y=500;
SDL_BlitSurface(play, NULL, screen, &positionecran);
positionecran.x=1700;
positionecran.y=1200;
SDL_BlitSurface(image1, NULL, screen, &positionecran);
SDL_BlitSurface(play, NULL, screen, &positionecran);
SDL_BlitSurface(settings, NULL, screen, &positionecran);
SDL_BlitSurface(exit, NULL, screen, &positionecran);
positionecran.x=0;
positionecran.y=0;
SDL_BlitSurface(jeu, NULL, screen, &positionecran);
SDL_Flip(screen);
continue;
default:
continue;
}

case SDL_QUIT:
continuer=0;
break;

 
}
}
Mix_FreeChunk(clic);
Mix_FreeMusic(music);
TTF_CloseFont(police);
TTF_Quit();
SDL_FreeSurface(texte);
SDL_Quit();
return EXIT_SUCCESS;
}
