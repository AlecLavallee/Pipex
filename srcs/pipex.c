/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:53:24 by alelaval          #+#    #+#             */
/*   Updated: 2021/12/14 16:41:50 by alelaval         ###   ########.fr       */
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

void	ft_pipex(t_pipex *pipex)
{
	int		end[2];
	int		status;
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(end) == -1)
	{
		perror("Pipe ");
		error(pipex, EXIT_FAILURE);
	}
	pipex->end = end;
	pid1 = fork();
	if (pid1 < 0)
	{
		perror("Fork ");
		error(pipex, EXIT_FAILURE);
	}
	pid2 = fork();
	if (pid2 < 0)
	{
		perror("Fork ");
		error(pipex, EXIT_FAILURE);
	}
	close(pipex->end[0]);
	close(pipex->end[1]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
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
		pipex->envp = envp;
		parser(pipex, num_args, args, paths);
		ft_pipex(pipex);
		free_all(pipex, EXIT_SUCCESS);
	}
	return (0);
}
