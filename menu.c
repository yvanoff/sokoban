#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "struct.h"
#include "menu.h"
#include "editor.h"
#include "level.h"

void menu(SDL_Surface *ecran, blocks *board)
{
    SDL_Surface *menu = NULL;
    SDL_Rect positionMenu;
    int still = 1;
    SDL_Event event;

    positionMenu.x = 0;
    positionMenu.y = 0;

    menu = IMG_Load("menu.jpg");

    SDL_BlitSurface(menu,NULL,ecran,&positionMenu);
    SDL_Flip(ecran);

    while (still)
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        {
            case SDL_QUIT:
                still = 0;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        still = 0;
                        break;
                    case SDLK_KP1:
                        loadLevel(ecran, board); 
                        play(ecran, board);
                        break;
                    case SDLK_KP2:
                        //editLevel(ecran, board);
                        break;
                }
        }
    }
}
