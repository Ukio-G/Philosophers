/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukio <ukio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:44:51 by atawana           #+#    #+#             */
/*   Updated: 2021/08/10 10:59:19 by atawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

#	define MIN_INT 2147483648
#	define MAX_INT 2147483647

static int	f_isspace(char ch)
{
	return ((ch == '\n') || (ch == ' ') || (ch == '\t')
		|| (ch == '\v') || (ch == '\f') || (ch == '\r'));
}

static int	f_pow(int num, int p)
{
	int			result;

	result = num;
	if (p == 0)
		return (1);
	while (p > 1)
	{
		result = result * num;
		p--;
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	int			is_negate;
	long long	result;
	int			digits;
	const char	*str_cpy;

	str_cpy = str;
	while (f_isspace(*str_cpy))
		str_cpy++;
	is_negate = (*str_cpy == '-');
	result = 0;
	digits = 0;
	str_cpy = str_cpy + is_negate + (*str_cpy == '+');
	while (str_cpy[digits] >= '0' && str_cpy[digits] <= '9')
		digits++;
	while (digits > 0)
	{
		result += ((int)(*str_cpy - '0')) * (f_pow(10, digits - 1));
		str_cpy++;
		digits--;
		if ((is_negate && (result > MIN_INT)) || ((!is_negate)
				&& (result > MAX_INT)) || digits > 10)
			return (ft_ternary_ll(is_negate, 0, -1));
	}
	return (ft_ternary_ll(is_negate, -result, result));
}
