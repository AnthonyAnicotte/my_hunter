/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** Created by anthonyanicotte,
*/

#include "../include/my.h"
#include "../include/prototype_function.h"
#include <SFML/System/Vector2.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/struct.h"

int move_rect(duck_t *duck, int offset, int max_value, int i)
{
    if (duck->rect.left == max_value) {
        duck->rect.left = offset;
        i = 1;
    } else if (duck->rect.left == offset) {
        if (i == 1) {
            duck->rect.left = 0;
            i = 0;
        } else if (i == 0)
            duck->rect.left += offset;
    } else if (duck->rect.left == 0)
        duck->rect.left += offset;
    return (i);
}

void end_score(window_t *window)
{
    window->final_score = sfText_create();
    sfText_setString(window->final_score, window->score_char);
    sfText_setFont(window->final_score, window->font2);
    sfText_setCharacterSize(window->final_score, 70);
    window->score_display_pos.x = 510;
    window->score_display_pos.y = 82;
    sfText_setPosition(window->final_score, window->score_display_pos);
}