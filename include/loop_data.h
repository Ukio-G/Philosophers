/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_data.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atawana <atawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 16:02:45 by atawana           #+#    #+#             */
/*   Updated: 2021/08/14 16:02:45 by atawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOP_DATA_H
# define LOOP_DATA_H
# include "ft_vector.h"

typedef struct s_loop_data
{
    t_ft_vector forks;
    t_ft_vector philos;
    s_start_settings settings;
} t_loop_data;

#endif