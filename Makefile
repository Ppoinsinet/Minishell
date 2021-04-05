NAME = minishell

SRCS = args.c arrow.c commands.c commands_two.c cursor.c delete_pipe.c directory.c environment.c \
	   env_var.c error.c executable.c free_shell.c ft_list.c ft_shell_split.c \
	   input.c intro.c pipe.c pipe_two.c print.c selection.c setup_pipe.c dyn_var.c \
	   signal.c special_chars.c strings.c main.c utils.c init.c delete_char.c

PRINTF_SRCS = check_flag.c check_flag2.c field.c flag.c precision.c ft_printf.c hex.c strings2.c \
			  star.c bonus.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

CC = clang ${FLAGS}

all: $(NAME)

.c.o:
	$(CC) -c $< -o $(<:.c=.o) -g

$(NAME): $(addprefix srcs/, $(OBJS))
	cd libft/ ; make
	cd printf/ ; make
	$(CC) -o $(NAME) $(addprefix srcs/, $(OBJS)) $(addprefix printf/srcs/, $(PRINTF_SRCS:.c=.o)) libft/libft.a -ltermcap

clean:
	rm -rf ${OBJS}
	cd libft/ ; make fclean
	cd printf/ ; make fclean

fclean: clean
	rm -rf $(NAME)
	rm -rf libft/libft.a 
	rm -rf printf/libftprintf.a

re: fclean $(NAME)
