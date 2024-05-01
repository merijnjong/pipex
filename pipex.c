/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:18:50 by mjong             #+#    #+#             */
/*   Updated: 2024/04/30 16:13:22 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_process(char **argv, char **envp, int *fd)
{
	int	infile;

	infile = open(argv[1], O_RDONLY, 0777);
	if (infile == -1)
		ft_error();
	ft_execute(argv[2], envp);
	ft_printf("infile: %d\n", infile);
	fd = 0;
}

void	ft_parent_process(char **argv, char **envp, int *fd)
{
	int	outfile;
	
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		ft_error();
	ft_execute(argv[3], envp);
	ft_printf("outfile: %d\n", outfile);
	fd = 0;
}

int	main(int argc, char **argv, char **envp)
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
			ft_child_process(argv, envp, fd);
		else
		{
			waitpid(pid, NULL, 0);
			ft_parent_process(argv, envp, fd);
		}
	}
	else
		ft_error();
	return (0);
}
