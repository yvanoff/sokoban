#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "struct.h"
#include "game.h"
#include "move.h"
#include "print.h"

void play(SDL_Surface *ecran, blocks *board)
{
    int still = 1, keyDown;
    directions choiceDirection;
    SDL_Event event;

    while (still)
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        {
            case SDL_QUIT:
                still = 0;
                break;
            case SDL_KEYUP:
                keyDown = 0;
                break;
            case SDL_KEYDOWN:
                keyDown = 1;
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        still = 0;
                        break;
                    case SDLK_UP:
                        choiceDirection = UP;
                        break;
                    case SDLK_DOWN:
                        choiceDirection = DOWN;
                        break;
                    case SDLK_LEFT:
                        choiceDirection = LEFT;
                        break;
                    case SDLK_RIGHT:
                        choiceDirection = RIGHT;
                        break;
                    case SDLK_z:
                        choiceDirection = UP;
                        break;
                    case SDLK_s:
                        choiceDirection = DOWN;
                        break;
                    case SDLK_q:
                        choiceDirection = LEFT;
                        break;
                    case SDLK_d:
                        choiceDirection = RIGHT;
                        break;
                }
        }
        if (keyDown)
        {
            printf("Appel 1\n");
            printText(board);
            moveMario(ecran, board, choiceDirection);
            printf("Appel 2\n");
            printText(board);
            printBoard(ecran, board, choiceDirection);
            printf("Appel 3\n");
            printText(board);
        }
        if (victory(board))
        {
            still = 0;
            printf("Victory !!\n");
            break;
        }
    }
}

int victory(blocks *board)
{
    int retour = 1, i = 0;

    while (retour && i < WIDTH_BOARD*HEIGHT_BOARD)
    {
        if (board[i].category == OBJECTIVE)
        {
            retour = 0;
        }
        i++;
    }
    return retour;
}
