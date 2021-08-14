cmake_minimum_required(VERSION 3.20)
project(Philo C)

file(GLOB UTILS_SRC utils/*.c)
file(GLOB VECTOR_SRC ft_vector/*.c)
file(GLOB PROJECT_SRC srcs/*.c)

include_directories(utils . ft_vector include)

set(CMAKE_C_STANDARD 99)

add_executable(Philo main.c ${UTILS_SRC} ${VECTOR_SRC} ${PROJECT_SRC})

target_link_libraries(Philo PRIVATE pthread)
