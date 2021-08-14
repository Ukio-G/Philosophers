/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ternary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweeper <lweeper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 11:46:56 by lweeper           #+#    #+#             */
/*   Updated: 2021/08/09 11:54:08 by lweeper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_ternary_int(int predict, int true_v, int false_v)
{
	if (predict)
		return (true_v);
	return (false_v);
}

long long	ft_ternary_ll(int predict, long long true_v, long long false_v)
{
	if (predict)
		return (true_v);
	return (false_v);
}

char	ft_ternary_char(int predict, char true_v, char false_v)
{
	if (predict)
		return (true_v);
	return (false_v);
}

char	*ft_ternary_str(int predict, char *true_v, char *false_v)
{
	if (predict)
		return (true_v);
	return (false_v);
}

float	ft_ternary_float(int predict, float true_v, float false_v)
{
	if (predict)
		return (true_v);
	return (false_v);
}
