/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atawana <atawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 14:59:43 by atawana           #+#    #+#             */
/*   Updated: 2021/08/15 18:15:10 by atawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <unistd.h>
# include "loop_data.h"
# include "philo.h"

int			ft_atoi(const char *str);

char		ft_ternary_char(int predict, char true_v, char false_v);
char		*ft_ternary_str(int predict, char *true_v, char *false_v);
float		ft_ternary_float(int predict, float true_v, float false_v);
long long	ft_ternary_ll(int predict, long long true_v, long long false_v);
int			ft_ternary_int(int predict, int true_v, int false_v);

void		thread_safe_fork_pick(t_philo *philo, t_fork fork);
void		thread_safe_eating(t_philo *philo);
void		thread_safe_sleeping(t_philo *philo);
void		thread_safe_thinking(t_philo *philo);
void		thread_safe_died(t_philo *philo);

void		set_begin_ms_in_settings(void);
long long	get_current_ms(void);
long long	get_ms_from_begin(void);

void		free_resourses(void);
void		pick_right_fork(t_philo *philo);
void		pick_left_fork(t_philo *philo);
void		put_right_fork(t_philo *philo);
void		put_left_fork(t_philo *philo);
void		free_fork_idx(int fork_idx);
void		pick_fork_idx(t_philo *philo, int fork_idx);
int			is_alive(t_philo *philo);
int			is_all_fed(void);
void		philo_fed(t_philo *philo);
#endif
