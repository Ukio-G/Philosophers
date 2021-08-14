/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atawana <atawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 14:59:41 by atawana           #+#    #+#             */
/*   Updated: 2021/08/14 14:59:41 by atawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	position;

	position = 0;
	while (position < n)
	{
		*((char *)s + position) = 0;
		position++;
	}
}
