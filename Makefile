NAME = arena
CC = cc
C_FLAGS = -Wall -Wextra -Werror
SRCS = main.c list_version/arena.c list_version/free.c list_version/free_utils.c list_version/alloc.c

NAME_OBJS = $(SRCS:.c=.o)
LIBFT = libft.a
LIB = libft
LIBS = -L$(LIB) -lft
RM = rm -rf

# Regra para compilar os arquivos .c em .o
all: $(LIBFT) $(NAME)

$(NAME): $(NAME_OBJS)
	$(CC) $(NAME_OBJS) $(LIBFLAGS) -o $(NAME) $(LIBS)

$(LIBFT):
	make -C $(LIB) && make -C $(LIB) bonus

clean:
	$(RM) $(NAME_OBJS)
	make -C $(LIB) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIB) fclean

re: fclean all


