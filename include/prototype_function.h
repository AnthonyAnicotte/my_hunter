/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** Created by anthonyanicotte,
*/
#ifndef MY_HUNTER_PROTOTYPE_FUNCTION_H
#define MY_HUNTER_PROTOTYPE_FUNCTION_H

#include "struct.h"

void change_cursor(window_t *window, shot_t *shot);
void duck_hit(window_t *window, duck_t *duck);
void reloading(window_t *window, shot_t *shot);
void vector2(window_t *window, shot_t *shot);
void creations(window_t *window, shot_t *shot, duck_t *duck);
void create_from_file(window_t *window, shot_t *shot, duck_t *duck);
void create_other_things(window_t *window, duck_t *duck, shot_t *shot);
void strings(window_t *window, shot_t *shot);
void create_sprites(window_t *window, shot_t *shot, duck_t *duck);
void vector1(window_t *window, duck_t *duck);
void scope_on_cursor(shot_t *shot, window_t *window);
int move_rect(duck_t *duck, int offset, int max_value, int i);
void display_window(window_t *window, duck_t *duck, shot_t *shot);
void set_position(window_t *window, duck_t *duck, shot_t *shot);
void three_heart_case(window_t *window);
void two_heart_case(window_t *window);
void one_heart_case(window_t *window);
void end_score(window_t *window);
void no_more_hearts(window_t *window);
void display_hearts(window_t *window);
void vector2(window_t *window, shot_t *shot);
void draw_sprite(window_t *window, duck_t *duck, shot_t *shot);
void draw_sprite(window_t *window, duck_t *duck, shot_t *shot);
void no_more_ammo(shot_t *shot);

#endif //MY_HUNTER_PROTOTYPE_FUNCTION_H
