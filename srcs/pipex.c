/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:53:24 by alelaval          #+#    #+#             */
/*   Updated: 2021/12/13 17:35:42 by alelaval         ###   ########.fr       */
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

char	**get_paths(char **envp)
{
	int		i;
	int		j;
	char	buffer[255];
	char	**paths;

	i = 0;
	j = 0;
	while (envp[21][j])
	{
		if (j >= 5 && !ft_isspace(envp[21][j]))
		{
			buffer[i] = envp[21][j];
			i++;
		}
		j++;
	}
	buffer[i] = '\0';
	paths = ft_split(buffer, ':');
	if (paths)
		return (paths);
	return (NULL);
}

void	ft_pipex(t_pipex *pipex, char **envp)
{
	if (!execve(pipex->command1, pipex->args1, envp))
		error(pipex, EXIT_FAILURE);
	if (!execve(pipex->command2, pipex->args2, envp))
		error(pipex, EXIT_FAILURE);
	ft_putstr("Pipex done\n");
}

int	main(int num_args, char **args, char **envp)
{
	t_pipex	*pipex;
	char	**paths;

	pipex = NULL;
	if (num_args > 2)
	{
		pipex = init_all();
		paths = get_paths(envp);
		parser(pipex, num_args, args, paths);
		ft_pipex(pipex, envp);
		free_all(pipex, EXIT_SUCCESS);
	}
	return (0);
}
