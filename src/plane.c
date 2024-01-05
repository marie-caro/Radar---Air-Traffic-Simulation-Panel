/*
** EPITECH PROJECT, 2023
** radar_mod
** File description:
** fill_plane.c
*/
#include "../include/my_radar.h"

// coord_s -> initial coords | coord -> while moving | coord_f -> final

//#### PLANE: Fill info from script ########################################
void fill_plane(Plist_t *planes, char **arr)
{
    planes->plane.script.coord_s.x = str_to_float(arr[1]);
    planes->plane.script.coord_s.y = str_to_float(arr[2]);
    planes->plane.script.coord.x = str_to_float(arr[1]);
    planes->plane.script.coord.y = str_to_float(arr[2]);
    planes->plane.script.coord_f.x = str_to_float(arr[3]);
    planes->plane.script.coord_f.y = str_to_float(arr[4]);
    planes->plane.script.delay = my_get_nbr(arr[5]);
    planes->plane.script.speed = my_get_nbr(arr[6]);
    planes->plane.sprite = sfSprite_create();
    planes->plane.texture = sfTexture_createFromFile("imgs/plane.png", NULL);
    sfSprite_setTexture(planes->plane.sprite, planes->plane.texture, sfTrue);
    planes->plane.vida = 0;
    planes->plane.area = sfRectangleShape_create();
    planes->plane.angle = 0.0;
    planes->next = NULL;
}

void update_var(mv_t *mv, plane_t *plane)
{
    mv->currentPos = sfSprite_getPosition(plane->sprite);
    VEC(mv).x = mv->pos_f.x - mv->currentPos.x;
    VEC(mv).y = mv->pos_f.y - mv->currentPos.y;
    mv->distance = sqrt(VEC(mv).x * VEC(mv).x + VEC(mv).y * VEC(mv).y);
}

// vector_dir -> vector btw the current position & the final position
// moving is the vector that the plane follows while moving (?) twrds final pos
// After looking at functions from math.h -> atan2
// atan2 -> Se utiliza fundamentalmente para devolver un valor correcto e
// inequívoco para el ángulo θ en la conversión de coordenadas cartesianas
// (x, y) a coordenadas polares (r, θ). -> angulo con las coordenadas
// in radians bc if not it doesn't work :/
void get_angle(plane_t *plane, mv_t *mv)
{
    float diff_x = plane->script.coord_f.x - mv->currentPos.x;
    float diff_y = plane->script.coord_f.y - mv->currentPos.y;
    double angle_rad = atan2(diff_y, diff_x);

    plane->angle = angle_rad * (180.0 / 3.1415926535);
}

plane_t *make_time_pos(plane_t *plane, all_t *all, int j)
{
    mv_t *mv = mv_ctor(plane, all);

    if (mv->seconds > 0.05) {
        update_var(mv, plane);
        mv->moving.x = mv->vec_dir.x * mv->seconds / 150;
        mv->moving.y = mv->vec_dir.y * mv->seconds / 150;
        sfSprite_move(plane->sprite, mv->moving);
        if (fabs(mv->currentPos.x - plane->script.coord_f.x) < mv->diff
        && fabs(mv->currentPos.y - plane->script.coord_f.y) < mv->diff) {
            plane->vida = 1;
        }
        plane->script.coord = mv->currentPos;
        get_angle(plane, mv);
        sfRectangleShape_setPosition(plane->area, mv->currentPos);
    }
    return plane;
}
