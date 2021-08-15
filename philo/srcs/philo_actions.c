/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atawana <atawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 16:11:14 by atawana           #+#    #+#             */
/*   Updated: 2021/08/15 11:45:02 by atawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop_data.h"
#include "philos_loops.h"
#include "utils.h"

void start_philos()
{
    t_loop_data *data;
    int i;

    i = 0;
    data = get_settings();
    data->start_flag = 0;
    while (i < data->settings.philos_count)
    {
        pthread_create(&data->philos->thread, NULL, &philo_thread, (void*) (data->philos + i));
        i++;
    }
    set_begin_ms_in_settings();
    data->start_flag = 1;
}
