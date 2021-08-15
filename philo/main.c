#include <stdio.h>
#include <pthread.h>
#include <loop_data.h>
#include <philos_loops.h>


int main(int argc, char **argv) {
    init_settings(argc, argv);
    start_philos();

    while (get_settings()->app_active && get_settings()->last_msg_printed == 0)
    {
        usleep(5);
    }
    return (0);
}
