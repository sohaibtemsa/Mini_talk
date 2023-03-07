/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stemsama <stemsama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:08:46 by stemsama          #+#    #+#             */
/*   Updated: 2023/02/19 23:37:33 by stemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_recived(int signal, siginfo_t *rec_pid, void *nothing)
{
	static unsigned char	c;
	static int				i;
	static int				pid;

	(void)nothing;
	if (pid != rec_pid->si_pid)
	{
		i = 0;
		c = 0;
	}
	c <<= 1;
	if (signal == SIGUSR1)
		c |= 1;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
	pid = rec_pid->si_pid;
}

int	main(void)
{
	struct sigaction	rec_sig;

	ft_putnbr_fd(getpid());
	write(1, "\n", 1);
	rec_sig.sa_sigaction = sig_recived;
	rec_sig.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &rec_sig, NULL);
	sigaction(SIGUSR2, &rec_sig, NULL);
	while (1)
		pause();
	return (0);
}
