/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stemsama <stemsama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:15:03 by stemsama          #+#    #+#             */
/*   Updated: 2023/03/05 15:44:05 by stemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	client_bonus(int sig)
{
	(void)sig;
	ft_putstr_fd("Every message received\n");
}

void	send_null(int pid, char argv)
{
	int	j;

	j = 7;
	while (j >= 0)
	{
		if (((argv >> j) & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(550);
		j--;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;
	int	j;

	signal(SIGUSR1, client_bonus);
	i = -1;
	if (argc != 3)
		exit(1);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		exit(1);
	while (argv[2][++i])
	{
		j = 7;
		while (j >= 0)
		{
			if (((argv[2][i] >> j) & 1) == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(550);
			j--;
		}
	}
	send_null(pid, argv[2][i]);
}
