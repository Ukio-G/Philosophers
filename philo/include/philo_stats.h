/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_stats.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atawana <atawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 18:06:00 by atawana           #+#    #+#             */
/*   Updated: 2021/08/15 18:06:15 by atawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STATS_H
# define PHILO_STATS_H

typedef struct s_philo_stats
{
	long long	time_to_die;
	long long	time_to_eat;
	long long	time_to_sleep;
}	t_philo_stats;

#endif
