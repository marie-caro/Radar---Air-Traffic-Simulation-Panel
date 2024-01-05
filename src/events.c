/*
** EPITECH PROJECT, 2023
** radar
** File description:
** events.c
*/

#include "../include/my_radar.h"

void which_key(all_t *all, sfEvent event)
{
    static int i = 1;
    static int j = 1;

    if (event.key.code == sfKeyS) {
        if (i % 2 != 0) {
            all->key = 1;
        }
        if (i % 2 == 0)
            all->key = 0;
        i++;
    }
    if (event.key.code == sfKeyL) {
        if (j % 2 != 0) {
            all->keys = 1;
        }
        if (j % 2 == 0)
            all->keys = 0;
        j++;
    }
}

int are_dead(lists_t *list)
{
    Plist_t *tmp = list->Pstart;

    while (tmp != NULL) {
        if (tmp->plane.vida == 0)
            return 0;
        tmp = tmp->next;
    }
    return 1;
}

void analize_event(all_t *all, sfEvent event)
{
    while (sfRenderWindow_pollEvent(all->sys->wd, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(all->sys->wd);
        if (event.type == sfEvtKeyPressed)
            which_key(all, event);
    }
    sfRenderWindow_display(all->sys->wd);
    sfRenderWindow_clear(all->sys->wd, sfBlack);
    sfRenderWindow_drawSprite(all->sys->wd, all->map->sprite, NULL);
}
