/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 16:11:21 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/04/05 15:45:45 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <dirent.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <signal.h>
# include <curses.h>
# include <term.h>
# include <sys/types.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include "libft.h"
# include <errno.h>
# define ENVDIR "environment.42"
# define UPARROW 4283163
# define DOWNARROW 4348699
# define RIGHTARROW 4414235
# define LEFTARROW 4479771
# define END_KEY 4610843
# define HOME_KEY 4741915
# define CTRLRIGHT 73895905418011
# define CTRLLEFT 74995417045787
# define CTRLUP 71696882162459
# define CTRLDOWN 72796393790235
# define CTRLX 24
# define CTRLW 23
# define CTRLP 16
# define INTRO_LENGTH 12
# define PERMISSION_ERROR "Shell42 : Cannot execute (Permission)\n"

# define COLOR_HIGHLIGHT COLOR_GREEN

enum				e_type
{
	NONE, WRITE, APPEND, READ, ERROR
};

typedef struct		s_pipe
{
	enum e_type		type;
	int				fd;
	char			*arg;
}					t_pipe;

typedef struct		s_shell
{
	char			**env;
	int				size_env;
	char			**cmds;
	t_list			*history;
	char			*input;
	char			indexcmd;
	int				lignes;
	int				indexinput;
	int				cursor;
	int				*pipes;
	int				number_of_pipes;
	int				exit_status;
	int				selection[2];
	char			*copy;
	int				cols;
	t_pipe			stdin;
	t_pipe			stdout;
}					t_shell;

extern t_shell		g_shell;

int					find_dir(char *path, char *file);
int					exec_bin_script(char **cmd);
int					running_bin(char **cmd);
int					ft_env(void);
int					ft_pwd(char **cmd);
int					ft_cd(char **cmd);
int					ft_export(char **cmd);
int					ft_unset(char **cmd);
int					ft_echo(char **cmd);
int					manage_pipe(char *cmd);
int					manage_exec(char **cmd);
int					count_true_guil(char *str);
void				print_intro(void);
int					print_input(void);
int					size_intro(void);
int					min_size(void);
int					myputchar(int c);
void				refresh_cmd(char **input);
int					print_terminal(char *entry);
int					check_arrow(long *entry, char mode);
int					has_real_char(char *str);
int					check_escape(long *entry);
int					check_ctrl(long *entry);
void				sigint_handler(int a);
void				sigresize_handler(int a);
void				sigquit_handler(int a);
char				**treat_args(char **cmd);
void				boucle(int a);
void				set_terminal(void);

int					delete_char(void);

char				*get_env_var(char *name);
char				*get_env_var_two(char *name);
int					add_env_var(char *str);
int					init_env_var(void);
int					gives_var_size(char *str);
char				*env_var_input(char *input);
char				**gives_path_var(void);
char				*input_chars(char *input);
char				**sort_env(char **cmd);
char				**env_remove(char **cmd, char *name);

char				ft_comp_word(char *str, char *str2);
char				ft_check_pipe(char *str, char *str2);
int					size_until(char *str, char c);
int					size_word(char *str);
char				*next_word(char *str);
char				*pipe_next_word(char *str);
char				*previous_word(char *str, int index);

int					free_shell(void);
int					init_shell(void);

int					duplicate_pipes(void);
int					close_pipes(void);
int					clear_pipe(t_pipe *pipe);

char				*delete_pipes(char *cmd);
int					find_pipe(char *str);
char				check_pipe_format(void);
char				check_pipe_arg(void);
int					check_input(void);
int					init_pipe(t_pipe *pipe);
int					setup_pipe(t_pipe *pipe, int type, char *arg);

int					check_guill(char *str, int index);
char				*delete_every_guill(char *str);
int					is_contained_between(char *str, char *index, char *c1,
		char *c2);
char				is_between_guill(char *str, char *tmp);
char				*delete_every_char(char *str, char c);

void				list_lst(void);
t_list				*get_n_lst(t_list *lst, int n);

void				index_next_word(void);
void				index_previous_word(void);
void				clear_buffer(void);
void				place_cursor(int index);

char				**ft_shell_split(char const *s, char c);
int					ft_abs(int a);

int					selection(int index);
int					reset_highlight(int cursor_pos);
int					highlight_selection(int color);

void				increment_shlvl(void);
void				add_dyn_variable(char **cmd);
#endif
