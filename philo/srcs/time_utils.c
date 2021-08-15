/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atawana <atawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 22:49:24 by atawana           #+#    #+#             */
/*   Updated: 2021/08/15 18:16:04 by atawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <loop_data.h>
#include "utils.h"

long long	get_current_ms(void)
{
	long			time_passed;
	struct timeval	time;

	gettimeofday(&time, NULL);
	time_passed = (time.tv_sec * 1000 + time.tv_usec / 1000);
	return (time_passed);
}

void	set_begin_ms_in_settings(void)
{
	get_settings()->begin = get_current_ms();
}

long long	get_ms_from_begin(void)
{
	return (get_current_ms() - get_settings()->begin);
}
