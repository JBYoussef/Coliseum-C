NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
NAME_SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
			ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			get_next_line/get_next_line.c ft_strcmp.c\
			ft_printf/ft_printf.c ft_printf/print_functions.c ft_strndup.c\
			ft_printf/print_functions2.c ft_printf/print_utils.c
BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
			ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
			ft_lstclear.c ft_lstiter.c ft_lstmap.c

SRCS_OBJS = $(NAME_SRCS:.c=.o)			
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
ALL_OBJS = $(SRCS_OBJS) $(BONUS_OBJS)
%.o: %.c
	$(CC) $(CFLAGS) -I . -c $< -o $@
all: $(NAME)
$(NAME): $(SRCS_OBJS)
	$(AR) $(NAME) $(SRCS_OBJS)
bonus: $(BONUS_OBJS)
	$(AR) $(NAME) $(BONUS_OBJS)
clean:
	rm -rf $(SRCS_OBJS) $(BONUS_OBJS)
fclean: clean
	rm -rf $(NAME)
re: fclean all
rebonus: fclean bonus
.PHONY: all clean fclean re bonus rebonus
