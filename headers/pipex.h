/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:53:20 by alelaval          #+#    #+#             */
/*   Updated: 2021/12/08 20:06:22 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/headers/libft.h"

typedef struct s_pipex
{
	int			file1;
	int			file2;
	char		*command1;
	char		*command2;
	char		**args1;
	char		**args2;
}				t_pipex;

t_pipex	*init_all(void);
t_pipex	*parser(t_pipex *pipex, int count, char **args, char **paths);
void	free_all(t_pipex *pipex, int code);
void	error(t_pipex *pipex, int code);

#endif