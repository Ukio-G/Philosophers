/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_data.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atawana <atawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 16:02:45 by atawana           #+#    #+#             */
/*   Updated: 2021/08/15 00:21:04 by atawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOP_DATA_H
# define LOOP_DATA_H

# include "start_settings.h"
# include "philo.h"

typedef enum e_fork_status
{
    FREE,
    TAKEN
} t_fork_status;

typedef struct s_loop_data
{
    pthread_mutex_t *forks_mtx;
    t_fork_status *forks;
    t_philo *philos;
    t_start_settings settings;
    pthread_mutex_t io_mutex;
    pthread_mutex_t app_mutex; // after_one_philo_die this mutex will unlock
    int start_flag;
    int app_active;
    long long begin;
    int last_msg_printed;
} t_loop_data;

void alloc_philoforks(int philo_count);
t_loop_data* get_settings();
void init_settings(int argc, char **argv);
#endif