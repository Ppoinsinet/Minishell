/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 00:07:07 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/04/05 17:30:34 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGS_H
# define STRINGS_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

char		*ft_strncpy(char *dest, char *src, unsigned int n);
char		*ft_strcpy(char *dest, char *src);
char		*ft_strreplace(char *str, char *str2, int index);
char		*ft_strremove(char *str, int index, int rem);
char		*appendstart(char *dst, char *src);
char		*appendend(char *dst, char *src);
char		*appendend_char(char *dst, char c, int n);
char		*appendstart_char(char *dst, char c, int n);
char		*appendchar(char c, int n);
int			is_correct(char c);
int			modify_tab(int *tab, int valeur);
int			*count_cases(char *txt);
void		init_tab(int *tab, char *txt);
void		remove_char(char **flag, char c, int keep);

#endif
