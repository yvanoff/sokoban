#include <stdlib.h>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#include "struct.h"
#include "menu.h"

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL");
        exit(EXIT_FAILURE);
    }

    SDL_Surface *ecran = NULL;
    blocks board[HEIGHT_BOARD*HEIGHT_BOARD];

    ecran = SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));

    if (ecran == NULL)
    {
        fprintf(stderr, "Impossible de charger la vidéo: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_WM_SetCaption("Mario Sokoban",NULL);

    menu(ecran, board);

    SDL_Quit();
    return EXIT_SUCCESS;
}
