/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atawana <atawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 22:49:24 by atawana           #+#    #+#             */
/*   Updated: 2021/08/15 00:07:14 by atawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <loop_data.h>
#include "utils.h"

long long get_current_ms()
{
    long time_passed;
    struct  timeval time;

    gettimeofday(&time, NULL);
    time_passed = (time.tv_sec * 1000 + time.tv_usec / 1000);
    return (time_passed);
}

void set_begin_ms_in_settings()
{
    get_settings()->begin = get_current_ms();
}

long long time_diff_from_ms(long long start_moment)
{
    return (get_current_ms() - start_moment);
}

long long get_ms_from_begin()
{
    return (get_current_ms() - get_settings()->begin);
}

long long get_current_us()
{
    long time_passed;
    struct  timeval time;

    gettimeofday(&time, NULL);
    time_passed = time.tv_sec * 1000000 + time.tv_usec;
    return (time_passed);
}

void ms_sleep(long long sleep_ms)
{
    long long awake_time;
    long long sleep_us;

    sleep_us = sleep_ms * 1000;
    awake_time = get_current_us() + sleep_us;
    while (get_current_us() < awake_time)
    {
        usleep(10);
    }
}

