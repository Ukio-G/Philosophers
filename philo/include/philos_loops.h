/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_loops.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atawana <atawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 15:52:30 by atawana           #+#    #+#             */
/*   Updated: 2021/08/14 22:05:24 by atawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_LOOPS_H
# define PHILOS_LOOPS_H


void start_philos();
void eating();
void sleeping();
void thinking();
void* philo_thread();

void philo_die();
void philo_pick_fork();
int philo_is_alive();

#endif
