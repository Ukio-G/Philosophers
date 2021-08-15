/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atawana <atawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 14:54:32 by atawana           #+#    #+#             */
/*   Updated: 2021/08/14 14:54:32 by atawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strdup(const char *str)
{
	size_t  strlen;
	char	*result;

	strlen = ft_strlen(str);
	result = (char *)malloc(strlen + 1);
	ft_strlcpy(result, str, strlen + 1);
	return (result);
}
