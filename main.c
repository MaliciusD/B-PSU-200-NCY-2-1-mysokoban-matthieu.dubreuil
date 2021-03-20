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

int screensetup(void)
{
    initscr();
    keypad(stdscr, TRUE);
    return (0);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    struct_t *soko = malloc(sizeof(struct_t));
    call_loop2(soko, av);
    check_info(soko);
    screensetup();
    loop(soko);
    clear();
    for (int i = 0; soko->map[i] != NULL; i++)
            mvprintw(i + LINES / 2 - soko->max_col / 2, COLS /
            2 - soko->max_line / 2, soko->map[i]);
    refresh();
    endwin();
    if (soko->f_blc == 1)
        return (84);
    if (soko->count2 == 1)
        return (0);
    else
        return (1);
}