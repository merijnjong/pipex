/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:19:17 by mjong             #+#    #+#             */
/*   Updated: 2024/05/16 13:47:35 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>

void	ft_error(const char *msg);
void	ft_execute(char *argv, char *envp[]);
// char	*ft_find_path(char *envp[], char *cmd);
// void	ft_free_dbl(char **ptr);

#endif