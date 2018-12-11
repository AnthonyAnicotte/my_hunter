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
#include "../include/prototype_function.h"
#include <stdlib.h>
#include <unistd.h>
#include "../include/struct.h"

void draw_sprite(window_t *window, duck_t *duck, shot_t *shot)
{
    sfSprite_setTextureRect(duck->Sduck, duck->rect);
    sfRenderWindow_drawSprite(window->window, window->Sbackground, NULL);
    sfRenderWindow_drawSprite(window->window, duck->Sduck, NULL);
    scope_on_cursor(shot, window);
    sfRenderWindow_drawSprite(window->window, window->Sblock_lives, NULL);
    sfRenderWindow_drawSprite(window->window, window->Sblock_score, NULL);
    sfRenderWindow_drawSprite(window->window, window->Sblock_ammo, NULL);
    display_hearts(window);
    sfRenderWindow_drawSprite(window->window, window->Sammo, NULL);
    sfRenderWindow_drawText(window->window, window->score_text, NULL);
    sfRenderWindow_drawText(window->window, window->x, NULL);
    sfRenderWindow_drawText(window->window, window->score_txt, NULL);
    sfRenderWindow_drawText(window->window, shot->ammo_text, NULL);
    sfRenderWindow_drawSprite(window->window, shot->Scursor, NULL);
    sfRenderWindow_display(window->window);
    sfRenderWindow_clear(window->window, sfBlack);
}

void display_window(window_t *window, duck_t *duck, shot_t *shot)
{
    window->time = sfClock_getElapsedTime(window->clock);
    window->seconds = window->time.microseconds / 1000000.0;
    if (window->seconds > 0.09) {
        duck->i = move_rect(duck, 110, 220, duck->i);
        set_position(window, duck, shot);
        sfClock_restart(window->clock);
    }
    window->window_pos = sfRenderWindow_getPosition(window->window);
    if (duck->vector.x > window->window_pos.x + 810) {
        sfMusic_play(window->oof);
        window->nb_lives--;
        display_hearts(window);
        sfSprite_destroy(duck->Sduck);
        duck->Sduck = sfSprite_create();
        sfSprite_setTexture(duck->Sduck, duck->Tduck, sfTrue);
        sfSprite_setPosition(duck->Sduck, duck->vector);
        duck->vector.x = 0;
        duck->vector.y = rand() % 435;
    }
    draw_sprite(window, duck, shot);
}