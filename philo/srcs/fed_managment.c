/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fed_managment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atawana <atawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 18:48:16 by atawana           #+#    #+#             */
/*   Updated: 2021/08/15 19:01:46 by atawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "loop_data.h"

void	philo_fed(t_philo *philo)
{
	t_loop_data	*data;

	data = get_settings();
	if (data->settings.eat_limit < 0)
		return ;
	philo->eaten_times++;
	if (philo->eaten_times == data->settings.eat_limit)
	{
		pthread_mutex_lock(&data->fed_mutex);
		data->well_fed_philo++;
		pthread_mutex_unlock(&data->fed_mutex);
	}
}

int	is_all_fed(void)
{
	t_loop_data	*data;

	data = get_settings();
	if (data->settings.eat_limit == -1)
		return (0);
	return (data->settings.philos_count == data->well_fed_philo);
}
