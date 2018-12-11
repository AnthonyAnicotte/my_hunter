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

void create_from_file(window_t *window, shot_t *shot, duck_t *duck)
{
    window->oof = sfMusic_createFromFile("assets/musics/oof.ogg");
    shot->reloading = sfMusic_createFromFile("assets/musics/reload.ogg");
    shot->error = sfMusic_createFromFile("assets/musics/error.ogg");
    window->death = sfMusic_createFromFile("assets/musics/death.ogg");
    window->font1 = sfFont_createFromFile("assets/Komiko.ttf");
    window->font2 = sfFont_createFromFile("assets/fast99.ttf");
    duck->Tduck = sfTexture_createFromFile("assets/images/sprite.png", NULL);
    window->music = sfMusic_createFromFile("assets/musics/music.ogg");
    window->Tblock = sfTexture_createFromFile("assets/images/pan2.png", NULL);
    window->Tammo = sfTexture_createFromFile("assets/images/ammo2.png", NULL);
    window->Tbackground = sfTexture_createFromFile("assets/images/back2.png",
        NULL);
    window->Tgame_over = sfTexture_createFromFile("assets/images/game_over.png",
        NULL);
    shot->shot = sfMusic_createFromFile("assets/musics/shot.ogg");
    duck->coin_coin = sfMusic_createFromFile("assets/musics/coin_coin.ogg");
    shot->Tcursor = sfTexture_createFromFile("assets/images/cursor.png", NULL);
    window->Tlives = sfTexture_createFromFile("assets/images/heart.png", NULL);
}

void creations(window_t *window, shot_t *shot, duck_t *duck)
{
    window->Sgame_over = sfSprite_create();
    window->heart = sfSprite_create();
    window->Sblock_lives = sfSprite_create();
    window->score_txt = sfText_create();
    shot->ammo_text = sfText_create();
    window->x = sfText_create();
    window->your_score = sfText_create();
    window->score_text = sfText_create();
    duck->Sduck = sfSprite_create();
    window->Sblock_score = sfSprite_create();
    window->Sammo = sfSprite_create();
    window->Sblock_ammo = sfSprite_create();
    window->Sbackground = sfSprite_create();
    window->clock = sfClock_create();
    window->clock_end = sfClock_create();
    shot->Scursor = sfSprite_create();
    window->video_mode.width = 800;
    window->video_mode.height = 600;
    window->video_mode.bitsPerPixel = 32;
    window->window = sfRenderWindow_create(window->video_mode, "My Hunter",
        sfDefaultStyle, NULL);
}

void strings(window_t *window, shot_t *shot)
{
    window->ammo_char = "6";
    window->score_char = "0";
    sfText_setString(window->your_score, "Your score :");
    sfText_setFont(window->your_score, window->font2);
    sfText_setCharacterSize(window->your_score, 70);
    sfText_setString(shot->ammo_text, window->ammo_char);
    sfText_setFont(shot->ammo_text, window->font1);
    sfText_setCharacterSize(shot->ammo_text, 50);
    sfText_setString(window->x, "x");
    sfText_setFont(window->x, window->font1);
    sfText_setCharacterSize(window->x, 40);
    sfText_setString(window->score_txt, window->score_char);
    sfText_setFont(window->score_txt, window->font1);
    sfText_setCharacterSize(window->score_txt, 50);
    sfText_setString(window->score_text, "Score:");
    sfText_setFont(window->score_text, window->font1);
    sfText_setCharacterSize(window->score_text, 29);
}

void create_sprites(window_t *window, shot_t *shot, duck_t *duck)
{
    sfMusic_setVolume(duck->coin_coin, 50);
    sfMusic_setVolume(window->death, 10);
    sfMusic_setVolume(window->music, 5.00);
    sfMusic_setVolume(shot->shot, 50);
    sfSprite_setTexture(window->Sgame_over, window->Tgame_over, sfTrue);
    sfSprite_setTexture(window->heart, window->Tlives, sfTrue);
    sfSprite_setTexture(window->Sblock_lives, window->Tblock, sfTrue);
    sfSprite_setTexture(duck->Sduck, duck->Tduck, sfTrue);
    sfSprite_setTexture(window->Sblock_score, window->Tblock, sfTrue);
    sfSprite_setTexture(window->Sblock_ammo, window->Tblock, sfTrue);
    sfSprite_setTexture(window->Sbackground, window->Tbackground, sfTrue);
    sfSprite_setTexture(window->Sammo, window->Tammo, sfTrue);
    sfSprite_setTexture(shot->Scursor, shot->Tcursor, sfTrue);
}

void set_position(window_t *window, duck_t *duck, shot_t *shot)
{
    sfText_setPosition(window->your_score, window->your_score_pos);
    sfText_setPosition(window->x, window->x_pos);
    sfText_setPosition(window->score_text, window->score_pos);
    sfText_setPosition(window->score_txt, window->score_display_pos);
    sfText_setPosition(shot->ammo_text, window->ammo_txt_pos);
    sfSprite_setPosition(window->heart, window->img_live_pos);
    sfSprite_setPosition(window->Sammo, window->ammo_pos);
    sfSprite_setPosition(window->Sblock_lives, window->block_live_pos);
    sfSprite_setPosition(window->Sblock_ammo, window->block_ammo_pos);
    sfSprite_setPosition(window->Sblock_score, window->pan_pos);
    sfSprite_setPosition(duck->Sduck, duck->vector);
    sfSprite_setPosition(window->Sgame_over, window->game_over_pos);
    duck->vector.x += 7 + duck->speed;
    duck->vector.y += 0;
}