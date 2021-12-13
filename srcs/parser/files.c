/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:38:48 by alelaval          #+#    #+#             */
/*   Updated: 2021/12/09 13:39:20 by alelaval         ###   ########.fr       */
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