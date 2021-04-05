/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 00:05:44 by ppoinsin          #+#    #+#             */
/*   Updated: 2020/12/01 14:43:33 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int				is_in_flags(char *flags, char c);
int				precision(char *flag);
int				star_in_prec(char *flag);
int				star_in_field(char *flag);
int				min_field(char *flag);

void			remove_char(char **txt, char c, int keep);
int				is_correct(char c);
char			*ft_args(char *flags, va_list argpt, int len);
int				space(char *flag);
char			*prefix(char *flag, char **txt);

char			char_to_print(char *flag, int side);
char			*print_field(char *flag, char **txt, int size, int side);
int				treat_field(char **txt, char *flag);

int				skip_flag(char **flag, int *len);
void			treat_flag(char **str, va_list arg, int *len);
char			*is_in_arg(char *flag, char c);
int				is_hex(char *flags);
int				is_decimal(char *flags);

char			*puthex(__int128_t nbr, char *base);
char			*treat_hex(char *flag, char **txt);

char			**treat_prec(char **txt, char *flag);
int				treat_stars(char **flag, va_list arg);
__int128_t		size_bonus(char *flags, va_list argpt, int sign);
int				has_bonus(char *flags);
long long int	l_size(char *flags, va_list argpt, int sign, int *done);

int				len_flags(char *s);
int				ft_printf(const char *str, ...);
int				ft_isspace(char c);
int				write_free(char *txt, int null);

#endif
