/*
** EPITECH PROJECT, 2023
** radar
** File description:
** ctor.c
*/

#include "../include/my_radar.h"

many_t *many_ctor()
{
    many_t *many = malloc(sizeof(many_t));

    many->i = 0;
    many->o = 0;
    many->u = 0;
    return many;
}

lists_t *list_ctor()
{
    lists_t *list = malloc(sizeof(lists_t));

    list->Ppoint = malloc(sizeof(Plist_t));
    list->Tpoint = malloc(sizeof(Tlist_t));
    list->Pstart = malloc(sizeof(Plist_t));
    list->Tstart = malloc(sizeof(Tlist_t));
    return list;
}

mv_t *mv_ctor(plane_t *plane, all_t *all)
{
    mv_t *mv = malloc(sizeof(mv_t));

    mv->pos_f = plane->script.coord_f;
    mv->time = sfClock_getElapsedTime(all->sys->clock);
    mv->seconds = mv->time.microseconds / 1000000.0;
    mv->currentPos.x = 0;
    mv->currentPos.y = 0;
    mv->vec_dir.x = 0;
    mv->vec_dir.y = 0;
    mv->moving.x = 0;
    mv->moving.y = 0;
    mv->distance = 0.0;
    mv->pos_x = 0.0;
    mv->pos_y = 0.0;
    mv->diff = 90.0;
    return mv;
}
