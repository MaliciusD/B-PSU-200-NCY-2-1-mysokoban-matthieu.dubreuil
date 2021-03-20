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

void left2(struct_t *soko)
{
    if (soko->map[soko->posx][soko->posy - 1] != '#') {
        if (soko->map[soko->posx][soko->posy - 1] == 'X' &&
        soko->map[soko->posx][soko->posy - 2] != 'X' &&
        soko->map[soko->posx][soko->posy - 2] != '#') {
            soko->map[soko->posx][soko->posy] = 'O';
            soko->map[soko->posx][soko->posy - 1] = 'P';
            soko->map[soko->posx][soko->posy - 2] = 'X';
        }
        else if (soko->map[soko->posx][soko->posy - 1] != 'X') {
            soko->map[soko->posx][soko->posy] = 'O';
            soko->map[soko->posx][soko->posy - 1] = 'P';
        }
    }
    soko->count = 0;
}

void right2(struct_t *soko)
{
    if (soko->map[soko->posx][soko->posy + 1] != '#') {
        if (soko->map[soko->posx][soko->posy + 1] == 'X' &&
        soko->map[soko->posx][soko->posy + 2] != 'X' &&
        soko->map[soko->posx][soko->posy + 2] != '#') {
            soko->map[soko->posx][soko->posy] = 'O';
            soko->map[soko->posx][soko->posy + 1] = 'P';
            soko->map[soko->posx][soko->posy + 2] = 'X';
        }
        else if (soko->map[soko->posx][soko->posy + 1] != 'X') {
            soko->map[soko->posx][soko->posy] = 'O';
            soko->map[soko->posx][soko->posy + 1] = 'P';
        }
    }
    soko->count = 0;
}

void down2(struct_t *soko)
{
    if (soko->map[soko->posx + 1][soko->posy] != '#') {
        if (soko->map[soko->posx + 1][soko->posy] == 'X' &&
        soko->map[soko->posx + 2][soko->posy] != 'X' &&
        soko->map[soko->posx + 2][soko->posy] != '#') {
            soko->map[soko->posx][soko->posy] = 'O';
            soko->map[soko->posx + 1][soko->posy] = 'P';
            soko->map[soko->posx + 2][soko->posy] = 'X';
        }
        else if (soko->map[soko->posx + 1][soko->posy] != 'X') {
            soko->map[soko->posx][soko->posy] = 'O';
            soko->map[soko->posx + 1][soko->posy] = 'P';
        }
    }
    soko->count = 0;
}

void up2(struct_t *soko)
{
    if (soko->map[soko->posx - 1][soko->posy] != '#') {
        if (soko->map[soko->posx - 1][soko->posy] == 'X' &&
        soko->map[soko->posx - 2][soko->posy] != 'X' &&
        soko->map[soko->posx - 2][soko->posy] != '#') {
            soko->map[soko->posx][soko->posy] = 'O';
            soko->map[soko->posx - 1][soko->posy] = 'P';
            soko->map[soko->posx - 2][soko->posy] = 'X';
        }
        else if (soko->map[soko->posx - 1][soko->posy] != 'X') {
            soko->map[soko->posx][soko->posy] = 'O';
            soko->map[soko->posx - 1][soko->posy] = 'P';
        }
    }
    soko->count = 0;
}