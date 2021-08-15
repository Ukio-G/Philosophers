/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atawana <atawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 16:00:04 by atawana           #+#    #+#             */
/*   Updated: 2021/08/10 10:59:19 by atawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dst, const void *src, int n)
{
	int		i;
	char	*c_insert_position;
	char	*c_copy_position;
	long	*l_insert_position;
	long	*l_copy_position;

	if (dst == 0 && src == 0)
		return (0);
	l_insert_position = (long *)dst;
	l_copy_position = (long *)src;
	i = n / sizeof(long);
	while (--i >= 0)
		*(l_insert_position++) = *(l_copy_position++);
	i = (n / sizeof(long)) * sizeof(long);
	c_insert_position = (char *)l_insert_position;
	c_copy_position = (char *)l_copy_position;
	while (n >= ++i)
		*c_insert_position++ = *c_copy_position++;
	return (dst);
}
