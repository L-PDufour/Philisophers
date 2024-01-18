/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 08:08:39 by ldufour           #+#    #+#             */
/*   Updated: 2024/01/18 10:12:20 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <errno.h>
# include <limits.h>
# include <pthread.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}					t_opcode;

typedef enum e_state
{
	DIE,
	EAT,
	SLEEP,
	THINK,
	FORKING,
}					t_state;

typedef struct s_philo
{
	pthread_mutex_t	r_fork;
	pthread_mutex_t	*l_fork;
	pthread_t		threads;
	bool			full;
	bool			dead;
	long			last_meal_time;
	t_state			state;
}					t_philo;

typedef struct s_data
{
	int				nb_of_philo;
	int				nb_of_meals;
	bool			start_thread;
	long			time;
	// TODO: start_time not used
	long			start_time;
	bool			end_time;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	pthread_mutex_t	print;
	t_philo			*philo;
}					t_data;

// Functions
void				parsing_arguments(t_data *philo, int argc, char **argv);
t_data				*thread_init(int argc, char **argv);
// time
long long			timeInMilliseconds(void);
long long			timeInMicroseconds(void);
void				precise_usleep(long usec, t_data *data);

// utils
void				exit_prg_at_error(char *str);
void				*safe_malloc(size_t bytes);
void				print_philo_info(t_data *philo);
void				safe_thread_handle(pthread_t *thread, void *(*foo)(void *),
						void *data, t_opcode opcode);
void				safe_mutex_handle(pthread_mutex_t *mutex, t_opcode opcode);

#endif
