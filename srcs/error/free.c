/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:36:30 by alelaval          #+#    #+#             */
/*   Updated: 2021/11/29 13:49:22 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_pipex(int code)
{
	exit(code);
}

void	free_all(t_pipex *pipex, int code)
{
	free(pipex);
	close_pipex(code);
}
