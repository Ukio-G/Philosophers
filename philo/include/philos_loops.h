/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_loops.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atawana <atawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 15:52:30 by atawana           #+#    #+#             */
/*   Updated: 2021/08/15 18:07:16 by atawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_LOOPS_H
# define PHILOS_LOOPS_H

void	start_philos(void);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);
void	*philo_thread(t_philo *philo);
int		is_alive(t_philo *philo);

#endif
