/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:57:07 by mjong             #+#    #+#             */
/*   Updated: 2024/07/25 16:26:25 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	ft_free_dbl(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

char	*ft_find_path(char *envp[], char *cmd)
{
	char	**paths;
	char	*temp;
	char	*path;
	int		i;

	i = 0;
	if (access(cmd, X_OK) == 0)
		return (cmd);
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i] != NULL)
	{
		temp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	ft_free_dbl(paths);
	return (0);
}

void	ft_execute(char *argv, char *envp[])
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	if (!cmd)
		ft_error("cmd");
	path = ft_find_path(envp, cmd[0]);
	if (path == NULL)
	{
		ft_free_dbl(cmd);
		perror("Incorrect argument");
		exit(127);
	}
	if (execve(path, cmd, envp) < 0)
		ft_error("execve");
}
