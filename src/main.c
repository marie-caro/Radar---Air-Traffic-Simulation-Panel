/*
** EPITECH PROJECT, 2023
** radar_mod
** File description:
** main.c
*/
#include "../include/my_radar.h"

void game_loop_bis(Plist_t *tmp_p, all_t *all, int v)
{
    if (v == 0)
        sfSprite_setPosition(tmp_p->plane.sprite, tmp_p->plane.script.coord_s);
    sfRenderWindow_drawSprite(all->sys->wd, tmp_p->plane.sprite, NULL);
    sfRectangleShape_setRotation(tmp_p->plane.area, tmp_p->plane.angle);
    sfSprite_setRotation(tmp_p->plane.sprite, tmp_p->plane.angle);
    draw_rect(tmp_p, all);
}

void check_t(Tlist_t *tmp_t, all_t *all)
{
    sfCircleShape *area = tmp_t->tower.circleS;

    if (all->keys == 0)
        sfRenderWindow_drawCircleShape(all->sys->wd, area, NULL);
}

void check_p(Plist_t *tmp_p, all_t *all, int v, Plist_t *tmp)
{
    sfRectangleShape *area = tmp_p->plane.area;

    if (tmp_p->plane.vida == 0 && all->key == 0)
        game_loop_bis(tmp_p, all, v);
    if (tmp_p->plane.vida == 0 && all->keys == 0)
        sfRenderWindow_drawRectangleShape(all->sys->wd, area, NULL);
    if (tmp_p->plane.vida == 0)
        make_time_pos(&tmp_p->plane, all, 5);
    while (tmp != NULL) {
        if (tmp->plane.vida == 1)
            tmp = tmp->next;
        if (fabs(tmp_p->plane.script.coord.x - tmp->plane.script.coord.x) < 55
        && fabs(tmp_p->plane.script.coord.y - tmp->plane.script.coord.y) < 55
        && tmp_p != tmp) {
            tmp_p->plane.vida = 1;
            tmp->plane.vida = 1;
        }
        tmp = tmp->next;
    }
}

int game_loop(all_t *all, sfEvent event, lists_t *list)
{
    Plist_t *tmp_p = malloc(sizeof(Plist_t));
    Tlist_t *tmp_t = malloc(sizeof(Tlist_t));
    Plist_t *tmp = set_values(tmp_p, tmp_t);
    static int v = 0;

    tmp_p = list->Pstart;
    tmp_t = list->Tstart;
    tmp = tmp_p;
    while (tmp_t != NULL) {
        draw_tower(all, tmp_t);
        tmp_t = tmp_t->next;
    }
    while (tmp_p != NULL) {
        check_p(tmp_p, all, v, tmp_p);
        tmp_p = tmp_p->next;
    }
    if (are_dead(list) == 1)
        return 1;
    v++;
    return 0;
}

int main(int ac, char **av)
{
    all_t *all = malloc(sizeof(all_t));
    sfEvent event;
    lists_t *list = malloc(sizeof(lists_t));

    if (ac != 2)
        return 84;
    if (my_strcmp(av[1], "-h") == 1) {
        output_help();
        return 0;
    }
    create_sys(all, event);
    list = fill_list(ac, av);
    sfRenderWindow_setFramerateLimit(all->sys->wd, 30);
    while (sfRenderWindow_isOpen(all->sys->wd)) {
        analize_event(all, event);
        if (game_loop(all, event, list) == 1)
            return 0;
    }
    destroy_all(all);
    return 0;
}
