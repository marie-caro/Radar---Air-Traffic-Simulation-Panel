/*
** EPITECH PROJECT, 2023
** radar
** File description:
** help.c
*/

#include "../lib/my/my.h"

void output_help(void)
{
    my_printf("Air traffic simulation panel\n");
    my_putstr("\nUSAGE: ./my_radar [OPTION] path_to_script\n");
    my_printf(" path_to_script\t\t The path to the script file.\n");
    my_putstr("\nOPTIONS:\n -h\t\t        print the usage and quit.");
    my_putstr("\n ");
    my_printf("\nUSER INTERACTIONS\n");
    my_printf(" 'L' key       enable/disable hitbox and areas.\n");
    my_printf(" 'S' key       enable/disable sprites.\n");
}
