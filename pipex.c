/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjong <mjong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:18:50 by mjong             #+#    #+#             */
/*   Updated: 2024/04/24 17:05:09 by mjong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void	id_two_is_zero(int id1, int id2)
// {
// 	waitpid(id1, NULL, 0);
// 	id2 = fork();
// 	if (id2 == 0)
// 		ft_printf("I only have a father\n");
// 	else
// 	{
// 		waitpid(id2, NULL, 0);
// 		ft_printf("I have a son and a grandson\n");
// 	}
// }

// void	id_one_is_zero(int id2)
// {
// 	id2 = fork();
// 	if (id2 == 0)
// 		ft_printf("I have a father and a grandfather\n");
// 	else
// 	{
// 		waitpid(id2, NULL, 0);
// 		ft_printf("I have a son and a father\n");
// 	}
// }

// int	main(void)
// {
// 	int	id1;
// 	int	id2;

// 	id1 = fork();
// 	id2 = 0;
// 	if (id1 == 0)
// 		id_one_is_zero(id2);
// 	else
// 		id_two_is_zero(id1, id2);
// 	return (0);
// }

// int	main(void)
// {
// 	int	fd[2];
// 	int	id;
// 	int	x;
// 	int y;
// 	if (pipe(fd) == -1)
// 	{
// 		ft_printf("An error occured with opening the pipe\n");
// 		return (1);
// 	}
// 	id = fork();
// 	if (id == -1)
// 	{
// 		ft_printf("An error occured with fork\n");
// 		return (2);
// 	}
// 	if (id == 0)
// 	{
// 		close(fd[0]);
// 		ft_printf("Input a number: ");
// 		scanf("%d", &x);
// 		if (write(fd[1], &x, sizeof(int)) == -1)
// 		{
// 			ft_printf("An error occured with writing to the pipe\n");
// 			return (3);
// 		}
// 		close(fd[1]);
// 	}
// 	else
// 	{
// 		close(fd[1]);
// 		if (read(fd[0], &y, sizeof(int)) == -1)
// 		{
// 			ft_printf("An error occured with reading from the pipe\n");
// 			return (4);
// 		}
// 		close(fd[0]);
// 		printf("Got from child process: %d\n", y);
// 	}
// 	return (0);
// }

int	main(void)
{
	int	arr[] = { 1, 2, 3, 4, 1, 2, 7, 7 };
	int arrSize = sizeof(arr) / sizeof(int);
	int	fd[2];
	int	id;
	int	start;
	int	end;
	if (pipe(fd) == 1)
		return (1);
	id = fork();
	if (id == -1)
		return (2);
	if (id == 0)
	{
		start = 0;
		end = arrSize / 2;
	}
	else
	{
		waitpid(id, NULL, 0);
		start = arrSize / 2;
		end = arrSize;
	}
	int	sum;
	int	i;

	sum = 0;
	i = start;
	while (i < end)
	{
		sum += arr[i];
		i++;
	}
	ft_printf("Calculated partial sum: %d\n", sum);
	int	sumFromSon;
	int	totalSum;

	if (id == 0)
	{
		close(fd[0]);
		if (write(fd[1], &sum, sizeof(sum)) == -1)
			return (3);
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		if (read(fd[0], &sumFromSon, sizeof(sumFromSon)) == -1)
			return (4);
		close(fd[0]);
		totalSum = sum + sumFromSon;
		ft_printf("Total sum: %d\n", totalSum);
	}
	return (0);
}
