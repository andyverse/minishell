/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 19:19:06 by fnochiza          #+#    #+#             */
/*   Updated: 2022/09/05 15:10:47 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parsing(char *cmd);

char	*ft_readline(char *prompt)
{
	char	*str;

	str = readline(prompt);
	if (str)
		add_history(str);
	return (str);
}

t_list	*create_list(void)
{
	t_list		*list;

	list = (t_list *) malloc(sizeof(t_list));
	list->size = 0;
	list->first = NULL;
	return (list);
}

void	add_last_elem(t_list *list, char *key, char *value)
{
	t_list_unit	*unit;
	t_list_unit	*unitf;

	unitf = list->first;
	if (unitf)
		while (unitf->next != NULL)
			unitf = unitf->next;
	unit = (t_list_unit *) malloc(sizeof(t_list_unit));
	if (!unit)
		return ;
	unit->key = ft_strjoin("", key);
	unit->value = ft_strjoin("", value);
	unit->next = NULL;
	if (list->first == NULL)
		list->first = unit;
	else
		unitf->next = unit;
	list->size++;
}

void	init_envp(t_list *list, char **envp)
{
	int			i;
	char		**split;
	char		*str1;
	char		*str2;
	t_list_unit	*unit;

	i = 0;
	while (envp[i] != NULL)
	{
		split = ft_split(envp[i], '=');
		add_last_elem(list, split[0], split[1]);
		free(split[0]);
		free(split[1]);
		free(split);
		i++;
	}
}

void	change(char **str)
{
	free(str);
	str = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	int			i;
	char		*cmd;
	char		*str;
	char		**mas;
	char		**arr;
	t_list		*envp_list;
	t_list_unit	*unit;

	(void) argc;
	(void) argv;
	(void) cmd;
	i = 0;
	cmd = NULL;
	// (*str) = ft_strjoin("", "sdfghgf");
	// printf("%s\n", *str);
	// change(str);
	// printf("%s\n", *str);
	//printf("HEY\n");
	envp_list = create_list();
	init_envp(envp_list, envp);
	unit = envp_list->first;
	while (1)
	{
		cmd = ft_readline("MINISHELL > ");
		//cmd = "OJEOFI ";
		parsing(cmd);
		exit(1);
	}
}
