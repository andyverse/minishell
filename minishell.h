/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:21:18 by fnochiza          #+#    #+#             */
/*   Updated: 2022/09/04 22:05:40 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include "libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

typedef struct unit
{
	char		*key;
	char		*value;
	struct unit	*next;
}	t_list_unit;

typedef struct list
{
	int			size;
	t_list_unit	*first;
}	t_list;

void	parsing(char *cmd);
void	print_prompt1(void);
void	print_prompt2(void);
char	*read_cmd(char *buf);
char	**dbl_realloc(char **arr, int oldsize, int inc);
void	inc_vars(int *i, int *j, char *str, char symbol);
char	**init_var(int *i, int *j, int *size);
void	dbl_quot(char **arr, char *str, int i);
void	sngl_quot(char **arr, char *str, int i);

#endif