/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:18:50 by mjong             #+#    #+#             */
/*   Updated: 2024/06/19 15:24:33 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

pid_t	ft_child1_process(char *argv[], char *envp[], int *fd)
{
	int		infile;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_error("fork");
	if (pid == 0)
	{
		close(fd[0]);
		infile = open(argv[1], O_RDONLY, 0777);
		if (infile == -1)
			ft_error("infile not found");
		dup2(infile, 0);
		close(infile);
		dup2(fd[1], 1);
		close(fd[1]);
		if ((ft_strcmp(argv[2], "") == 0) || (argv[2][0] == ' '))
		{
			errno = 13;
			ft_error("argv 2");
		}
		ft_execute(argv[2], envp);
	}
	return (pid);
}

pid_t	ft_child2_process(char *argv[], char *envp[], int *fd)
{
	int		outfile;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_error("fork");
	if (pid == 0)
	{
		close(fd[1]);
		outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (outfile == -1)
			ft_error("outfile not found");
		dup2(outfile, 1);
		close(outfile);
		dup2(fd[0], 0);
		close(fd[0]);
		if ((ft_strcmp(argv[3], "") == 0) || (argv[3][0] == ' '))
		{
			errno = 13;
			ft_error("argv 3");
		}
		ft_execute(argv[3], envp);
	}
	return (pid);
}

int	main(int argc, char *argv[], char *envp[])
{
	pid_t	pid;
	int		fd[2];
	int		status;

	if (argc != 5)
		ft_error("\033[31mError: Incorrect notation\n\e[0m\n\
		Example: ./pipex <file1> <cmd1> <cmd2> <file2>\n");
	if (pipe(fd) == -1)
		ft_error("pipe");
	pid = ft_child1_process(argv, envp, fd);
	pid = ft_child2_process(argv, envp, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid, &status, 0);
	while (wait(NULL) != -1)
		;
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (EXIT_FAILURE);
}
