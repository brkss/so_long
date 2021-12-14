


NAME = so_long

SOURCES = so_long.c

OBJECTS = $(subst .c,.o,$(SOURCES))

FLAGS = -Wall -Wextra -Werror
LINKS = -I /usr/local/include -L /usr/local/lib \
    	-l mlx -framework OpenGL -framework Appkit

# Remember to implement your rules...

$(NAME)	: $(OBJECTS)
			gcc $(SOURCES) -o $(NAME) $(FLAGS) $(LINKS)

clean	:
		rm *.o

fclean	: 	clean

