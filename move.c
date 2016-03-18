#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "struct.h"
#include "move.h"

void moveMario(SDL_Surface *ecran, blocks *board, directions direction)
{
    int mario;

    mario = findMario(board);

    if (isValid(board, direction, mario))
    {
        if (!board[mario].isHiddenObjective)
        {
            board[mario].category = EMPTY;
        }
        else
        {
            board[mario].isHiddenObjective = 0;
            board[mario].category = OBJECTIVE;
        }
        switch (direction)
        {
            case UP:
                switch (board[mario - WIDTH_BOARD].category)
                {
                    case OBJECTIVE:
                        board[mario - WIDTH_BOARD].isHiddenObjective = 1;
                        break;
                    case CRATE:
                        if (board[mario - 2*WIDTH_BOARD].category == OBJECTIVE)
                        {
                            board[mario - 2*WIDTH_BOARD].category = VALID_CRATE;
                        }
                        else
                        {
                            board[mario - 2*WIDTH_BOARD].category = CRATE;
                        }
                        break;
                    case VALID_CRATE:
                        board[mario - WIDTH_BOARD].isHiddenObjective = 1;
                        if (board[mario - 2*WIDTH_BOARD].category == OBJECTIVE)
                        {
                            board[mario - 2*WIDTH_BOARD].category = VALID_CRATE;
                        }
                        else
                        {
                            board[mario - 2*WIDTH_BOARD].category = CRATE;
                        }
                        break;
                 }
                 board[mario - WIDTH_BOARD].category = MARIO;
                 break;
            case DOWN:
                switch (board[mario + WIDTH_BOARD].category)
                {
                    case OBJECTIVE:
                        board[mario + WIDTH_BOARD].isHiddenObjective = 1;
                        break;
                    case CRATE:
                        if (board[mario + 2*WIDTH_BOARD].category == OBJECTIVE)
                        {
                            board[mario + 2*WIDTH_BOARD].category = VALID_CRATE;
                        }
                        else
                        {
                            board[mario + 2*WIDTH_BOARD].category = CRATE;
                        }
                        break;
                    case VALID_CRATE:
                        board[mario + WIDTH_BOARD].isHiddenObjective = 1;
                        if (board[mario + 2*WIDTH_BOARD].category == OBJECTIVE)
                        {
                            board[mario + 2*WIDTH_BOARD].category = VALID_CRATE;
                        }
                        else
                        {
                            board[mario + 2*WIDTH_BOARD].category = CRATE;
                        }
                        break;
                 }                
                 board[mario + WIDTH_BOARD].category = MARIO;
                 break;
            case LEFT:
                switch (board[mario-1].category)
                {
                    case OBJECTIVE:
                        board[mario-1].isHiddenObjective = 1;
                        break;
                    case CRATE:
                        if (board[mario - 2].category == OBJECTIVE)
                        {
                            board[mario - 2].category = VALID_CRATE;
                        }
                        else
                        {
                            board[mario - 2].category = CRATE;
                        }
                        break;
                    case VALID_CRATE:
                        board[mario-1].isHiddenObjective = 1;
                        if (board[mario - 2].category == OBJECTIVE)
                        {
                            board[mario - 2].category = VALID_CRATE;
                        }
                        else
                        {
                            board[mario - 2].category = CRATE;
                        }
                        break;
                }
                board[mario - 1].category = MARIO;
                break;
            case RIGHT:
                switch (board[mario+1].category)
                {
                    case OBJECTIVE:
                        board[mario+1].isHiddenObjective = 1;
                        break;
                    case CRATE:
                        if (board[mario + 2].category == OBJECTIVE)
                        {
                            board[mario + 2].category = VALID_CRATE;
                        }
                        else
                        {
                            board[mario + 2].category = CRATE;
                        }
                        break;
                    case VALID_CRATE:
                        board[mario+1].isHiddenObjective = 1;
                        if (board[mario + 2].category == OBJECTIVE)
                        {
                            board[mario + 2].category = VALID_CRATE;
                        }
                        else
                        {
                            board[mario + 2].category = CRATE;
                        }
                        break;
                }
                board[mario + 1].category = MARIO;
                break;
        }
    }
}

int isValid(blocks *board, directions direction, int mario)
{
    int possibleMove;

    switch (direction)
    {
        case UP:
            if (mario < WIDTH_BOARD)
            {
                possibleMove = 0;
            }
            switch (board[mario - WIDTH_BOARD].category)
            {
                case WALL:
                    possibleMove = 0;
                    break;
                case EMPTY:
                    possibleMove = 1;
                    break;
                case OBJECTIVE:
                    possibleMove = 1;
                    break;
                case MARIO:
                    fprintf(stderr, "Il y a deux Marios !!!\n");
                    exit(EXIT_FAILURE);
                case CRATE:
                    if (mario - WIDTH_BOARD < WIDTH_BOARD)
                    {
                        possibleMove = 0;
                    }
                    else if (board[mario - 2*WIDTH_BOARD].category == EMPTY || board[mario - 2*WIDTH_BOARD].category == OBJECTIVE)
                    {
                        possibleMove = 1;
                    }
                    else
                    {
                        possibleMove = 0;
                    }
                    break;
                 case VALID_CRATE:
                    if (mario - WIDTH_BOARD < WIDTH_BOARD)
                    {
                        possibleMove = 0;
                    }
                    else if (board[mario - 2*WIDTH_BOARD].category == EMPTY || board[mario - 2*WIDTH_BOARD].category == OBJECTIVE)
                    {
                        possibleMove = 1;
                    }
                    else
                    {
                        possibleMove = 0;
                    }
                    break;
            }
            break;
        case DOWN:
            if (mario >= WIDTH_BOARD*(HEIGHT_BOARD-1))
            {
                possibleMove = 0;
            }
            switch (board[mario + WIDTH_BOARD].category)
            {
                case WALL:
                    possibleMove = 0;
                    break;
                case EMPTY:
                    possibleMove = 1;
                    break;
                case OBJECTIVE:
                    possibleMove = 1;
                    break;
                case MARIO:
                    fprintf(stderr, "Il y a deux Marios !!!\n");
                    exit(EXIT_FAILURE);
                case CRATE:
                    if (mario + WIDTH_BOARD >= WIDTH_BOARD*(HEIGHT_BOARD-1))
                    {
                        possibleMove = 0;
                    }
                    else if (board[mario + 2*WIDTH_BOARD].category == EMPTY || board[mario + 2*WIDTH_BOARD].category == OBJECTIVE)
                    {
                        possibleMove = 1;
                    }
                    else
                    {
                        possibleMove = 0;
                    }
                    break;
                 case VALID_CRATE:
                    if (mario + WIDTH_BOARD >= WIDTH_BOARD*(HEIGHT_BOARD-1))
                    {
                        possibleMove = 0;
                    }
                    else if (board[mario + 2*WIDTH_BOARD].category == EMPTY || board[mario + 2*WIDTH_BOARD].category == OBJECTIVE)
                    {
                        possibleMove = 1;
                    }
                    else
                    {
                        possibleMove = 0;
                    }
                    break;
            }
            break;
        case LEFT:
            if (mario%WIDTH_BOARD == 0)
            {
                possibleMove = 0;
            }
            switch (board[mario-1].category)
            {
                case WALL:
                    possibleMove = 0;
                    break;
                case EMPTY:
                    possibleMove = 1;
                    break;
                case OBJECTIVE:
                    possibleMove = 1;
                    break;
                case MARIO:
                    fprintf(stderr, "Il y a deux Marios !!!\n");
                    exit(EXIT_FAILURE);
                case CRATE:
                    if ((mario-1)%WIDTH_BOARD == 0)
                    {
                        possibleMove = 0;
                    }
                    else if (board[mario - 2].category == EMPTY || board[mario - 2].category == OBJECTIVE)
                    {
                        possibleMove = 1;
                    }
                    else
                    {
                        possibleMove = 0;
                    }
                    break;
                 case VALID_CRATE:
                    if ((mario-1)%WIDTH_BOARD == 0)
                    {
                        possibleMove = 0;
                    }
                    else if (board[mario - 2].category == EMPTY || board[mario - 2].category == OBJECTIVE)
                    {
                        possibleMove = 1;
                    }
                    else
                    {
                        possibleMove = 0;
                    }
                    break;
            }
            break;
        case RIGHT:
            if ((mario - (WIDTH_BOARD-1))%WIDTH_BOARD == 0)
            {
                possibleMove = 0;
            }
            switch (board[mario+1].category)
            {
                case WALL:
                    possibleMove = 0;
                    break;
                case EMPTY:
                    possibleMove = 1;
                    break;
                case OBJECTIVE:
                    possibleMove = 1;
                    break;
                case MARIO:
                    fprintf(stderr, "Il y a deux Marios !!!\n");
                    exit(EXIT_FAILURE);
                case CRATE:
                    if ((mario-1)%WIDTH_BOARD == 0)
                    {
                        possibleMove = 0;
                    }
                    else if (board[mario + 2].category == EMPTY || board[mario + 2].category == OBJECTIVE)
                    {
                        possibleMove = 1;
                    }
                    else
                    {
                        possibleMove = 0;
                    }
                    break;
                 case VALID_CRATE:
                    if ((mario-1)%WIDTH_BOARD == 0)
                    {
                        possibleMove = 0;
                    }
                    else if (board[mario + 2].category == EMPTY || board[mario + 2].category == OBJECTIVE)
                    {
                        possibleMove = 1;
                    }
                    else
                    {
                        possibleMove = 0;
                    }
                    break;
            }
            break;
    }

    return possibleMove;
}

int findMario(blocks *board)
{
    int i = 0, trouve = 0;

    while (i < WIDTH_BOARD * HEIGHT_BOARD && (!trouve))
    {
        if (board[i].category == MARIO)
        {
            trouve = 1;
        }
        else
        {
            i++;
        }
    }
    if ((!trouve) && i == WIDTH_BOARD * HEIGHT_BOARD)
    {
        fprintf(stderr, "Impossible de trouver Mario.\n");
        exit(EXIT_FAILURE);
    }
    return i;
}
