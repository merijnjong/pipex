/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:18:50 by mjong             #+#    #+#             */
/*   Updated: 2024/04/25 15:38:10 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_process(char *argv[], int *fd)
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		ft_error();
	ft_printf("infile: %d\n", infile);
	fd = 0;
}

void	ft_parent_process(char *argv[], int *fd)
{
	int	outfile;
	
	outfile = open(argv[4], O_RDONLY);
	if (outfile == -1)
		ft_error();
	ft_printf("outfile: %d\n", outfile);
	fd = 0;
}

int	main(int argc, char *argv[])
{
	int	pid;
	int	fd[2];

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			ft_error();	
		pid = fork();
		if (pid == -1)
			ft_error();
		if (pid == 0)
			ft_child_process(argv, fd);
		else
		{
			waitpid(pid, NULL, 0);
			ft_parent_process(argv, fd);
		}
	}
	else
		ft_error();
	return (0);
}
