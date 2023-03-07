/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stemsama <stemsama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:06:06 by stemsama          #+#    #+#             */
/*   Updated: 2023/02/18 20:02:22 by stemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

void	ft_atoi_trois(void);
int		ft_atoi(char *str);
void	ft_putnbr_fd(int n);
void	ft_putstr_fd(char const *s);
void	ft_putchar_fd(char c);

#endif