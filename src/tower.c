/*
** EPITECH PROJECT, 2023
** radar
** File description:
** fill_tower.c
*/

#include "../include/my_radar.h"

//#### TOWER: Fill info from script ########################################
void fill_tower(Tlist_t *towers, char **arr)
{
    towers->tower.coord.x = str_to_float(arr[1]);
    towers->tower.coord.y = str_to_float(arr[2]);
    towers->tower.radius = my_get_nbr(arr[3]);
    towers->tower.sprite = sfSprite_create();
    towers->tower.texture = sfTexture_createFromFile("imgs/tower.png", NULL);
    sfSprite_setTexture(towers->tower.sprite, towers->tower.texture, sfTrue);
    towers->tower.circleS = sfCircleShape_create();
}
