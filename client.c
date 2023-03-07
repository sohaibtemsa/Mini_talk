/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stemsama <stemsama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:06:02 by stemsama          #+#    #+#             */
/*   Updated: 2023/03/05 15:42:25 by stemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int	pid;
	int	i;
	int	j;

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
}
