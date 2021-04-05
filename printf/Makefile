SRCS = check_flag.c check_flag2.c field.c flag.c precision.c \
	   ft_printf.c hex.c strings2.c star.c bonus.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

INCL = include/

CC = gcc ${FLAGS}

all : $(NAME)

$(NAME): $(addprefix ../libft/, $(LIBFT:.c=.o)) $(addprefix srcs/, $(OBJS))

bonus: all

$(LIBFT):
	$(CC) -c $(LIBFT) -o $@

.c.o:
	$(CC) -c $< -o $@

re: fclean all

clean: 
	rm -rf $(addprefix srcs/, $(OBJS))

fclean : clean
	rm -rf $(NAME)
