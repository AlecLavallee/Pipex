/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:53:24 by alelaval          #+#    #+#             */
/*   Updated: 2021/12/08 20:06:18 by alelaval         ###   ########.fr       */
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
	pipex->command1 = NULL;
	pipex->command2 = NULL;
	pipex->args1 = NULL;
	pipex->args2 = NULL;
	return (pipex);
}

int	main(int num_args, char **args, char **env)
{
	int		j;
	int		k;
	char	buffer[255];
	t_pipex	*pipex;
	char	**paths;

	pipex = NULL;
	if (num_args > 2)
	{
		pipex = init_all();
		j = 0;
		k = 0;
		while (env[21][j])
		{
			if (j >= 5 && !ft_isspace(env[21][j]))
			{
				buffer[k] = env[21][j];
				k++;
			}
			j++;
		}
		buffer[k] = '\0';
		paths = ft_split(buffer, ':');
		parser(pipex, num_args, args, paths);
		free_all(pipex, EXIT_SUCCESS);
	}
	return (0);
}
