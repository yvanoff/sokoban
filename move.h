#ifndef MOVE_H_INCLUDED
#define MOVE_H_INCLUDED

void moveMario(SDL_Surface *ecran, blocks *board, directions direction);

int isValid(blocks *board, directions direction, int mario);

int findMario(blocks *board);

#endif // MOVE_H_INCLUDED
