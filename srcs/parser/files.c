/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:38:48 by alelaval          #+#    #+#             */
/*   Updated: 2021/12/17 17:17:29 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_fd(t_pipex *pipex, char *arg, int com, char *path)
{
	char	*tmp;

	tmp = NULL;
	if (arg && path)
	{
		arg = ft_strjoin("/", arg);
		tmp = ft_strjoin(path, arg);
		if (access(tmp, X_OK) == 0)
		{
			if (com == 1)
				pipex->command1 = tmp;
			else if (com == 2)
				pipex->command2 = tmp;
			return (0);
		}
		free(arg);
		free(tmp);
	}
	return (-1);
}

void	test_files(t_pipex *pipex, char **args)
{

	// enlever erreur et tout casser
	// tester dans premiere fonction
	// creer pour deuxieme fonction si pas dispo
	pipex->file1 = open(args[1], O_RDONLY);
	if (pipex->file1 == -1)
	{
		perror("File1 ");
		error(pipex, EXIT_FAILURE);
	}
	pipex->file2 = open(args[4], O_WRONLY | O_CREAT);
	if (pipex->file2 == -1)
	{
		perror("File2 ");
		error(pipex, EXIT_FAILURE);
	}
}
