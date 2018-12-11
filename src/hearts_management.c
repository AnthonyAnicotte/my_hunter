/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** Created by anthonyanicotte,
*/

#include "../include/my.h"
#include <SFML/System/Vector2.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/prototype_function.h"
#include "../include/struct.h"

void three_heart_case(window_t *window)
{
    window->img_live_pos.x = 47;
    window->img_live_pos.y = 522;
    sfSprite_setPosition(window->heart, window->img_live_pos);
    sfRenderWindow_drawSprite(window->window, window->heart, NULL);
    window->img_live_pos.x = 112;
    window->img_live_pos.y = 522;
    sfSprite_setPosition(window->heart, window->img_live_pos);
    sfRenderWindow_drawSprite(window->window, window->heart, NULL);
    window->img_live_pos.x = 177;
    window->img_live_pos.y = 522;
    sfSprite_setPosition(window->heart, window->img_live_pos);
    sfRenderWindow_drawSprite(window->window, window->heart, NULL);
}

void two_heart_case(window_t *window)
{
    window->img_live_pos.x = 47;
    window->img_live_pos.y = 522;
    sfSprite_setPosition(window->heart, window->img_live_pos);
    sfRenderWindow_drawSprite(window->window, window->heart, NULL);
    window->img_live_pos.x = 112;
    window->img_live_pos.y = 522;
    sfSprite_setPosition(window->heart, window->img_live_pos);
    sfRenderWindow_drawSprite(window->window, window->heart, NULL);
}

void one_heart_case(window_t *window)
{
    window->img_live_pos.x = 47;
    window->img_live_pos.y = 522;
    sfSprite_setPosition(window->heart, window->img_live_pos);
    sfRenderWindow_drawSprite(window->window, window->heart, NULL);
}

void no_more_hearts(window_t *window)
{
    sfMusic_stop(window->music);
    sfMusic_play(window->death);
    sfClock_restart(window->clock_end);
    end_score(window);
    window->seconds_end = 0;
    window->seconds_end = window->time_end.microseconds / 1000000.0;
    while (window->seconds_end < 5) {
        sfRenderWindow_clear(window->window, sfBlack);
        sfRenderWindow_drawSprite(window->window, window->Sgame_over, NULL);
        sfRenderWindow_drawText(window->window, window->your_score, NULL);
        sfRenderWindow_drawText(window->window, window->final_score, NULL);
        sfRenderWindow_display(window->window);
        window->time_end = sfClock_getElapsedTime(window->clock_end);
        window->seconds_end = window->time_end.microseconds / 1000000.0;
    }
    sfRenderWindow_destroy(window->window);
    exit(0);
}

void display_hearts(window_t *window)
{
    switch (window->nb_lives) {
    case 3:
        three_heart_case(window);
        break;
    case 2:
        two_heart_case(window);
        break;
    case 1:
        one_heart_case(window);
        break;
    case 0:
        no_more_hearts(window);
        break;
    }
}