/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atawana <atawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 14:54:32 by atawana           #+#    #+#             */
/*   Updated: 2021/08/14 14:54:32 by atawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	ft_strlen(const char *str)
{
	int	result;

	if (!str)
		return (0);
	result = 0;
	while (str[result] != 0)
		result++;
	return (result);
}
