/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:18:50 by mjong             #+#    #+#             */
/*   Updated: 2024/05/16 16:12:11 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child1_process(char *argv[], char *envp[], int *fd)
{
	int	infile;

	close(fd[0]);
	infile = open(argv[1], O_RDONLY, 0777);
	if (infile == -1)
		ft_error("infile not found");
	dup2(infile, 0);
	close(infile);
	dup2(fd[1], 1);
	close(fd[1]);
	ft_execute(argv[2], envp);
}

void	ft_child2_process(char *argv[], char *envp[], int *fd)
{
	int	outfile;

	close(fd[1]);
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		ft_error("outfile not found");
	dup2(outfile, 1);
	close(outfile);
	dup2(fd[0], 0);
	close(fd[0]);
	if (ft_strcmp(argv[3], "") == 0)
		ft_error("argv 3");
	ft_execute(argv[3], envp);
}

int	main(int argc, char *argv[], char *envp[])
{
	pid_t	pid;
	int		fd[2];
	int		status;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			ft_error("pipe");
		pid = fork();
		if (pid == -1)
			ft_error("fork");
		if (pid == 0)
		{
			ft_child1_process(argv, envp, fd);
			exit(1);
		}
		close(fd[1]);
		wait(NULL);
		pid = fork();
		if (pid == -1)
			ft_error("fork");
		if (pid == 0)
		{
			ft_child2_process(argv, envp, fd);
			exit(1);
		}
		waitpid(pid, &status, 0);
	}
	else
	{
		ft_putstr_fd("\033[31mError: Incorrect notation\n\e[0m", 2);
		ft_putstr_fd("Example: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
	}
	return (0);
}
