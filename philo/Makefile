all: philo

.PHONY: all
CFLAGS = -Wextra -Wall -Werror
INCLUDE = -I. -Iinclude

# Create list of .obj files, based on .c files
OBJS_DIR = objs
SRC = main.c \
	srcs/args_validator.c \
	srcs/fed_managment.c \
	srcs/forks_managment.c \
	srcs/loop_data.c \
	srcs/philo_actions.c \
	srcs/philos_loops.c \
	srcs/thread_safe_print.c \
	srcs/time_utils.c \
	utils/ft_atoi.c \
	utils/ft_ternary.c

HEADERS = include/loop_data.h \
	include/philo.h \
	include/philo_stats.h \
	include/philos_loops.h \
	include/start_settings.h \
	include/utils.h

$(addprefix $(OBJS_DIR)/,%o): $(addprefix utils/, $(notdir %c)) $(HEADERS)
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(addprefix $(OBJS_DIR)/,%o): $(addprefix srcs/, $(notdir %c)) $(HEADERS)
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(addprefix $(OBJS_DIR)/,%o): %c $(HEADERS)
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

BASIC_OBJS = $(addprefix $(OBJS_DIR)/, $(patsubst %c, %o, $(notdir $(SRC))))

philo: $(BASIC_OBJS)
	gcc $(CFLAGS) -o $@ $^

clean:
	rm -rf objs

fclean: clean
	rm -f philo

re: fclean clean all