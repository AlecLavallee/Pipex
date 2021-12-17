/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:53:24 by alelaval          #+#    #+#             */
/*   Updated: 2021/12/17 19:03:07 by alelaval         ###   ########.fr       */
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

char	*get_path_line(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		if (ft_strncmp("PATH=", paths[i], 5) == 0)
			return (paths[i] + 5);
		i++;
	}
	return (NULL);
}

char	**get_paths(t_pipex *pipex, char **envp)
{
	char	**paths;
	char	*path;

	path = get_path_line(envp);
	if (path == NULL)
		error(pipex, EXIT_FAILURE);
	printf("%s\n", path);
	paths = ft_split(path, ':');
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

	ft_putstr("pipex\n");
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
	if (pid1 == 0)
		first_command(pipex);
	pid2 = fork();
	if (pid2 < 0)
	{
		perror("Fork ");
		error(pipex, EXIT_FAILURE);
	}
	if (pid2 == 0)
		second_command(pipex);
	close(pipex->end[0]);
	close(pipex->end[1]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
	ft_putstr("noice\n");
}

int	main(int num_args, char **args, char **envp)
{
	t_pipex	*pipex;
	char	**paths;

	pipex = NULL;
	if (num_args > 2)
	{
		pipex = init_all();
		paths = get_paths(pipex, envp);
		pipex->envp = envp;
		parser(pipex, num_args, args, paths);
		ft_pipex(pipex);
		free_all(pipex, EXIT_SUCCESS);
	}
	return (0);
}
