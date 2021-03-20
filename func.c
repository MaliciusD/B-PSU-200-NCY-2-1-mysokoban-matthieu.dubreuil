/*
** EPITECH PROJECT, 2021
** func
** File description:
** func
*/

#include "include/my.h"

char **my_str_to_wordarray(char *src, char c)
{
    int x = 0;
    int y = 0;
    int count1 = 0;
    int count2 = 0;
    char **str = malloc(sizeof(char *) * (100000));
    for (int i = 0; i != 100000; i++)
        str[i] = malloc(sizeof(char) * (100000));
    for (int i = 0; src[i] != '\0'; i++) {
        if (src[i] != c) {
            str[x][y] = src[i];
            y++;
        }
        if (src[i] == c) {
            str[x][y] = src[i];
            y++;
            y = 0;
            x++;
        }
    } str[x][y] = '\0';
    return (str);
}

void get_pos(struct_t *soko)
{
    for (int i = 0; soko->map[i] != NULL; i++) {
        for (int y = 0; soko->map[i][y] != '\0'; y++) {
            if (soko->map[i][y] == 'P') {
                soko->posx = i;
                soko->posy = y;
            }
        }
    }
}