/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atawana <atawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:01:28 by atawana           #+#    #+#             */
/*   Updated: 2021/08/10 10:59:19 by atawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	str_len;

	if (s == 0)
		return ;
	str_len = (int)ft_strlen(s);
	if (str_len >= 0)
	{
		write(fd, s, str_len);
		write(fd, "\n", 1);
	}
}
