/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atawana <atawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 16:11:14 by atawana           #+#    #+#             */
/*   Updated: 2021/08/15 18:57:07 by atawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop_data.h"
#include "philos_loops.h"
#include "utils.h"

void	pick_fork_idx(t_philo *philo, int fork_idx)
{
	t_loop_data	*data;

	data = get_settings();
	while (data->forks[fork_idx] == TAKEN)
	{
		is_alive(philo);
		usleep(10);
	}
	pthread_mutex_lock(data->forks_mtx + fork_idx);
	data->forks[fork_idx] = TAKEN;
	pthread_mutex_unlock(data->forks_mtx + fork_idx);
}

void	free_fork_idx(int fork_idx)
{
	t_loop_data	*data;

	data = get_settings();
	pthread_mutex_lock(data->forks_mtx + fork_idx);
	data->forks[fork_idx] = FREE;
	pthread_mutex_unlock(data->forks_mtx + fork_idx);
}

void	start_philos(void)
{
	t_loop_data	*data;
	int			i;

	i = 0;
	data = get_settings();
	data->start_flag = 0;
	while (i < data->settings.philos_count)
	{
		pthread_create(&data->philos->thread, NULL, &philo_thread,
			(void *)(data->philos + i));
		i++;
	}
	set_begin_ms_in_settings();
	data->start_flag = 1;
}
