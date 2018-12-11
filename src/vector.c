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

void vector1(window_t *window, duck_t *duck)
{
    window->x_pos.x = 412;
    window->x_pos.y = 520;
    window->score_pos.x = 581;
    window->score_pos.y = 511;
    duck->vector.x = 0;
    duck->vector.y = 0;
    duck->rect.top = 0;
    duck->rect.left = 0;
    duck->rect.width = 110;
    duck->rect.height = 110;
    window->score_display_pos.x = 685;
    window->score_display_pos.y = 515;
    window->pan_pos.x = 570;
    window->pan_pos.y = 500;
    window->block_live_pos.x = 31;
    window->block_live_pos.y = 500;
    window->img_live_pos.x = 47;
    window->img_live_pos.y = 522;
    window->your_score_pos.x = 80;
    window->your_score_pos.y = 80;
}

void vector2(window_t *window, shot_t *shot)
{
    window->game_over_pos.x = 0;
    window->game_over_pos.y = 0;
    window->block_ammo_pos.x = 300;
    window->block_ammo_pos.y = 500;
    window->ammo_pos.x = 325;
    window->ammo_pos.y = 515;
    window->ammo_txt_pos.x = 450;
    window->ammo_txt_pos.y = 515;
    window->score = 0;
    window->nb_lives = 3;
    shot->nb_ammo = 6;
}