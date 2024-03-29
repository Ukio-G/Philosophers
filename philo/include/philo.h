/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atawana <atawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 18:04:53 by atawana           #+#    #+#             */
/*   Updated: 2021/08/15 18:05:36 by atawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "philo_stats.h"
# include <sys/time.h>
# include <pthread.h>

typedef enum e_fork
{
	FORK_NO_SIDE = -1,
	FORK_LEFT = 0,
	FORK_RIGHT = 1
}	t_fork;

typedef struct s_philo
{
	int				idx;
	t_philo_stats	stats;
	pthread_t		thread;
	int				forks_idx[2];
	int				picked_forks[2];
	long long		last_eat_time;
	int				is_alive;
	int				eaten_times;
}	t_philo;

#endif
