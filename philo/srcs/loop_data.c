/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atawana <atawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 16:32:40 by atawana           #+#    #+#             */
/*   Updated: 2021/08/15 17:44:23 by atawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include "loop_data.h"
#include "utils.h"
#include "philo.h"

t_loop_data	*get_settings(void)
{
	static t_loop_data	*data;

	if (data == 0)
		data = malloc(sizeof(t_loop_data));
	return (data);
}

int	init_settings(int argc, char **argv)
{
	int	philo_count;

	if (argc > 6 || argc < 5)
	{
		printf("Wrong argument count!\n");
		return (1);
	}
	philo_count = ft_atoi(argv[1]);
	get_settings()->settings.philos_count = philo_count;
	get_settings()->settings.stats.time_to_die = ft_atoi(argv[2]);
	get_settings()->settings.stats.time_to_eat = ft_atoi(argv[3]);
	get_settings()->settings.stats.time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		get_settings()->settings.eat_limit = ft_atoi(argv[5]);
	else
		get_settings()->settings.eat_limit = -1;
	get_settings()->app_active = 1;
	get_settings()->last_msg_printed = 0;
	pthread_mutex_init(&get_settings()->io_mutex, NULL);
	pthread_mutex_init(&get_settings()->app_mutex, NULL);
	alloc_philoforks(philo_count);
	return (0);
}

void	init_philo(t_philo *philo)
{
	t_loop_data	*data;
	int			last_fork_idx;

	data = get_settings();
	philo->stats = get_settings()->settings.stats;
	philo->is_alive = 1;
	philo->eaten_times = 0;
	last_fork_idx = (int)(data->settings.philos_count) - 1;
	if (philo->idx == 0)
	{
		philo->forks_idx[FORK_LEFT] = last_fork_idx;
		philo->forks_idx[FORK_RIGHT] = 0;
	}
	else
	{
		philo->forks_idx[FORK_RIGHT] = philo->idx;
		philo->forks_idx[FORK_LEFT] = philo->idx - 1;
	}
}

void	alloc_philoforks(int philo_count)
{
	int			i;
	t_loop_data	*data;

	i = 0;
	data = get_settings();
	data->philos = malloc(philo_count * sizeof(t_philo));
	data->forks_mtx = malloc(philo_count * sizeof(pthread_mutex_t));
	data->forks = malloc(philo_count * sizeof(t_fork_status));
	memset(data->forks, 0, philo_count);
	while (i < philo_count)
	{
		pthread_mutex_init(data->forks_mtx + i, 0);
		pthread_mutex_unlock(data->forks_mtx + i);
		data->philos[i].idx = i;
		init_philo(data->philos + i);
		i++;
	}
}

void	free_resourses(void)
{
	t_loop_data	*data;
	int			fork_cnt;
	int			i;

	i = 0;
	data = get_settings();
	fork_cnt = data->settings.philos_count;
	while (i < fork_cnt)
	{
		pthread_mutex_destroy(data->forks_mtx + i);
		i++;
	}
	free(data->forks_mtx);
	free(data->forks);
	free(data->philos);
}
