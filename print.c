#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "struct.h"
#include "print.h"

void printBoard(SDL_Surface *ecran, blocks *board, directions direction)
{
    int i, j;
    SDL_Surface *picture = NULL;
    SDL_Rect placePicture;

    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));

    for (i = 0; i < HEIGHT_BOARD; i++)
    {
        for (j = 0; j < WIDTH_BOARD; j++)
        {
            switch (board[WIDTH_BOARD*i + j].category)
            {
                case EMPTY:
                    picture = NULL;
                    break;
                case WALL:
                    picture = IMG_Load("mur.jpg");
                    break;
                case CRATE:
                    picture = IMG_Load("caisse.jpg");
                    break;
                case OBJECTIVE:
                    picture = IMG_Load("objectif.png");
                    break;
                case MARIO:
                    switch (direction)
                    {
                        case UP:
                            picture = IMG_Load("mario_haut.gif");
                            break;
                        case DOWN:
                            picture = IMG_Load("mario_bas.gif");
                            break;
                        case LEFT:
                            picture = IMG_Load("mario_gauche.gif");
                            break;
                        case RIGHT:
                            picture = IMG_Load("mario_droite.gif");
                            break;
                    }
                    break;
                case VALID_CRATE:
                    picture = IMG_Load("caisse_ok.jpg");
                    break;
            }
            placePicture.x = j*SIZE_PICT;
            placePicture.y = i*SIZE_PICT;
            if (picture != NULL)
            {
                SDL_BlitSurface(picture, NULL, ecran, &placePicture);
            }
        }
    }
    SDL_Flip(ecran);
}

void printText(blocks *board)
{
    int i, j;
    printf("Board:\n");
    for (i = 0; i < HEIGHT_BOARD; i++)
    {
        for (j = 0; j < WIDTH_BOARD; j++)
        {
            switch (board[WIDTH_BOARD*i + j].category)
            {
                case EMPTY:
                    printf("0");;
                    break;
                case WALL:
                    printf("1");
                    break;
                case CRATE:
                    printf("2");
                    break;
                case OBJECTIVE:
                    printf("3");
                    break;
                case MARIO:
                    printf("4");
                    break;
                case VALID_CRATE:
                    printf("5");
                    break;
            }
        }
        printf("\n");
    }
    printf("\n%d\n", WIDTH_BOARD*(i-1) + (j-1));
}
