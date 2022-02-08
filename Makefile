


NAME = so_long

SOURCES = so_long.c srcs/finish.c srcs/events.c  srcs/map.c srcs/images.c srcs/gnl/get_next_line.c srcs/gnl/get_next_line_utils.c srcs/join.c srcs/itoa.c srcs/animation.c srcs/utils.c srcs/put_str.c

OBJECTS = $(subst .c,.o,$(SOURCES))

FLAGS = -Wall -Wextra -Werror
LINKS = -I /usr/local/include -L /usr/local/lib \
    	-l mlx -framework OpenGL -framework Appkit

all		: $(NAME)

$(NAME)	: 
			gcc $(SOURCES) -o $(NAME) $(FLAGS) $(LINKS)

clean	:
			rm -f $(OBJECTS)

fclean	: 	clean
			rm -f $(NAME)

re		:	fclean all
