/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:20:37 by alelaval          #+#    #+#             */
/*   Updated: 2021/12/14 17:07:30 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_command(t_pipex *pipex)
{
	dup2(pipex->file1, STDIN_FILENO);
	dup2(pipex->end[1], STDOUT_FILENO);
	close(pipex->end[0]);
	close(pipex->file1);
	exit(EXIT_FAILURE);
}

void	second_command(t_pipex *pipex)
{
	dup2(pipex->file2, 1);
	dup2(pipex->end[0], STDIN_FILENO);
	close(pipex->end[1]);
	close(pipex->file2);
	exit(EXIT_FAILURE);
}
