NAME = libft.a

LIBFT = ft_2split.c ft_atof.c ft_atoi.c ft_bzero.c ft_calloc.c ft_fpow.c ft_ftoa.c ft_isalnum.c \
		ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isnum.c ft_isprint.c ft_itoa.c ft_lstadd_back.c \
		ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c \
		ft_lstnew.c ft_lstsize.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
		ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_split.c ft_strchr.c \
		ft_strcmp.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
		ft_strndup.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
		get_next_line.c ft_strncpy.c ft_strstr.c ft_strreplace.c ft_multi_split.c extract_str.c \
		ft_strinsert.c ft_strremove.c ft_strcpy.c


#LIB_OBJS = $(addprefix libft/, $(LIBFT:.c=.o))
LIB_OBJS = $(LIBFT:.c=.o)

FLAGS = -Wall -Wextra -Werror

CC = clang ${FLAGS}

all: $(NAME)

.c.o:
	$(CC) -c $< -o $(<:.c=.o) -g

$(NAME): $(LIB_OBJS)
	ar rcs $(NAME) $(LIB_OBJS)

clean:
	rm -rf ${LIB_OBJS}

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)
