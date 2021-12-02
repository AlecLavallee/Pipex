/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:03:00 by alelaval          #+#    #+#             */
/*   Updated: 2021/12/02 16:53:33 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_fd(char *arg, char *path)
{
	int		fd;
	char	*tmp;

	if (arg)
	{
		ft_putstr(path);
		tmp = ft_strjoin(path, arg);
		ft_putstr(tmp);
		ft_putchar('\n');
		fd = open(tmp, O_RDONLY);
		free(tmp);
		return (fd);
	}
	return (-1);
}

int	test_func(t_pipex *pipex, char *arg, char **paths)
{
	int		fd;
	int		i;

	if (arg)
	{
		if (!ft_strncmp(arg, "/", 1) || !ft_strncmp(arg, "./", 2))
			fd = open(arg, O_RDONLY);
		else
		{
			i = 0;
			while (paths[i] && fd < 1)
				fd = get_fd(arg, paths[i++]);
		}
		return (fd);
	}
	error(pipex, EXIT_FAILURE);
	return (-1);
}

int	test_fd(t_pipex *pipex, char *arg)
{
	int	ret;

	if (arg)
	{
		ret = open(arg, O_RDONLY);
		return (ret);
	}
	error(pipex, EXIT_FAILURE);
	return (-1);
}

t_pipex	*parser(t_pipex *pipex, int count, char **args, char **paths)
{
	if (count == 5)
	{
		pipex->file1 = test_fd(pipex, args[1]);
		pipex->file2 = test_fd(pipex, args[4]);
		ft_putnbr_fd(pipex->file1, 1);
		ft_putchar('\n');
		ft_putnbr_fd(pipex->file2, 1);
		ft_putchar('\n');
		if ((pipex->file1 < 1) || (pipex->file2 < 1))
			error(pipex, EXIT_FAILURE);
		ft_putstr("fichiers bon\n");
		pipex->command1 = test_func(pipex, args[2], paths);
		pipex->command2 = test_func(pipex, args[3], paths);
		ft_putnbr_fd(pipex->command1, 1);
		ft_putchar('\n');
		ft_putnbr_fd(pipex->command2, 1);
		ft_putchar('\n');
		if ((pipex->command1 < 1) || (pipex->command2 < 1))
			error(pipex, EXIT_FAILURE);
		ft_putstr("commandes bonne\n");
		return (pipex);
	}
	error(pipex, EXIT_FAILURE);
	return (NULL);
}
