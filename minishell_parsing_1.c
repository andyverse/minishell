/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parsing_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 18:43:21 by fnochiza          #+#    #+#             */
/*   Updated: 2022/09/05 15:06:54 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sngl_quot(char **arr, char *str, int i)
{
	(void) arr;
	(void) str;
	(void) i;
}

void	dbl_quot(char **arr, char *str, int i)
{
	(void) arr;
	(void) str;
	(void) i;
}

char	**new_arg(char **arr, char *str, int i, int *size)
{
	arr = dbl_realloc(arr, *size, 2);
	str[i] = '\0';
	arr[*size] = ft_strjoin("", str);
	arr[*size + 1] = NULL;
	(*size)++;
	free(str);
	return (arr);
}

char	**init_var(int *i, int *j, int *size)
{
	*i = 0;
	*j = 0;
	*size = 0;
	return (NULL);
}

void	inc_vars(int *i, int *j, char *str, char symbol)
{
	(*i)++;
	if (str == NULL)
		*j = 0;
	else
		(*j)++;
}

void	parsing(char *cmd)
{
	char	**arr;
	char	*str;
	int		size;
	int		i;
	int		j;

	arr = init_var(&i, &j, &size);
	str = NULL;
	while (i < ft_strlen(cmd) + 1)
	{
		str = ft_realloc(str, (ft_strlen(str) + 1));
		if ((cmd[i] == ' ') || (cmd[i] == '\0'))
		{
			arr = new_arg(arr, str, i, &size);
			str = NULL;
		}
		else if (ft_strchr(" \"\'", cmd[i]) == NULL)
			str[j] = cmd[i];
		else if (cmd[i] == '\'')
			sngl_quot(arr, str, i);
		else if (cmd[i] == '\"')
			dbl_quot(arr, str, i);
		inc_vars(&i, &j, str, cmd[i]);
	}
	i = 0;
	while (arr[i])
	{
		printf("%d) %s\n", i, arr[i]);
		i++;
	}
}
