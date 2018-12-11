/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** Created by anthonyanicotte,
*/
#ifndef MY_HUNTER_STRUCT_H
#define MY_HUNTER_STRUCT_H

#include <SFML/System/Vector2.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/Window/Mouse.h>
#include <unistd.h>

#include <SFML/System/Time.h>

typedef struct window_s
{
    sfVector2f your_score_pos;
    sfVector2f game_over_pos;
    sfVector2i window_pos;
    sfVector2f block_live_pos;
    sfVector2f img_live_pos;
    sfVector2f x_pos;
    sfVector2f block_ammo_pos;
    sfVector2f ammo_txt_pos;
    sfVector2f ammo_pos;
    sfVector2f pan_pos;
    sfVector2f score_display_pos;
    sfVector2f score_pos;

    sfSprite *Sgame_over;
    sfSprite *heart;
    sfSprite *Sblock_lives;
    sfSprite *Sammo;
    sfSprite *Sblock_ammo;
    sfSprite *Sbackground;
    sfSprite *Sblock_score;
    sfTexture *Tblock;
    sfTexture *Tbackground;
    sfTexture *Tammo;
    sfTexture *Tlives;
    sfTexture *Tgame_over;

    sfText *final_score;
    sfText *your_score;
    sfFont *font1;
    sfFont *font2;
    sfText *score_text;
    sfText *x;
    sfText *score_txt;
    char *ammo_char;
    double seconds;
    double seconds_end;
    int score;
    int nb_lives;
    char *score_char;

    sfMusic *oof;
    sfMusic *death;
    sfMusic *music;
    sfTime time_end;
    sfClock *clock_end;
    sfTime time;
    sfClock *clock;
    sfVideoMode video_mode;
    sfRenderWindow *window;
    sfEvent event;
} window_t;

typedef struct duck_s
{
    sfVector2f spos;
    int speed;
    int i;
    sfMusic *coin_coin;
    sfVector2f vector;
    sfIntRect rect;
    sfTexture *Tduck;
    sfSprite *Sduck;
} duck_t;

typedef struct shot_s
{
    sfText *ammo_text;
    sfMusic *reloading;
    sfMusic *error;
    sfVector2i mpos;
    sfVector2f sprite_pos;
    sfVector2f cursor_pos;
    sfMusic *shot;
    int nb_ammo;
    sfTexture *Tcursor;
    sfSprite *Scursor;
} shot_t;

#endif
