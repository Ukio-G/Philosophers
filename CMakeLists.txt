cmake_minimum_required(VERSION 3.20)
project(Philo C)

file(GLOB UTILS_SRC philo/utils/*.c)
file(GLOB PROJECT_SRC philo/srcs/*.c)

include_directories(philo/utils philo philo/include)

set(CMAKE_C_STANDARD 99)

add_executable(Philo philo/main.c ${UTILS_SRC} ${PROJECT_SRC})

target_link_libraries(Philo PRIVATE pthread)
