/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_loops_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atawana <atawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 17:54:04 by atawana           #+#    #+#             */
/*   Updated: 2021/08/15 18:00:41 by atawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "loop_data.h"

void	pick_right_fork(t_philo *philo)
{
	pick_fork_idx(philo, philo->forks_idx[FORK_RIGHT]);
	thread_safe_fork_pick(philo, FORK_RIGHT);
}

void	pick_left_fork(t_philo *philo)
{
	pick_fork_idx(philo, philo->forks_idx[FORK_LEFT]);
	thread_safe_fork_pick(philo, FORK_LEFT);
}

void	put_right_fork(t_philo *philo)
{
	free_fork_idx(philo->forks_idx[FORK_RIGHT]);
}

void	put_left_fork(t_philo *philo)
{
	free_fork_idx(philo->forks_idx[FORK_LEFT]);
}
