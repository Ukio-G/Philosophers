/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atawana <atawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 14:54:32 by atawana           #+#    #+#             */
/*   Updated: 2021/08/14 14:54:32 by atawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	swap(char *a, char *b)
{
	char	tmp_value;

	tmp_value = *a;
	*a = *b;
	*b = tmp_value;
}

static char	*strrev(char *str)
{
	int	len;
	int	cntr;

	len = (int)ft_strlen(str) - 1;
	cntr = 0;
	while (cntr <= len / 2)
	{
		swap(str + cntr, str + len - cntr);
		cntr++;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char		*result;
	char		buffer[13];
	int			is_negate;
	int			i;
	long long	nn;

	nn = n;
	ft_bzero(buffer, 13);
	is_negate = (nn < 0);
	if (is_negate)
		buffer[0] = '-';
	if (is_negate)
		nn *= -1;
	i = is_negate;
	if (nn == 0)
		buffer[i++] = '0';
	while (nn > 0 && ((nn % 10) + '0'))
	{
		buffer[i++] = (nn % 10) + '0';
		nn /= 10;
	}
	result = ft_strdup(buffer);
	if (result)
		strrev(result + is_negate);
	return (result);
}
