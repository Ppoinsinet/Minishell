/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:49:37 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/04/02 20:04:53 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

__int128_t			ft_atoi(const char *str);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
void				ft_bzero(void *s, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

char				*ft_strncpy(char *dest, char *src, unsigned int n);
char				*ft_strreplace(char *str, char *to_remove,
		char *to_replace);
char				*ft_strreplace_spec(char *str, char *to_remove,
		char *to_replace);
char				*ft_strreplace_pipe(char *str, char *to_remove,
		char *to_replace);
char				*ft_strstr(char *str, char *to_find);
char				*ft_strchr(char *s, char c);
char				*ft_strdup(const char *s);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strjoin_free(char *s1, char *s2);
char				*ft_strjoin_gnl(char *s1, char *s2);
char				*ft_strjoin_free_two(char *s1, char *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				**ft_multi_split(char *str, int n, char *chars);
int					free_split(char ***split);
char				**ft_2split(char const *s, char c, char c2);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

size_t				ft_strlen(const char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

char				*ft_strinsert(char *str, char *str2, int index);
char				*ft_strinsert_free(char *str, char *str2, int index);
char				*ft_strremove(char *str, int index, int num);

int					ft_strcmp(char *s1, char *s2);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*extract_str(char *str);

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
void (*del)(void *));

int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);

float				ft_fpow(float n, int power);
__int128_t			ft_pow(int n, int power);
int					size_min(long double n);
int					gives_prec(long double n, int prec);
long double			arrondis(long double n, int prec);
char				*float_error(long double n, int *prec);

char				*ft_strndup(const char *s, size_t n);
char				*ft_itoa(__int128_t n);
char				*ft_ftoa(long double n, int prec);
float				ft_atof(char *s);

int					count_print(char *buff);
int					get_next_line(int fd, char **line);
int					moves_buff(char *buff, int cursor);
# define BUFFER_SIZE 30

#endif
