#include "loop_data.h"
#include "philos_loops.h"
#include "philo.h"
#include "utils.h"

int is_alive(t_philo * philo)
{
    long long die_time;

    die_time = philo->last_eat_time + philo->stats.time_to_die;
    if (get_current_ms() >= die_time)
    {
        philo->is_alive = 0;
        get_settings()->app_active = 0;
        thread_safe_died(philo);
        return (0);
    }
    return (1);
}

void pick_fork_idx(t_philo *philo, int fork_idx)
{
    t_loop_data *data;

    data = get_settings();

    while (data->forks[fork_idx] == TAKEN)
    {
        is_alive(philo);
        usleep(10);
    }
    pthread_mutex_lock(data->forks_mtx + fork_idx);
    data->forks[fork_idx] = TAKEN;
}

void free_fork_idx(int fork_idx)
{
    t_loop_data *data;

    data = get_settings();

    data->forks[fork_idx] = FREE;
    pthread_mutex_unlock(data->forks_mtx + fork_idx);
}

void pick_right_fork(t_philo *philo)
{
    pick_fork_idx(philo, philo->forks_idx[FORK_RIGHT]);
    thread_safe_fork_pick(philo, FORK_RIGHT);
}

void pick_left_fork(t_philo *philo)
{
    pick_fork_idx(philo, philo->forks_idx[FORK_LEFT]);
    thread_safe_fork_pick(philo, FORK_LEFT);
}

void put_right_fork(t_philo *philo)
{
    free_fork_idx(philo->forks_idx[FORK_RIGHT]);
}

void put_left_fork(t_philo *philo)
{
    free_fork_idx(philo->forks_idx[FORK_LEFT]);
}

void eating(t_philo *philo)
{
    long long eat_time;
    if (philo->idx % 2 == 0)
    {
        pick_left_fork(philo);
        pick_right_fork(philo);
    }
    else
    {
        pick_right_fork(philo);
        pick_left_fork(philo);
    }
    eat_time = get_current_ms() + philo->stats.time_to_eat;
    philo->eaten_times++;
    thread_safe_eating(philo);
    philo->last_eat_time = get_current_ms();
    while (get_current_ms() < eat_time)
    {
        usleep(10);
    }
    if (philo->idx % 2 != 0)
    {
        put_left_fork(philo);
        put_right_fork(philo);
    }
    else
    {
        put_right_fork(philo);
        put_left_fork(philo);
    }
}

void sleeping(t_philo *philo)
{
    long long awake_time;

    awake_time = get_current_ms() + philo->stats.time_to_sleep;
    thread_safe_sleeping(philo);

    while (get_current_ms() < awake_time)
    {
        is_alive(philo);
        usleep(10);
    }
}

void thinking(t_philo *philo)
{
    thread_safe_thinking(philo);
}

void *philo_thread(t_philo *philo)
{
    t_loop_data *data;

    data = get_settings();
    while (data->start_flag == 0)
        usleep(5);

    philo->last_eat_time = get_current_ms();
    if ((philo->idx % 2))
        usleep(500);
    while (philo->is_alive && data->app_active)
    {
        if (is_alive(philo) && data->app_active)
            eating(philo);
        if (is_alive(philo) && data->app_active)
            sleeping(philo);
        if (is_alive(philo) && data->app_active)
            thinking(philo);
    }
    return (0);
}
