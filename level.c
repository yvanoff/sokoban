#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "struct.h"
#include "level.h"
#include "game.h"
#include "print.h"

void loadLevel(SDL_Surface *ecran, blocks *board)
{
    FILE *levels = NULL;
    char line[HEIGHT_BOARD*WIDTH_BOARD];
    int i, j;
    SDL_Surface *picture = NULL;
    SDL_Rect positionPicture;

    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));

    levels = fopen("niveaux.lvl","r");

    if (levels == NULL)
    {
        fprintf(stderr, "Impossible de charger les niveaux\n");
        exit(EXIT_FAILURE);
    }

    fgets(line, WIDTH_BOARD*HEIGHT_BOARD+1, levels);

    for (i=0;i<HEIGHT_BOARD;i++)
    {
        for (j=0;j<WIDTH_BOARD;j++)
        {
            printf("%d\n", WIDTH_BOARD*i + j);
            board[WIDTH_BOARD*i + j].isHiddenObjective = 0;
            switch (line[WIDTH_BOARD*i + j])
            {
                case '0':
                    board[WIDTH_BOARD*i + j].category = EMPTY;
                    picture = NULL;
                    break;
                case '1':
                    board[WIDTH_BOARD*i + j].category = WALL;
                    picture = IMG_Load("mur.jpg");
                    break;
                case '2':
                    board[WIDTH_BOARD*i + j].category = CRATE;
                    picture = IMG_Load("caisse.jpg");
                    break;
                case '3':
                    board[WIDTH_BOARD*i + j].category = OBJECTIVE;
                    picture = IMG_Load("objectif.png");
                    break;
                case '4':
                    board[WIDTH_BOARD*i + j].category = MARIO;
                    picture = IMG_Load("mario_bas.gif");
                    break;
                case '5':
                    board[WIDTH_BOARD*i + j].category = VALID_CRATE;
                    picture = IMG_Load("caisse_ok.jpg");
                    break;
            }
            if (picture != NULL)
            {
                positionPicture.x = j*SIZE_PICT;
                positionPicture.y = i*SIZE_PICT;
                SDL_BlitSurface(picture, NULL, ecran, &positionPicture);
                SDL_Flip(ecran);
            }
        }
        printf("\n");
    }

    printText(board);

    fclose(levels);
}

//saveLevel:
//end saveLevel
