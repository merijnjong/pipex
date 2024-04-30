/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:57:07 by mjong             #+#    #+#             */
/*   Updated: 2024/04/25 17:22:24 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_execute(char *argv, char **envp)
{
	const char	*path;
	char		**cmd;

	path = "/usr/local/bin/pipex";
	cmd = ft_split(argv, ' ');
	// ft_printf("%p\n", cmd);
	if (execve(path, cmd, envp) == -1)
		ft_error();
}
