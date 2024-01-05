##
## EPITECH PROJECT, 2023
## radar_mod
## File description:
## Makefile
##

SRC =	src/main.c\
		src/read.c\
		src/plane.c\
		src/tower.c\
		src/general_fill.c\
		src/system.c\
		src/ctor.c\
		src/events.c\
		src/help.c\
		src/draw.c\

OBJ = $(SRC:.c=.o)

NAME =	libmy.a

SNAME =	my_radar

LDFLAGS = -I./include -L lib/my/ -lmy

PFLAGS = -I./include -L lib/ -lmy

# CFLAGS = -Wall -Werror -Wextra

CSFMLFLAGS = -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

all:	$(NAME) $(SNAME)

$(NAME):
	$(MAKE) -C lib/my/

# -lm because sqrt -> can't compile otherwise
$(SNAME): $(OBJ)
	$(CC) -g3 -o $(SNAME) $(SRC) $(LDFLAGS) $(PFLAGS) $(CSFMLFLAGS) -lm

clean:
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C lib/my/
	$(RM) lib/libmy.a lib/my/libmy.a
	clear

re: fclean all

.PHONY:	all clean fclean re
