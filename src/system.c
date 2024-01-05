/*
** EPITECH PROJECT, 2023
** radar_mod
** File description:
** system.c
*/
#include "../include/my_radar.h"

void destroy_all(all_t *all)
{
    sfSprite_destroy(all->map->sprite);
    sfTexture_destroy(all->map->texture);
    sfClock_destroy(all->sys->clock);
    sfRenderWindow_destroy(all->sys->wd);
    free(all->map);
    free(all->sys);
    free(all);
}

Plist_t *set_values(Plist_t *tmp_p, Tlist_t *tmp_t)
{
    Plist_t *tmp = malloc(sizeof(Plist_t));

    memset(tmp_p, 0, sizeof(Plist_t));
    memset(tmp_t, 0, sizeof(Tlist_t));
    memset(tmp, 0, sizeof(Plist_t));
    return tmp;
}

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *arr = malloc(sizeof(framebuffer_t));

    arr->width = width;
    arr->height = height;
    return arr;
}

mytext_t text_ctor(int pos, sfColor color)
{
    mytext_t text;
    sfVector2f text_pos;

    text_pos.x = 20.0f;
    text_pos.y = 75.0f;
    text.text = sfText_create();
    text.font = sfFont_createFromFile("Fonts/Valoon.ttf");
    sfText_setFont(text.text, text.font);
    sfText_setCharacterSize(text.text, pos);
    sfText_setPosition(text.text, text_pos);
    sfText_setColor(text.text, color);
    return text;
}

void create_sys(all_t *all, sfEvent event)
{
    sys_t *sys = malloc(sizeof(sys_t));
    gameobject_t *map = malloc(sizeof(gameobject_t));
    sfVideoMode video_mode = {1920, 1080, 32};
    framebuffer_t *arr = NULL;

    sys->arr = framebuffer_create(1920, 1080);
    sys->event = event;
    sys->wd = sfRenderWindow_create(video_mode, "My_Radar", sfResize
    | sfClose, NULL);
    sys->clock = sfClock_create();
    map->sprite = sfSprite_create();
    map->texture = sfTexture_createFromFile("imgs/mapa.png", NULL);
    sfSprite_setTexture(map->sprite, map->texture, sfTrue);
    all->sys = sys;
    all->map = map;
    all->key = 0;
    all->keys = 0;
    all->text = text_ctor(50, sfBlack);
}
