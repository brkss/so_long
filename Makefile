
NAME = so_long

SOURCES = so_long.c srcs/finish.c srcs/events.c  srcs/map.c srcs/images.c srcs/gnl/get_next_line.c srcs/gnl/get_next_line_utils.c srcs/join.c srcs/itoa.c srcs/animation.c srcs/utils.c srcs/put_str.c srcs/error.c


FLAGS = -Wall -Wextra -Werror
LINKS = -l mlx -framework OpenGL -framework Appkit

all		: $(NAME)

$(NAME)	: 
			gcc $(SOURCES) -o $(NAME) $(FLAGS) $(LINKS)

clean	:
			rm -f $(NAME)

fclean	: 	clean

re		:	fclean all
