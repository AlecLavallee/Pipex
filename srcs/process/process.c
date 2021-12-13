/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:20:37 by alelaval          #+#    #+#             */
/*   Updated: 2021/12/13 19:36:16 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_pipex *pipex)
{
	dup2(pipex->file1, STDIN_FILENO);
	dup2(pipex->end2, STDOUT_FILENO);
	close(pipex->end1);
	close(pipex->file1);
	exit(EXIT_FAILURE);
}

void	parent_process(t_pipex *pipex)
{
	int	status;

	waitpid(-1, &status, 0);
	dup2(pipex->file2, 1);
	close(pipex->end2);
	close(pipex->file2);
	exit(EXIT_FAILURE);
}
