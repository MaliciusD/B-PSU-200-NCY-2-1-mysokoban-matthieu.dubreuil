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

int check_win(struct_t *soko)
{
    for (int i = 0; soko->pos_o[i][0] != '\0'; i += 2) {
        if (soko->map[my_getnbr(soko->pos_o[i])]
        [my_getnbr(soko->pos_o[i + 1])] == 'X') {
            soko->count2 = 1;
        }
        else {
            soko->count2 = 0;
            return (0);
        }
    }
}

void check_pos(struct_t *soko)
{
    int pos = 0;
    int pos2 = 0;
    for (int i = 0; soko->pos_o[i] != NULL; i += 2) {
        pos = my_getnbr(soko->pos_o[i]);
        pos2 = my_getnbr(soko->pos_o[i + 1]);
        if (soko->posx == pos && soko->posy == pos2)
            soko->count = 1;
    }
}

char *my_getnbrinverse(int tmp)
{
    char *int_chared = malloc(sizeof(char *) * (11));
    char *intneg_chared = malloc(sizeof(char *) * (11));
    int k = 0;
    int trans = 0;
    int is_neg = 0;
    if (tmp == 0)
        return ("0");
    else { if (tmp < 0) { tmp = tmp * -1;
            is_neg = 1;
        }
        for (; tmp > 0; k++) {
            trans = tmp % 10;
            tmp = tmp / 10;
            int_chared[k] = trans + 48;
        } int_chared = my_revstr(int_chared);
        if (is_neg != 0) {
            for (int i = 0; int_chared[i] != 0; i++) { intneg_chared[0] = '-';
                intneg_chared[i + 1] = int_chared[i];
            } return (intneg_chared);
        } else return (int_chared); }
}

void check_o(struct_t *soko)
{
    int z = 0;
    for (int i = 0; soko->map[i] != NULL; i++) {
        for (int y = 0; soko->map[i][y] != '\0'; y++)
        if (soko->map[i][y] == 'O') {
            soko->nb_o += 1;
            soko->pos_o[z] = my_getnbrinverse(i);
            z++;
            soko->pos_o[z] = my_getnbrinverse(y);
            z++;
        }
    }
}

void bind(struct_t *soko)
{
    if (soko->close == KEY_LEFT && soko->count != 1)
        left(soko);
    if (soko->close == KEY_RIGHT && soko->count != 1)
        right(soko);
    if (soko->close == KEY_UP && soko->count != 1)
        up(soko);
    if (soko->close == KEY_DOWN && soko->count != 1)
        down(soko);
}