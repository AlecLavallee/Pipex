/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:36:30 by alelaval          #+#    #+#             */
/*   Updated: 2021/12/02 12:41:39 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_pipex(int code)
{
	exit(code);
}

void	free_all(t_pipex *pipex, int code)
{
	if (pipex->file1)
		close(pipex->file1);
	if (pipex->file2)
		close(pipex->file2);
	free(pipex);
	close_pipex(code);
}
