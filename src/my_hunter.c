/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** my_hunter
*/

#include "../include/my.h"
#include <SFML/System/Vector2.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/struct.h"
#include "../include/prototype_function.h"

void h_display(void)
{
    write(1, "In this game, you'll have to shoot the ducks to beat your ", 58);
    write(1, "best score\nShoot the ducks using mouse buttons\n", 47);
    write(1, "Press 'R' to reload your gun\n", 29);
}

void create_things(window_t *window, duck_t *duck, shot_t *shot)
{
    create_from_file(window, shot, duck);
    creations(window, shot, duck);
    strings(window, shot);
    create_sprites(window, shot, duck);
    vector1(window, duck);
    vector2(window, shot);
    change_cursor(window, shot);
}

void button_pressed_ok(window_t *window, duck_t *duck, shot_t *shot)
{
    sfMusic_play(shot->shot);
    shot->nb_ammo--;
    window->ammo_char = int_to_char(shot->nb_ammo);
    sfText_setString(shot->ammo_text, window->ammo_char);
    shot->mpos = sfMouse_getPositionRenderWindow(window->window);
    duck->spos = sfSprite_getPosition(duck->Sduck);
    if (shot->mpos.x >= duck->spos.x && shot->mpos.x <= duck->spos.x + 110 &&
        shot->mpos.y >= duck->spos.y && shot->mpos.y <= duck->spos.y + 110)
        duck_hit(window, duck);
    else
        display_window(window, duck, shot);
}

void event_function(window_t *window, shot_t *shot, duck_t *duck)
{
    if (window->event.type == sfEvtClosed)
        sfRenderWindow_close(window->window);
    if (window->event.type == sfEvtMouseButtonPressed) {
        if (shot->nb_ammo <= 0)
            no_more_ammo(shot);
        else
            button_pressed_ok(window, duck, shot);
    }
    if (window->event.key.code == sfKeyR)
        reloading(window, shot);
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        h_display();
        return (0);
    }
    window_t *window = malloc(sizeof(window_t));
    duck_t *duck = malloc(sizeof(duck_t));
    shot_t *shot = malloc(sizeof(shot_t));
    create_things(window, duck, shot);
    move_rect(duck, 110, 220, 0);
    sfMusic_play(window->music);
    sfRenderWindow_setFramerateLimit(window->window, 60);
    while (sfRenderWindow_isOpen(window->window)) {
        while (sfRenderWindow_pollEvent(window->window, &window->event))
            event_function(window, shot, duck);
        display_window(window, duck, shot);
    }
    sfRenderWindow_destroy(window->window);
    return (0);
}