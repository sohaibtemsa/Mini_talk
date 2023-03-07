/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stemsama <stemsama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:09:02 by stemsama          #+#    #+#             */
/*   Updated: 2023/02/18 19:02:03 by stemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar_fd(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_fd(char const *s)
{
	if (!s)
		return ;
	while (*s)
		write(1, s++, 1);
}

void	ft_putnbr_fd(int n)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648");
	else
	{
		if (n < 0)
		{
			n = -n;
			ft_putchar_fd('-');
		}
		if (n > 9)
		{
			ft_putnbr_fd(n / 10);
		}
		ft_putchar_fd((n % 10) + 48);
	}
}

int	ft_atoi(char *str)
{
	int			res;
	long long	cas;
	int			sin;

	res = 0;
	sin = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sin = -1;
		str++;
	}
	while (*str && *str <= '9' && *str >= '0')
	{
		cas = res;
		res = res * 10 + *str++ - 48;
		if (cas != res / 10)
			ft_atoi_trois();
	}
	return (res * sin);
}

void	ft_atoi_trois(void)
{
	write(2, "Error\n", 6);
	exit(0);
}
