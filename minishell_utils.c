/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:31:35 by fnochiza          #+#    #+#             */
/*   Updated: 2022/08/19 19:59:02 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_prompt1(void)
{
	ft_printf("MINISHELL > ");
}

void	print_prompt2(void)
{
	ft_printf("MINISHELL $> ");
}

char	*read_cmd(char *buf)
{
	int		buflen;
	char	*tmp;

	buflen = ft_strlen(buf);
	while (buflen > 1 && buf[buflen - 1] == '\\')
	{
		buf[buflen - 1] = '\n';
		buf[buflen] = '\0';
		print_prompt2();
		tmp = buf;
		buf = ft_strjoin(tmp, buf);
		buflen = ft_strlen(buf);
	}
	return (buf);
}

char	**dbl_realloc(char **arr, int oldsize, int inc)
{
	char	**ptr;
	char	*str;
	int		i;

	i = 0;
	ptr = (char **) malloc((oldsize + inc) * sizeof(char *));
	while (i < oldsize)
	{
		ptr[i] = ft_strjoin("", arr[i]);
		i++;
	}
	i = 0;
	while (i < oldsize)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (ptr);
}
