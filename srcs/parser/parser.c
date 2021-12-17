/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:03:00 by alelaval          #+#    #+#             */
/*   Updated: 2021/12/17 18:59:05 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_fun(char *arg, char **paths)
{
	int		i;
	char	*tmp;
	char	*save;

	save = arg;
	if (ft_strchr(arg, '/') != NULL)
		return (arg);
	else
	{
		i = 0;
		arg = ft_strjoin("/", arg);
		while (paths[i])
		{
			tmp = ft_strjoin(paths[i], arg);
			// ft_putstr(tmp);
			// ft_putchar('\n');
			if (access(tmp, X_OK) == 0)
			{
				printf("ca marche %s\n", tmp);
				return (tmp);
			}
			printf("ca marche pas %s\n", tmp);
			free(tmp);
			i++;
		}
	}
	return (save);
}

void	get_args(t_pipex *pipex, char **args)
{
	pipex->args1 = ft_split(args[2], ' ');
	pipex->args2 = ft_split(args[3], ' ');
	// printf("%s, %s\n", pipex->command1, pipex->command2);
}

t_pipex	*parser(t_pipex *pipex, int count, char **args, char **paths)
{
	if (count == 5)
	{
		test_files(pipex, args);
		//ft_putstr("noice\n");
		get_args(pipex, args);
		//ft_putstr("noice2\n");
		pipex->command1 = get_fun(pipex->args1[0], paths);
		pipex->command2 = get_fun(pipex->args2[0], paths);
		//ft_putstr("noice3\n");
		printf("c'est lui qui marche pas -> %s %s\n", pipex->command1, pipex->command2);
		if (!pipex->command1 || !pipex->command2)
			error(pipex, EXIT_FAILURE);
		ft_putstr("noice4\n");
		return (pipex);
	}
	error(pipex, EXIT_FAILURE);
	return (NULL);
}
