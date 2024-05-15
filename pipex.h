/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:19:17 by mjong             #+#    #+#             */
/*   Updated: 2024/05/15 16:49:43 by mjong            ###   ########.fr       */
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

void	ft_error(void);
void	ft_execute(char *argv, char *envp[]);

#endif