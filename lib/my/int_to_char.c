/*
** EPITECH PROJECT, 2018
** anthony.anicotte@epitech.eu
** File description:
** int to char
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>

char *int_to_char(int nb)
{
    int i = 0;
    char *str = malloc(sizeof(char) * 11);

    while (nb != 0)
    {
        str[i] = (nb % 10) + 48;
        nb /= 10;
        i++;
    }
    str[i] = '\0';
    my_revstr_no_display(str);
    return (str);
}