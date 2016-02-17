#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>

void pause();
int drawPolygon(int nb);

int main(int argc, char *argv[])
{
        SDL_Window *window;
        SDL_Renderer *renderer;
		SDL_Point hexa[7]; //Permet de faire un chemin de points

        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
                SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s\n", SDL_GetError());
                return 3;
        }

        window = SDL_CreateWindow("OpenStreetMap",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,800, 800,SDL_WINDOW_SHOWN); //Création de la fenêtre
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);//Création du renderer associé a la fenêtre

        SDL_SetRenderDrawColor(renderer,233,234,237,255);//La couleur du fond
		SDL_RenderClear(renderer);//Application de la couleur choisis

		SDL_SetRenderDrawColor(renderer,0,0,0,255);

		hexa[0].x = 200;hexa[0].y = 100;
		hexa[1].x = 350;hexa[1].y = 250;
		hexa[2].x = 350;hexa[2].y = 450;
		hexa[3].x = 200;hexa[3].y = 600;
		hexa[4].x = 50;hexa[4].y = 450;
		hexa[5].x = 50;hexa[5].y = 250;
		hexa[6] = hexa[0];

		SDL_RenderDrawLines(renderer,hexa,7);

		SDL_Rect rect = {700,700,50,50};//Perau et de créer un rectangle vide au points 700,700 et de dimension 50,50 
		SDL_RenderDrawRect(renderer,&rect);

		SDL_SetRenderDrawColor(renderer,255,0,0,255);//On change la couleur pour le prochain rectangle

		SDL_Rect rectFill = {600,700,50,50};
		SDL_RenderFillRect(renderer,&rectFill);

		//Dessin d'une ligne droite verticale
		SDL_RenderDrawLine(renderer,480,0,480,800);
		SDL_RenderDrawLine(renderer,500,0,500,800);

		SDL_RenderDrawLine(renderer,490,10,490,80);
		SDL_RenderDrawLine(renderer,490,120,490,190);
		SDL_RenderDrawLine(renderer,490,230,490,300);
		SDL_RenderDrawLine(renderer,490,340,490,410);
		SDL_RenderDrawLine(renderer,490,450,490,520);
		SDL_RenderDrawLine(renderer,490,560,490,630);
		SDL_RenderDrawLine(renderer,490,670,490,740);
		

		SDL_RenderPresent(renderer);

		pause();
 
        SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
        SDL_Quit();
        return 0;
}


void pause()
{
	SDL_Event evenements;
    int terminer = 0;

	while(!terminer)
    {
		SDL_WaitEvent(&evenements);
		
		if(evenements.window.event == SDL_WINDOWEVENT_CLOSE)
			terminer = 1;
    }
}
