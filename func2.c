/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include <ncurses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "include/my.h"

void loop(struct_t *soko)
{
    //clear();
    for (int i = 0; soko->map[i] != NULL; i++)
        mvprintw(i + LINES / 2 - soko->max_col / 2, COLS /
        2 - soko->max_line / 2, soko->map[i]);
    refresh();
    while (soko->close != 'q') {
        call_loop1(soko);
        if (soko->count == 1) {
            if (soko->close == KEY_LEFT)
                left2(soko);
            if (soko->close == KEY_RIGHT)
                right2(soko);
            if (soko->close == KEY_UP)
                up2(soko);
            if (soko->close == KEY_DOWN)
                down2(soko);
            check_win(soko);
            check_block(soko);
        }
        if (soko->count2 == 1)
            soko->close = 'q';
        if (soko->count3 == 1)
            soko->close = 'q';
        if (soko->f_blc == 1)
            soko->close = 'q'; }
}

void call_loop2(struct_t *soko, char **av)
{
    struct stat buf;
    stat(av[1], &buf);
    int a = 0;
    int b = 0;
    int op = open(av[1], O_RDONLY);
    soko->size_buffer = buf.st_size;
    if (soko->size_buffer == 0)
        return (0);
    soko->buffer = malloc(sizeof(char) * (soko->size_buffer + 1));
    soko->pos_o = malloc(sizeof(char *) * (1000));
    for (int i = 0; i != 1000; i++)
        soko->pos_o[i] = malloc(sizeof(char) * (1000));
    a = read(op, soko->buffer, soko->size_buffer);
    if (a == -1)
        return (84);
    for (int i = 0; soko->buffer[i] != '\n'; i++)
        soko->line++;
    soko->line = soko->line + 1;
    soko->map = my_str_to_wordarray(soko->buffer, '\n');
    check_o(soko);
}

void call_loop1(struct_t *soko)
{
    //clear();
    refresh();
    get_pos(soko);
    check_pos(soko);
        soko->close = getch();
        bind(soko);
        for (int i = 0; soko->map[i] != NULL; i++)
            mvprintw(i + LINES / 2 - soko->max_col / 2, COLS /
            2 - soko->max_line / 2, soko->map[i]);
        check_win(soko);
        check_block(soko);
}

void check_info(struct_t *soko)
{
    for (int i = 0; soko->map[i][0] != '\0'; i++) {
        for (int y = 0; soko->map[i][y] != '\0'; y++) {
            if (soko->map[i][y] != '#' &&
            soko->map[i][y] != ' ' && soko->map[i][y] != 'P' &&
            soko->map[i][y] != 'X' &&
            soko->map[i][y] != '\n' && soko->map[i][y] != 'O')
                soko->f_blc = 1;
            if (i > soko->max_col)
                soko->max_col = i;
            if (y >soko->max_line)
                soko->max_line = y;
        }
    }
    soko->max_line += 1;
    soko->max_col += 1;
}

int check_block(struct_t *soko)
{
    for (int i = 0; soko->map[i][0] != '\0'; i++) {
        for (int y = 0; soko->map[i][y] != '\0'; y++) {
            if (soko->map[i][y] == 'X' && soko->map[i][y + 1] == '#'
            && soko->map[i + 1][y] == '#' ||
            soko->map[i][y] == 'X' && soko->map[i][y - 1] == '#'
            && soko->map[i + 1][y] == '#'
            || soko->map[i][y] == 'X' && soko->map[i][y - 1] == '#'
            && soko->map[i - 1][y] == '#' ||
            soko->map[i][y] == 'X' && soko->map[i][y + 1] == '#'
            && soko->map[i - 1][y] == '#')
                    soko->count_win += 1;
        }
    }
    if (soko->count_win == soko->nb_o)
        soko->count3 = 1;
    else
        soko->count_win = 0;
}