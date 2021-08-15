/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_settings.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atawana <atawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 16:24:05 by atawana           #+#    #+#             */
/*   Updated: 2021/08/14 16:35:22 by atawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef START_SETTINGS_H
# define START_SETTINGS_H

# include "philo_stats.h"

typedef struct s_start_settings
{
	t_philo_stats	stats;
	int				philos_count;
	int				eat_limit;
}	t_start_settings;

#endif
