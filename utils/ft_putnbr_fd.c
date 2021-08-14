/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukio <ukio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:04:17 by atawana           #+#    #+#             */
/*   Updated: 2021/08/10 10:59:19 by atawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

#define BUFFER_SIZE 13

static long	ft_abs(long i)
{
	return ((long)ft_ternary_ll(i < 0, -i, i));
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nn;

	nn = n;
	if ((ft_abs(nn)) >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd((ft_abs(nn) % 10) + '0', fd);
	}
	else
	{
		if (n < 0)
			ft_putchar_fd('-', fd);
		ft_putchar_fd((ft_abs(nn) % 10) + '0', fd);
	}
}

void	ft_putulong_fd(unsigned long long nbr, int fd)
{
	if (nbr >= 10)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putchar_fd((nbr % 10) + '0', fd);
	}
	else
		ft_putchar_fd((nbr % 10) + '0', fd);
}
