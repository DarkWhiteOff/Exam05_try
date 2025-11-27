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
    char **board;

} t_game;

void print_board(t_game *game);
void free_board(t_game *game);
void free_temp_board(char **temp_board, t_game *game);
int init_game(t_game *game, char **argv);
void draw_board(t_game *game);
int ft_alive_count(t_game *game, int i, int j);
int play_game(t_game *game);


#endif