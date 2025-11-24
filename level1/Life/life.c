#include "life.h"

void print_board(t_game *game)
{
    for (int i = 0; i < game->height; i++)
    {
        for (int j = 0; j < game->width; j++)
        {
            putchar(game->board[i][j]);
        }
        putchar('\n');
    }
}

void free_board(t_game *game)
{
    if (game->board)
    {
        for (int i = 0; i < game->height; i++)
        {
            if (game->board[i])
                free(game->board[i]);
        }
        free(game->board);
    }
    return ;
}

void free_temp_board(char **temp_board, t_game *game)
{
    if (temp_board)
    {
        for (int i = 0; i < game->width; i++)
        {
            if (temp_board[i])
                free(temp_board[i]);
        }
        free(temp_board);
    }
    return ;
}

int init_game(t_game *game, char **argv)
{
    game->width = atoi(argv[1]);
    game->height = atoi(argv[2]);
    game->iterations = atoi(argv[3]);
    game->pen = 0;
    game->board = (char **)malloc((sizeof(char *)) * game->height);
    if (!game->board)
        return (0);
    for (int i = 0; i < game->height; i++)
    {
        game->board[i] = (char *)malloc(sizeof(char) * game->width);
        if (!game->board[i])
        {
            free_board(game);
            return (0);
        }
        for (int j = 0; j < game->width; j++)
        {
            game->board[i][j] = ' ';
        }
    }
    return (1);
}

void draw_board(t_game *game)
{
    int i = 0;
    int j = 0;
    char key;

    while (read(STDIN_FILENO, &key, 1) != 0)
    {
        if (key == 'w' && i > 0)
            i--;
        if (key == 'a' && j > 0)
            j--;
        if (key == 's' && i < (game->height - 1))
            i++;
        if (key == 'd' && j < (game->width - 1))
            j++;
        if (key == 'x')
            game->pen = !(game->pen);
        if (game->pen)
            game->board[i][j] = '0';
    }
    return ;
}

int ft_alive_count(t_game *game, int i, int j)
{
    int x = j;
    int y = i;
    int alive_count = 0;

    if ((x + 1) < game->width && game->board[y][x + 1] == '0')
        alive_count++;
    if (((x + 1) < game->width && (y + 1) < game->height) && game->board[y + 1][x + 1] == '0')
        alive_count++;
    if ((y + 1) < game->height && game->board[y + 1][x] == '0')
        alive_count++;
    if (((x - 1) >= 0 && (y + 1) < game->height) && game->board[y + 1][x - 1] == '0')
        alive_count++;
    if ((x - 1) >= 0 && game->board[y][x - 1] == '0')
        alive_count++;
    if (((x - 1) >= 0 && (y - 1) >= 0) && game->board[y - 1][x - 1] == '0')
        alive_count++;
    if ((y - 1) >= 0 && game->board[y - 1][x] == '0')
        alive_count++;
    if (((y - 1) >= 0 && (x + 1) < game->width) && game->board[y - 1][x + 1] == '0')
        alive_count++;
    return (alive_count);
}

int play_game(t_game *game)
{
    char **temp_board = (char **)malloc(sizeof(char *) * game->height);
    if (!temp_board)
        return (0);
    for (int i = 0; i < game->height; i++)
    {
        temp_board[i] = (char *)malloc(sizeof(char) * game->width);
        if (!temp_board[i])
        {
            free_board(game);
            free_temp_board(temp_board, game);
            return (0);
        }
    }
    for (int i = 0; i < game->height; i++)
    {
        for (int j = 0; j < game->width; j++)
        {
            int alive_count = ft_alive_count(game, i, j);
            if (game->board[i][j] == '0')
            {
                if (alive_count == 2 || alive_count == 3)
                    temp_board[i][j] = '0';
                else
                    temp_board[i][j] = ' ';
            }
            else if (game->board[i][j] == ' ')
            {
                if (alive_count == 3)
                    temp_board[i][j] = '0';
                else
                    temp_board[i][j] = ' ';
            }
        }
    }
    free_board(game);
    game->board = temp_board;
    return (1);
}

int main(int argc, char **argv)
{
    if (argc != 4)
        return (1);
    t_game game;
    if (!init_game(&game, argv))
        return (1);
    draw_board(&game);
    for (int i = 0; i < game.iterations; i++)
    {
        if (!play_game(&game))
            return (1);
    }
    print_board(&game);
    free_board(&game);
    return (0);
}