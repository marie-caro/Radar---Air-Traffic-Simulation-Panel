/*
** EPITECH PROJECT, 2023
** radar
** File description:
** general_fill.c
*/

#include "../include/my_radar.h"

//### GERENERAL ############################################################
void augment_var(char **arr, int *i, int *j, int *k)
{
    arr[*k][*j] = '\0';
    (*i)++;
    (*k)++;
    *j = 0;
}

void put_in(void *object, char *script, char letter)
{
    char **arr = malloc(sizeof(char *) * 100);
    int j = 0;
    int k = 0;

    arr[0] = malloc(sizeof(char) * 5);
    for (int i = 0; script[i] != '\n' && script[i] != '\0'; i++) {
        if (script[i] == ' ') {
            augment_var(arr, &i, &j, &k);
            arr[k] = malloc(sizeof(char) * 5);
        }
        arr[k][j] = script[i];
        j++;
    }
    arr[k][j] = '\0';
    arr[k + 1] = NULL;
    if (letter == 'A')
        fill_plane((Plist_t *) object, arr);
    if (letter == 'T') {
        fill_tower((Tlist_t *) object, arr);
    }
}

void fill_bisp(char **script, lists_t *list, many_t *many)
{
    if (script[many->i][0] == 'A') {
        put_in(list->Ppoint, script[many->i], 'A');
        if (many->o == 0) {
            list->Pstart = list->Ppoint;
        }
        list->Ppoint->next = NULL;
        if (script[many->i + 1] != NULL) {
            list->Ppoint->next = malloc(sizeof(Plist_t));
            list->Ppoint = list->Ppoint->next;
            list->Ppoint->plane.script.coord.x = 0.0;
            list->Ppoint->plane.script.coord.y = 0.0;
            list->Ppoint->next = NULL;
            many->o++;
        }
    }
}

void fill_bist(char **script, lists_t *list, many_t *many)
{
    put_in(list->Tpoint, script[many->i], 'T');
    if (many->u == 0)
        list->Tstart = list->Tpoint;
    if (script[many->i + 1] != NULL) {
        list->Tpoint->next = malloc(sizeof(Tlist_t));
        list->Tpoint = list->Tpoint->next;
        many->u++;
    } else
        list->Tpoint->next = NULL;
}

lists_t *fill_list(int ac, char **av)
{
    char **script = read_file(ac, av);
    lists_t *list = list_ctor();
    many_t *many = many_ctor();

    for (; script[many->i] != NULL; many->i++) {
        if (script[many->i][0] == 'A')
            fill_bisp(script, list, many);
        if (script[many->i][0] == 'T') {
            fill_bist(script, list, many);
        }
    }
    return list;
}
