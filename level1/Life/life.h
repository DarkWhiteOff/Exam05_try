#ifndef LIFE
#define LIFE

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_game
{
    int width;
    int height;
    int iterations;
    int pen;
    char **board;

} t_game;

void free_board(t_game *game);
int init_game(t_game *game, char **argv);
void draw_board(t_game *game);

#endif