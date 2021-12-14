/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:03:00 by alelaval          #+#    #+#             */
/*   Updated: 2021/12/14 16:31:42 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	test_func(t_pipex *pipex, int com, char **paths)
{
	int			i;
	int			ret;
	const char	*arg;

	if (com == 1)
		arg = (const char *)pipex->command1;
	else if (com == 2)
		arg = (const char *)pipex->command2;
	if (!ft_strncmp(arg, "/", 1) || !ft_strncmp(arg, "./", 2))
	{
		if (access(arg, R_OK) == 0)
			return (0);
	}
	else
	{
		i = 0;
		ret = -1;
		while (paths[i] && ret < 0)
			ret = get_fd((char *)arg, paths[i++]);
		return (ret);
	}
	return (-1);
}

char	**fill_args(char **args)
{
	int		i;
	int		size;
	char	**array;

	i = 0;
	size = size_array(args);
	array = (char **)(malloc(sizeof(char *) * size + 1));
	while ((size - 1) > 0)
	{
		array[i] = ft_strdup(args[i + 1]);
		size--;
		i++;
	}
	array[i] = NULL;
	if (args)
	{
		i = 0;
		while (args[i])
			free(args[i++]);
		free(args);
	}
	return (array);
}

void	get_args(t_pipex *pipex, char *arg, int com)
{
	char	**args;

	if (arg)
	{
		args = ft_split(arg, ' ');
		if (com == 1)
		{
			pipex->command1 = ft_strdup((const char *)args[0]);
			pipex->args1 = fill_args(args);
		}
		else if (com == 2)
		{
			pipex->command2 = ft_strdup((const char *)args[0]);
			pipex->args2 = fill_args(args);
		}
		return ;
	}
	error(pipex, EXIT_FAILURE);
}

t_pipex	*parser(t_pipex *pipex, int count, char **args, char **paths)
{
	if (count == 5)
	{
		test_files(pipex, args);
		get_args(pipex, args[2], 1);
		get_args(pipex, args[3], 2);
		if (test_func(pipex, 1, paths) == -1
			|| test_func(pipex, 2, paths) == -1)
			error(pipex, EXIT_FAILURE);
		if (!pipex->command1 || !pipex->command2)
			error(pipex, EXIT_FAILURE);
		return (pipex);
	}
	error(pipex, EXIT_FAILURE);
	return (NULL);
}
