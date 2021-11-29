/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:03:00 by alelaval          #+#    #+#             */
/*   Updated: 2021/11/29 15:21:33 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parse_arg(char *arg)
{
	(void)arg;
}

t_pipex	*parser(t_pipex *pipex, int count, char **args)
{
	int	i;

	i = 1;
	while (count-- > 1)
	{
		ft_putstr(args[i++]);
		ft_putchar('\n');
	}
	return (pipex);
}
