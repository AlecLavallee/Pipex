/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:36:30 by alelaval          #+#    #+#             */
/*   Updated: 2021/12/08 20:10:51 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_pipex(int code)
{
	exit(code);
}

void	free_all(t_pipex *pipex, int code)
{
	int	i;

	if (pipex->file1)
		close(pipex->file1);
	if (pipex->file2)
		close(pipex->file2);
	if (pipex->command1)
		free(pipex->command1);
	if (pipex->command2)
		free(pipex->command2);
	if (pipex->args1)
	{
		i = 0;
		while (pipex->args1[i])
			free(pipex->args1[i++]);
	}
	if (pipex->args2)
	{
		i = 0;
		while (pipex->args2[i])
			free(pipex->args2[i++]);
	}
	free(pipex);
	close_pipex(code);
}
