/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:53:20 by alelaval          #+#    #+#             */
/*   Updated: 2021/11/29 15:22:05 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/headers/libft.h"

typedef struct s_pipex
{
	int			file1;
	int			file2;
}				t_pipex;

t_pipex	*init_all(void);
t_pipex	*parser(t_pipex *pipex, int count, char **args);
void	free_all(t_pipex *pipex, int code);
void	error(t_pipex *pipex, int code);

#endif