/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atawana <atawana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:33:39 by atawana           #+#    #+#             */
/*   Updated: 2021/08/15 12:33:39 by atawana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop_data.h"
#include "philos_loops.h"
#include "utils.h"
#include <unistd.h>

int main(int argc, char **argv) {
    if (init_settings(argc, argv) != 0)
        return (1);
    if (get_settings()->settings.eat_limit == 0)
        return (0);
    start_philos();
    while (get_settings()->app_active)
        usleep(5);
    free_resourses();
    return (0);
}
