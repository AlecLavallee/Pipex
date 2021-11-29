/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:53:24 by alelaval          #+#    #+#             */
/*   Updated: 2021/11/29 15:35:35 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pipex	*init_all(void)
{
	t_pipex	*pipex;

	pipex = (t_pipex *)malloc((sizeof(t_pipex)));
	if (!pipex)
		error(pipex, EXIT_FAILURE);
	pipex->file1 = 0;
	pipex->file2 = 0;
	return (pipex);
}

int	main(int num_args, char **args)
{
	t_pipex	*pipex;

	pipex = NULL;
	if (num_args > 2)
	{
		pipex = init_all();
		ft_putstr(args[1]);
		parser(pipex, num_args, args);
		free_all(pipex, EXIT_SUCCESS);
	}
	return (0);
}
