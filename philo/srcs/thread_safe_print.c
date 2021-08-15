/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_safe_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atawana <atawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 16:30:32 by atawana           #+#    #+#             */
/*   Updated: 2021/08/15 12:38:18 by atawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop_data.h"
#include "philo.h"
#include "utils.h"
#include <stdio.h>

void	thread_safe_fork_pick(t_philo *philo, t_fork fork)
{
	t_loop_data	*data;

	data = get_settings();
	pthread_mutex_lock(&data->io_mutex);
	printf("%lld %i has taken fork\n", get_ms_from_begin(), philo->idx + 1);
	pthread_mutex_unlock(&data->io_mutex);
}

void	thread_safe_eating(t_philo *philo)
{
	t_loop_data	*data;
	int			eat_limit;

	data = get_settings();
	eat_limit = data->settings.eat_limit;
	pthread_mutex_lock(&data->io_mutex);
	printf("%lld %i is eating\n", get_ms_from_begin(), philo->idx + 1);
	if (eat_limit < 0)
		pthread_mutex_unlock(&data->io_mutex);
	else
	{
		if (eat_limit > philo->eaten_times)
		{
			pthread_mutex_unlock(&data->io_mutex);
		}
		else
		{
			data->app_active = 0;
		}
	}
}

void	thread_safe_sleeping(t_philo *philo)
{
	t_loop_data	*data;

	data = get_settings();
	pthread_mutex_lock(&data->io_mutex);
	printf("%lld %i is sleeping\n", get_ms_from_begin(), philo->idx + 1);
	pthread_mutex_unlock(&data->io_mutex);
}

void	thread_safe_thinking(t_philo *philo)
{
	t_loop_data	*data;

	data = get_settings();
	pthread_mutex_lock(&data->io_mutex);
	printf("%lld %i is thinking\n", get_ms_from_begin(), philo->idx + 1);
	pthread_mutex_unlock(&data->io_mutex);
}

void	thread_safe_died(t_philo *philo)
{
	t_loop_data	*data;

	data = get_settings();
	pthread_mutex_lock(&data->io_mutex);
	printf("%lld %i died\n", get_ms_from_begin(), philo->idx + 1);
}
