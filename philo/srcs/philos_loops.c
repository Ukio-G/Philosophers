/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_loops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atawana <atawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 18:00:01 by atawana           #+#    #+#             */
/*   Updated: 2021/08/15 19:21:06 by atawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop_data.h"
#include "philos_loops.h"
#include "philo.h"
#include "utils.h"

int	is_alive(t_philo *philo)
{
	long long	die_time;

	die_time = philo->last_eat_time + philo->stats.time_to_die;
	if (get_current_ms() > die_time)
	{
		philo->is_alive = 0;
		get_settings()->app_active = 0;
		thread_safe_died(philo);
		return (0);
	}
	return (1);
}

void	eating(t_philo *philo)
{
	long long	eat_time;

	if (philo->idx % 2 == 0)
	{
		pick_left_fork(philo);
		pick_right_fork(philo);
	}
	else
	{
		pick_right_fork(philo);
		pick_left_fork(philo);
	}
	eat_time = get_current_ms() + philo->stats.time_to_eat;
	philo_fed(philo);
	thread_safe_eating(philo);
	philo->last_eat_time = get_current_ms();
	while (get_current_ms() < eat_time)
		usleep(10);
	put_left_fork(philo);
	usleep(10);
	put_right_fork(philo);
}

void	sleeping(t_philo *philo)
{
	long long	awake_time;

	awake_time = get_current_ms() + philo->stats.time_to_sleep;
	thread_safe_sleeping(philo);
	while (get_current_ms() < awake_time)
	{
		is_alive(philo);
		usleep(10);
	}
}

void	thinking(t_philo *philo)
{
	thread_safe_thinking(philo);
}

void	*philo_thread(void *arg)
{
	t_loop_data	*data;
	t_philo		*philo;

	philo = (t_philo *)arg;
	data = get_settings();
	while (data->start_flag == 0)
		usleep(5);
	philo->last_eat_time = get_current_ms();
	if (!(philo->idx % 2))
		usleep(50);
	while (philo->is_alive && data->app_active)
	{
		if (is_alive(philo) && data->app_active)
			eating(philo);
		if (is_alive(philo) && data->app_active)
			sleeping(philo);
		if (is_alive(philo) && data->app_active)
			thinking(philo);
	}
	return (0);
}
