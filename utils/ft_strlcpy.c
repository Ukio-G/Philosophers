/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukio <ukio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 22:50:20 by ukio              #+#    #+#             */
/*   Updated: 2021/08/14 15:17:47 by atawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	cnt;

	cnt = 0;
	if (dst == 0 || src == 0)
		return (0);
	if (size > 0)
	{
		while (src[cnt] != '\0' && (size - 1) > cnt)
		{
			dst[cnt] = src[cnt];
			cnt++;
		}
		dst[cnt] = '\0';
	}
	return ((int)ft_strlen(src));
}
