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

void scope_on_cursor(shot_t *shot, window_t *window)
{
    shot->mpos = sfMouse_getPositionRenderWindow(window->window);
    shot->sprite_pos.x = shot->mpos.x;
    shot->sprite_pos.y = shot->mpos.y;
    sfSprite_setPosition(shot->Scursor, shot->sprite_pos);
}

void change_cursor(window_t *window, shot_t *shot)
{
    shot->cursor_pos.x = 20;
    shot->cursor_pos.y = 20;
    sfRenderWindow_setMouseCursorVisible(window->window, sfFalse);
    sfSprite_setOrigin(shot->Scursor, shot->cursor_pos);
}

void duck_hit(window_t *window, duck_t *duck)
{
    sfMusic_play(duck->coin_coin);
    sfSprite_destroy(duck->Sduck);
    window->score += 50;
    window->score_char = int_to_char(window->score);
    sfText_setString(window->score_txt, window->score_char);
    sfRenderWindow_drawText(window->window, window->score_txt, NULL);
    duck->Sduck = sfSprite_create();
    sfSprite_setTexture(duck->Sduck, duck->Tduck, sfTrue);
    duck->vector.x = 0;
    duck->vector.y = rand() % 490;
    duck->speed = (rand() % 29) + 20;
}

void no_more_ammo(shot_t *shot)
{
    sfMusic_play(shot->error);
    sfText_setString(shot->ammo_text, "0");
}

void reloading(window_t *window, shot_t *shot)
{
    sfMusic_play(shot->reloading);
    shot->nb_ammo = 6;
    sfText_setString(shot->ammo_text, "6");
    sfRenderWindow_drawText(window->window, shot->ammo_text, NULL);
}