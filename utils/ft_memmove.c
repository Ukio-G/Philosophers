/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atawana <atawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:36:04 by atawana           #+#    #+#             */
/*   Updated: 2021/08/10 10:59:19 by atawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_memmove(void *dst, const void *source, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !source)
		return (0);
	if (source < dst)
	{
		while (n > 0)
		{
			*((char *)dst + n - 1) = *((char *)source + n - 1);
			n--;
		}
	}
	else
	{
		while (i < n)
		{
			((char *)dst)[i] = ((char *)source)[i];
			i++;
		}
	}
	return (dst);
}
