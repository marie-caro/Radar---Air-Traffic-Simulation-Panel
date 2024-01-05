/*
** EPITECH PROJECT, 2023
** radar_mod
** File description:
** my_radar.h
*/
#pragma once

#include <SFML/Graphics/PrimitiveType.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/RenderStates.h>
#include <SFML/Graphics/BlendMode.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/Graphics/Vertex.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics.h>
#include <SFML/Window/Window.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/VideoMode.h>
#include <SFML/Window/WindowHandle.h>
#include <SFML/Config.h>
#include <SFML/Audio.h>
#include <SFML/Audio/Types.h>
#include <SFML/Audio/Music.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector2.h>
#include <SFML/System/Vector3.h>
#include <SFML/System/InputStream.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../lib/my/my.h"

//##### READ SCRIPT #########################################################//
char **read_file(int ac, char **av);

//##### System ############################################################
typedef struct framebuffer_s {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
} framebuffer_t;

typedef struct sys_s {
    sfRenderWindow *wd;
    sfEvent event;
    sfClock *clock;
    framebuffer_t *arr;
    framebuffer_t *framebuffer;
} sys_t;

typedef struct gameobject {
    int vida;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfIntRect rect;
    int offset;
} gameobject_t;

typedef struct text {
    sfText *text;
    sfFont *font;
} mytext_t;

typedef struct all_s {
    sys_t *sys;
    gameobject_t *map;
    int key;
    int keys;
    mytext_t text;
} all_t;

typedef struct many_s {
    int o;
    int u;
    char **script;
    int i;
} many_t;

//#### Gameobjects #########################################################
typedef struct coord_s {
    int x;
    int y;
} coord_t;

typedef struct info_s {
    sfVector2f coord_s;
    sfVector2f coord_f;
    sfVector2f coord;
    int speed;
    int delay;
} info_t;

typedef struct plane_s {
    int vida;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfIntRect rect;
    int offset;
    sfRectangleShape *area;
    info_t script;
    float angle;
} plane_t;

typedef struct tower_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfIntRect rect;
    sfVector2f coord;
    sfCircleShape *circleS;
    int radius;
} tower_t;

typedef struct Tlist_s {
    tower_t tower;
    struct Tlist_s *next;
}Tlist_t;

typedef struct Plist_s {
    plane_t plane;
    struct Plist_s *next;
}Plist_t;

typedef struct lists_s {
    Plist_t *Ppoint;
    Tlist_t *Tpoint;
    Plist_t *Pstart;
    Tlist_t *Tstart;
}lists_t;


typedef struct mv_s {
    sfVector2f pos_f;
    sfTime time;
    float seconds;
    sfVector2f currentPos;
    sfVector2f vec_dir;
    sfVector2f moving;
    float distance;
    float pos_x;
    float pos_y;
    float diff;
}mv_t;

//###### #############################################################

//##### Planes | Towers ####################################################
void put_in(void *object, char *script, char letter);
void print_plane_data(Plist_t *planes);
plane_t *make_time_pos(plane_t *plane, all_t *all, int j);
void update_var(mv_t *mv, plane_t *plane);
void fill_plane(Plist_t *airplanes, char **arr);
void fill_tower(Tlist_t *towers, char **arr);

//#### Other ###############################################################
framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
void create_sys(all_t *all, sfEvent event);
void destroy_all(all_t *all);
many_t *many_ctor(void);
lists_t *list_ctor(void);
mv_t *mv_ctor(plane_t *plane, all_t *all);

void fill_bisp(char **script, lists_t *list, many_t *many);
void fill_bist(char **script, lists_t *list, many_t *many);
lists_t *fill_list(int ac, char **av);

Plist_t *set_values(Plist_t *tmp_p, Tlist_t *tmp_t);
void which_key(all_t *all, sfEvent event);
void analize_event(all_t *all, sfEvent event);

void output_help(void);

void draw_tower(all_t *all, Tlist_t *tmp_t);
void draw_rect(Plist_t *tmp_p, all_t *all);

void check_t(Tlist_t *tmp_t, all_t *all);
int are_dead(lists_t *list);

//#### Useless #############################################################

//############################################################################

#define VEC(mv)  (mv)->vec_dir
