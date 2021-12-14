/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:38:48 by alelaval          #+#    #+#             */
/*   Updated: 2021/12/14 16:37:42 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_fd(char *arg, char *path)
{
	char	*tmp;

	tmp = NULL;
	if (arg && path)
	{
		arg = ft_strjoin("/", arg);
		tmp = ft_strjoin(path, arg);
		if (access(tmp, X_OK) == 0)
		{
			free(arg);
			free(tmp);
			return (0);
		}
		free(arg);
		free(tmp);
	}
	return (-1);
}

void	test_files(t_pipex *pipex, char **args)
{
	int	ret;

	ret = open(args[1], O_RDONLY);
	if (ret == -1)
	{
		perror("File1 ");
		error(pipex, EXIT_FAILURE);
	}
	ret = open(args[4], O_RDONLY);
	if (ret == -1)
	{
		perror("File2 ");
		error(pipex, EXIT_FAILURE);
	}
}
