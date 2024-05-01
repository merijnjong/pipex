/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:57:07 by mjong             #+#    #+#             */
/*   Updated: 2024/04/30 17:02:48 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

const char	*ft_find_path(char **cmd)
{
	
}

void	ft_execute(char *argv, char **envp)
{
	char		**cmd;
	const char	*path;

	cmd = ft_split(argv, ' ');
	path = ft_find_path(cmd);
	// ft_printf("%p\n", cmd);
	if (execve(path, cmd, envp) == -1)
		ft_error();
}
