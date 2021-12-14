/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:53:20 by alelaval          #+#    #+#             */
/*   Updated: 2021/12/14 17:07:05 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include "../libft/headers/libft.h"

typedef struct s_pipex
{
	int			pid1;
	int			pid2;
	int			file1;
	int			file2;
	const int	*end;
	char		*command1;
	char		*command2;
	char		**args1;
	char		**args2;
	char		**envp;

}				t_pipex;

t_pipex	*init_all(void);
t_pipex	*parser(t_pipex *pipex, int count, char **args, char **paths);
void	first_command(t_pipex *pipex);
void	second_command(t_pipex *pipex);
int		get_fd(char *arg, char *path);
void	test_files(t_pipex *pipex, char **args);
int		size_array(char **array);
void	free_all(t_pipex *pipex, int code);
void	error(t_pipex *pipex, int code);

#endif