/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atawana <atawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 19:03:10 by atawana           #+#    #+#             */
/*   Updated: 2021/08/15 19:13:30 by atawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "loop_data.h"
#include <stdio.h>

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	is_onlynum(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	args_validate(int argc, char **argv)
{
	if (argc > 6)
	{
		printf("Error: too mush arguments\n");
		return (0);
	}
	if (argc < 5)
	{
		printf("Error: not enough arguments\n");
		return (0);
	}
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[2]) <= 0
		|| ft_atoi(argv[3]) <= 0 || ft_atoi(argv[4]) <= 0)
	{
		printf("Error: negate or zero arguments\n");
		return (0);
	}
	if (!is_onlynum(argv[1]) || !is_onlynum(argv[2]) || !is_onlynum(argv[3])
		|| !is_onlynum(argv[4]))
	{
		printf("Error: non digital characters in arguments\n");
		return (0);
	}
	return (1);
}
