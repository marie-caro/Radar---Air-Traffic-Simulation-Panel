/*
** EPITECH PROJECT, 2023
** radar
** File description:
** shapes.c
*/

#include "../include/my_radar.h"

void draw_tower(all_t *all, Tlist_t *tmp_t)
{
    sfVector2f roundness = {2.0f, 2.0f};
    sfVector2f position;

    if (all->key == 0) {
        position.x = tmp_t->tower.coord.x - 30;
        position.y = tmp_t->tower.coord.y - 30;
        sfRenderWindow_drawSprite(all->sys->wd, tmp_t->tower.sprite, NULL);
        sfSprite_setPosition(tmp_t->tower.sprite, tmp_t->tower.coord);
        sfCircleShape_setRadius(tmp_t->tower.circleS, tmp_t->tower.radius * 2);
        sfCircleShape_setScale(tmp_t->tower.circleS, roundness);
        sfCircleShape_setOutlineColor(tmp_t->tower.circleS, sfRed);
        sfCircleShape_setOutlineThickness(tmp_t->tower.circleS, 3.0f);
        sfCircleShape_setFillColor(tmp_t->tower.circleS, sfTransparent);
        sfCircleShape_setPosition(tmp_t->tower.circleS, position);
    }
    check_t(tmp_t, all);
}

void draw_rect(Plist_t *tmp_p, all_t *all)
{
    sfVector2f size = {50, 47};
    float outlineThickness = 3.0f;
    sfColor outlineColor = sfBlack;
    sfVector2f position;

    position.x = tmp_p->plane.script.coord.x;
    position.y = tmp_p->plane.script.coord.y;
    sfRectangleShape_setSize(tmp_p->plane.area, size);
    sfRectangleShape_setOutlineColor(tmp_p->plane.area, outlineColor);
    sfRectangleShape_setOutlineThickness(tmp_p->plane.area, outlineThickness);
    sfRectangleShape_setFillColor(tmp_p->plane.area, sfTransparent);
}
