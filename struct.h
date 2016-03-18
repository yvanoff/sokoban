#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

#define SIZE_PICT 34
#define WIDTH_BOARD 12
#define HEIGHT_BOARD 12
#define WINDOW_WIDTH SIZE_PICT * WIDTH_BOARD
#define WINDOW_HEIGHT SIZE_PICT * HEIGHT_BOARD

typedef enum directions directions;
enum directions
{
    UP, DOWN, LEFT, RIGHT
};

typedef enum block_types block_types;
enum block_types
{
    EMPTY, WALL, CRATE, OBJECTIVE, MARIO, VALID_CRATE
};

typedef struct blocks blocks;
struct blocks
{
    block_types category;
    int isHiddenObjective;
};

#endif // STRUCT_H_INCLUDED
